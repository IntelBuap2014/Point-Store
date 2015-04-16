CLN_FUENT = cliente.c
SRV_FUENT = servidor.c

all: Servidor Cliente

Servidor:
	${CC} ${CLN_FUENT} -o cliente

Cliente:
	${CC} ${SRV_FUENT} -o servidor

limpiar:
	rm -f cliente servidor