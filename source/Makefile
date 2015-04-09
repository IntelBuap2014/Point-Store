<<<<<<< HEAD
Int3 = int3.c
LOGIN = interfaz_login.c
BUSQUEDA = interfaz_busqueda.c
CFLAGS = `pkg-config --libs --cflags gtk+-2.0`
CC = gcc
=======
OBJETOS = int3.o
CFLAGS = `pkg-config --libs --cflags gtk+-3.0`
>>>>>>> refs/remotes/origin/master

.PHONY: all limpiar

all:  int3 login busquedas

int3: ${Int3}
	${CC} -o int3 ${int3} ${CFLAGS}

login: ${LOGIN}
	${CC} -o I_login ${LOGIN} ${CFLAGS}

busquedas:${BUSQUEDA}
	${CC} -o I_busqueda ${BUSQUEDA} ${CFLAGS}

limpiar: ${OBJETOS}
	rm -f int3 ${OBJETOS}
