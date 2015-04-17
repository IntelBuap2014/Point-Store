#include <my_global.h>
#include <mysql.h>
#include "usuario.h"
#include <string.h>
const int MAX_BUF=1000;
char* cad;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}
/*Funcion para verificar el login de un usuario*/
int login(MYSQL *con, ptrUsuario u){
cad=malloc(MAX_BUF);
sprintf(cad,"SELECT nombre,password from Usuario where nombre='%s'",getNombre(u));
printf(cad);
if (mysql_query(con, cad )) 
  {
     finish_with_error(con);
  }
  
  MYSQL_RES *result = mysql_store_result(con);
if (result == NULL) 
  {
     finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);
  MYSQL_ROW row;
   
  while ((row = mysql_fetch_row(result))) 
  { 
      int i;
	for(i = 0; i < num_fields; i++) 
      { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
          printf("\n"); 
  }
 mysql_free_result(result);
}

/*Funcion para agregar un usuario a la base de datos*/
int addNew(MYSQL *con, ptrUsuario  u){
	cad=malloc(MAX_BUF);
 	sprintf(cad,"INSERT INTO Usuario VALUES('%d','%s','%s','%s') ",getId(u),getNombre(u),getNombre(u),getNombre(u));

//FALTA verificar si ese usuario ya existe
if (mysql_query(con, cad))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
}
int openConexion (MYSQL *con )
{
 if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }
//Conexion a la base de datos 
if (mysql_real_connect(con, "localhost", "root", "123",
           "mydb", 0, NULL, 0) == NULL)
            {
                  fprintf(stderr, "%s\n", mysql_error(con));
                         mysql_close(con);
                               exit(1);
                                 }

}

int closeConexion(MYSQL *con){
    mysql_close(con);
    exit(1);

}
int main(int argc, char **argv)
{  
  MYSQL *con = mysql_init(NULL);
  openConexion(con);
  ptrUsuario  u = constructZ("Nua", "pass");
 // addNew(con,u);
  login(con, u);
  closeConexion(con);
  exit(0);

}


