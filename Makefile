
Int3 = source/int3.c
LOGIN = source/interfaz_login.c
BUSQUEDA = source/interfaz_search.c
INTERFAZ_2 = source/Interfaz_2.c
INTERFAZX = source/interfazX.c
CFLAGS = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc
DIRBIN = source

.PHONY: all limpiar int3

all:  int3 login busquedas interfaz_2 interfazx

int3: ${Int3}
	${CC} -o int3 ${Int3} ${CFLAGS}

login: ${LOGIN}
	${CC} -o I_login ${LOGIN} ${CFLAGS}

busquedas:${BUSQUEDA}
	${CC} -o I_busqueda ${BUSQUEDA} ${CFLAGS}

interfaz_2: ${INTERFAZ_2}
	${CC} -o Interfaz_2 ${INTERFAZ_2} ${CFLAGS}

interfazx: ${INTERFAZX}
	${CC} -o interfazX ${INTERFAZX} ${CFLAGS}

limpiar:

