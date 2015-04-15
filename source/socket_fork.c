//Servidor concurrente para atender mas de una conexion

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

//Funcion para procesar al nuevo cliente conectado
void procesar (int sock)
{
	int n;
	char buffer[256];
	bzero(buffer,256);
	//Se lee del nuevo socket, se verifica si hay error
	n = read(sock,buffer,255);
	if (n < 0)
	{
		perror("Error al leer del socket\n");
		exit(1);
	}
	//Se imprime el mensaje que envio el socket
	printf("Mensaje del socket: %s\n",buffer);
	//Se devuelve una cadena como respuesta al socket y se verifica si hay error
	n = write(sock,"Respuesta a socket",18);
	if (n < 0)
	{
		perror("Error al escribir en el socket\n");
		exit(1);
	}
}

int main()
{
	struct sockaddr_in sockaddr, clientaddr;	//Estructuras para almacenar la info del socket
	int s;						//Socket principal
	int ns;						//Socket que se crea despues del accept()
	int pid;					//Idetificador de procesos fork()
	int len;					//Longitud de estrucutras
	int portno = 51717;				//Puerto de comunicacion
	//Se abre el socket y se verifican errores
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("Error al crear socket\n");
	//Inicializar estructura del socket
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(portno);
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	//Definimos la longitud de la estructura
	len=sizeof(sockaddr);
	//Se liga al socket usando bind y se verifican errores
	if (bind(s, (struct sockaddr *)&sockaddr, len) < 0)
		perror("Error en el bind\n");
	//Señal para ignorar la terminacion de cada hijo
	signal(SIGCHLD, SIG_IGN);
	//Se coloca al socket en modo pasivo a la espera de conexiones y se verifican errores
	if (listen(s,10) < 0)
		perror("Eror en el listen\n");
	//Ciclo infinito para aceptar conexiones
	printf("Socket disponible\n");
	while(1)
	{
		//Longitud de ls estructura		
		len=sizeof(sockaddr);
		//Se espera por conexiones, se bloquea hasta que ocurre alguna
		if ((ns = accept(s,(struct sockaddr *)&sockaddr,&len)) < 0)
			perror("Error en el accept\n");
		//Se crea un proceso hijo por cada conexion entrante
		//Se verifica por algun error en fork()
		printf("Conexion establecida\n");
		if((pid = fork()) < 0)
		{ 
			perror("Error en fork\n");
			exit(1);
		}
		//El proceso hijo atiende la nuevo conexion
		if(pid == 0)
		{
			printf("Atendiendo conexion\n");
			//Se llama a la funcion que procesara los datos
			procesar(ns);
			exit(0);
		}
		//Proceso padre cierra el nuevo socket y queda en espera de mas conexiones
		else
			close(ns);
	}
	return(0);
}
