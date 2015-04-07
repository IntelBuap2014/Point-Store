OBJETOS = int3.o
FUENTES = int3.c
CFLAGS = `pkg-config --libs --cflags gtk+-2.0`

all:  compilar

compilar: ${OBJETOS}
	${CC} -o int3 ${OBJETOS} `pkg-config --libs --cflags gtk+-2.0`

