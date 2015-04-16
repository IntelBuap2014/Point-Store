#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h> //per us de atoi
#include <string.h>

int main()
{
int server_sockfd, client_sockfd;
int server_len, client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;

/* Remove any old socket and create an unnamed socket for the server. */

server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/* Name the socket. */

server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = htonl(INADDR_ANY);
server_address.sin_port = htons(9734);
server_len = sizeof(server_address);
bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/* Create a connection queue and wait for clients. */
//aleatorio = 7;

listen(server_sockfd, 5); //Punto A
while(1)
{
char mensaje[1024];
char respuesta[1024] = "Recibi mensaje: ";

printf("Servidor esperando peticiones...\n");
/* Aceptamos una conexion */

client_len = sizeof(client_address);
client_sockfd = accept(server_sockfd,(struct sockaddr *)&client_address, &client_len);

/* We can now read/write to client on client_sockfd. */

read(client_sockfd, mensaje, 1024);
printf("mensaje recibido de cliente: %s\n", mensaje);
//Código comparación
strcat(respuesta, mensaje);
//printf("Respuesta servidor: %c\n",respuesta);
write(client_sockfd, respuesta, 1024);

//Cerramos el Socket
close(client_sockfd);
}
exit(0);
}