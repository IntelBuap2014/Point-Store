
Int3 = source/int3.c
LOGIN = source/interfaz_login.c
BUSQUEDA = source/interfaz_search.c
INTERFAZ_2 = source/Interfaz_2.c
INTERFAZX = source/interfazX.c
CFLAGS = `pkg-config --libs --cflags gtk+-3.0`
CC = gcc

.PHONY: all limpiar int3

all:  int3 login busquedas interfaz_2 interfazx gen-archivos-mo

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


gen-template-pot:
	xgettext --package-name Point-Store --package-version 0.1 --default-domain Point-Store \
	--output po/Point-Store.pot --from-code=utf-8 --copyright-holder="Yenisei" \
	--msgid-bugs-address="yeniseirape@gmail.com" -s -k_ -L C source/int3.c \
	source/Interfaz_2.c source/interfaz_login.c source/interfaz_search.c source/interfazX.c

actualizar-archivos-po: gen-template-pot
	msgmerge -s -U po/en.po po/Point-Store.pot

gen-archivos-mo:
	msgfmt -c -v -o idioma/en/LC_MESSAGES/Point-Store.mo po/en.po


limpiar:
	rm I_busqueda I_login int3 Interfaz_2 interfazX
