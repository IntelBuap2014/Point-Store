//Servidor concurrente para atender mas de una conexion usando select()

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

//Funcion para procesar al nuevo cliente conectado
void procesar (int sock, int *numero)
{
	int n;
	char buffer[256];
	bzero(buffer,256);
	//Se lee del nuevo socket, se verifica si hay error
	n = read(sock,buffer,255);
	if (n < 0)
	{
		perror("Error al leer del socket");
		(*numero)--;
		exit(1);
	}
	//Se imprime el mensaje que envio el socket
	printf("Mensaje del socket: %s\n",buffer);
	//Se devuelve una cadena como respuesta al socket y se verifica si hay error
	n = write(sock,"Respuesta a socket",18);
	if (n < 0)
	{
		perror("Error al escribir en el socket");
		exit(1);
	}
}



//Busca en array todas las posiciones con -1 y las elimina
void limpia (int *tabla, int *n)
{
	int i,j;

	if ((tabla == NULL) || ((*n) == 0))
		return;

	j=0;
	for (i=0; i<(*n); i++)
	{
		if (tabla[i] != -1)
		{
			tabla[j] = tabla[i];
			j++;
		}
	}
	
	*n = j;
}

//Función que devuelve el valor máximo del descriptor en la tabla
int maximoDescriptor (int *tabla, int n)
{
	int i;
	int max;

	if ((tabla == NULL) || (n<1))
		return 0;
		
	max = tabla[0];
	for (i=0; i<n; i++)
		if (tabla[i] > max)
			max = tabla[i];

	return max;
}

int main(int argc, char *argv[])
{
	struct sockaddr_in sockaddr, clientaddr;	//Estructuras para almacenar la info del socket
	int s;						//Socket principal
	int ns;						//Socket que se crea despues del accept()
	int len;					//Longitud de estrucutras
	int portno = 5001;				//Puerto de comunicacion
	int i;
	int socketCliente[10];				//Arreglo de descriptores
	int numeroClientes = 0;				//Numero de clientes conectados
	int maximo;					//Valor del descriptor maximo
	fd_set descriptoresLectura;			//Estructura necesaria para verificar los descriptores
	//Se abre el socket y se verifican errores
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("Error al crear socket");
	//Inicializar estructura del socket
	memset(&sockaddr,'0',sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(portno);
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	//Definimos la longitud de la estructura
	len=sizeof(sockaddr);
	//Se liga al socket usando bind y se verifican errores
	if (bind(s, (struct sockaddr *)&sockaddr, len) < 0)
		perror("Error en el bind");
	//Señal para ignorar la terminacion de cada hijo
	signal(SIGCHLD, SIG_IGN);
	//Se coloca al socket en modo pasivo a la espera de conexiones y se verifican errores
	if (listen(s,10) < 0)
		perror("Eror en el listen");

	//Ciclo infinito para aceptar conexiones
	while(1)
	{
		limpia(socketCliente, &numeroClientes);
		FD_ZERO (&descriptoresLectura);
	    	FD_SET (s, &descriptoresLectura);
		for (i=0; i<numeroClientes; i++)
			FD_SET (socketCliente[i], &descriptoresLectura);
		maximo = maximoDescriptor(socketCliente, numeroClientes);
		if (maximo < s)
			maximo = s;		
		if (select (maximo + 1, &descriptoresLectura, NULL, NULL, NULL) < 0)
		{
			perror("Error en select");
			exit(1);
		}
		for (i=0; i<numeroClientes; i++)
		{
			if (FD_ISSET (socketCliente[i], &descriptoresLectura))
			{
				//Se procesa los que el cliente manda
				procesar(socketCliente[i],&numeroClientes);
			}
		}

		//Se comprueba si algún cliente nuevo desea conectarse y se le admite
		if (FD_ISSET (s, &descriptoresLectura))
		{	
			if ((socketCliente[numeroClientes] = accept(s,(struct sockaddr *)&clientaddr,&len)) < 0)
				perror("Error en el accept");
			numeroClientes++;
			if ((numeroClientes) >= 10)
			{
				close (socketCliente[numeroClientes -1]);
				numeroClientes--;
			}
			printf("Cliente nuevo aceptado");
		}
	}
	return(0);
}
