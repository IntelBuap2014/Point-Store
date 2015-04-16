FUENTE = conexionMySQL.c
CFLAGS = `mysql_config --cflags` `mysql_config --libs`

ConexionMySQL: ${FUENTE}
	${CC} -o conexionMySQL  ${FUENTE} ${CFLAGS}

limpiar:
	rm -f conexionMySQL