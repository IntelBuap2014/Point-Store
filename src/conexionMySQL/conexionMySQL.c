/* librerías que usaremos */
#include <mysql.h> /* libreria que nos permite hacer el uso de las conexiones y consultas con MySQL */
#include <stdio.h>

int main()
{
    MYSQL *conexion; /* variable de conexión para MySQL */
    MYSQL_RES *res; /* variable que contendra el resultado de la consuta */
    MYSQL_ROW row; /* variable que contendra los campos por cada registro consultado */
    char *server = "localhost"; /*direccion del servidor 127.0.0.1, localhost*/
    char *user = "root"; /*usuario permitido acceder a la base de datos */
    char *password = ""; /* contraseña para el usuario */
    char *database = "prueba"; /*nombre de la base de datos a consultar */
    conexion = mysql_init(NULL); /*inicializacion a nula la conexión */

    /* conectar a la base de datos */
    if (!mysql_real_connect(conexion, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conexion));
        exit(1);
    }

    /* enviar consulta SQL */
    if (mysql_query(conexion, "select * from datos"))
    {
        fprintf(stderr, "%s\n", mysql_error(conexion));
        exit(1);
    }

    res = mysql_use_result(conexion);
    printf("ID\tNombre\t\tedad\n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s\t%s\t%s \n", row[0],row[1],row[2]);

    /* se libera la variable res y se cierra la conexión */
    mysql_free_result(res);
    mysql_close(conexion);
    exit(0);
}