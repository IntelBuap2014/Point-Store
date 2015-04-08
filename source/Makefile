OBJETOS = int3.o
CFLAGS = `pkg-config --libs --cflags gtk+-3.0`

all:  compilar

compilar: ${OBJETOS}
	${CC} -o int3 ${OBJETOS} ${CFLAGS}

limpiar: ${OBJETOS}
	rm -f int3 ${OBJETOS}
