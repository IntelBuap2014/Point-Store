OBJETOS_C = Socket.o Socket_Cliente.o
OBJETOS_S = Socket.o Socket_Servidor.o
SERVIDOR_F = Servidor.c
CLIENTE_F = Cliente.c
CFLAGS = -I.
CC = gcc

all : Servidor Cliente

Servidor : ${OBJETOS_S} ${SERVIDOR_F}
	${CC} ${CFLAGS} ${OBJETOS_S} ${SERVIDOR_F} -o  servidor

Cliente : ${OBJETOS_C} ${CLIENTE_F}
	${CC} ${CFLAGS} ${OBJETOS_C} ${CLIENTE_F} -o  cliente

clean :
	rm *.o cliente servidor
