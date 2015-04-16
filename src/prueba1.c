#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{  
  MYSQL *con = mysql_init(NULL);

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

  if (mysql_query(con, "INSERT INTO Usuario VALUES (1,'Beo','Norml','paw')")) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      


      mysql_close(con);
      exit(1);
  }


  mysql_close(con);
  exit(0);
}
