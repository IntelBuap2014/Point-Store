
Int3 = int3.c
LOGIN = interfaz_login.c
BUSQUEDA = interfaz_search.c
INTERFAZ_2 = Interfaz_2.c
INTERFAZX = interfazX.c
CFLAGS = `pkg-config --libs --cflags gtk+-2.0`
CFLAGS2 = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc
DIRBIN = ../bin
.PHONY: all limpiar int3

all:  int3 login busquedas interfaz_2 interfazx

int3: ${Int3}
	${CC} -o ${DIRBIN}/int3 ${Int3} ${CFLAGS}

login: ${LOGIN}
	${CC} -o ${DIRBIN}/I_login ${LOGIN} ${CFLAGS}

busquedas:${BUSQUEDA}
	${CC} -o ${DIRBIN}/I_busqueda ${BUSQUEDA} ${CFLAGS}

interfaz_2: ${INTERFAZ_2}
	${CC} -o ${DIRBIN}/Interfaz_2 ${INTERFAZ_2} ${CFLAGS2}

interfazx: ${INTERFAZX}
	${CC} -o ${DIRBIN}/interfazX ${INTERFAZX} ${CFLAGS}

limpiar:
	rm -f ${DIRBIN}/*
