/* Make the necessary includes and set up the variables. */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
int sockfd;
int len;
struct sockaddr_in address;
int result;
char mensaje[1024];
char respuesta[1024]; //Inicializamos a 1 para que entre en el while

while(respuesta != "exit")
{

printf("Escribe mensaje a enviar a servidor ");
fflush(stdin);
scanf("%s",mensaje); //Para capturar caracteres utiliza "%s"
/* creamos socket para el cliente. */

sockfd = socket(AF_INET, SOCK_STREAM, 0);

address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr("43.255.190.165");
address.sin_port = htons(9734);
len = sizeof(address);

/* Conectamos socket al servidos */

result = connect(sockfd, (struct sockaddr *)&address, len);

if(result == -1) {
perror("oops: client3");
exit(1);
}

write(sockfd, mensaje, 1024);
//printf("El cliente envia: %c\n",numero);
read(sockfd, respuesta, 1024);
printf("Respuesta de Servidor: %s\n", respuesta );
close(sockfd);
}

printf("terminado: %s !!!\n", mensaje);
exit(0);
}