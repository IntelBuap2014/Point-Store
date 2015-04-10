#include <stdio.h>
#include <string.h>
 
typedef struct Usuario
{
   char  nombre[45];
   char  password[20];
   int   usuario_id;
} Usuario ;

void  construct(Usuario *const  u, int usuario_id, char nombre[], char password [] )
{
 	 u->usuario_id=usuario_id;
 	 strcpy(u->nombre, nombre);
 	 strcpy( u->password,password);	
}
int getId (Usuario *const u){
	return u->usuario_id;
}
void  setId(Usuario * const u, int usuario_id ){
	u->usuario_id=usuario_id;
}
char [] getNombre(Usuario *const u ){
      	return u->nombre;
}
void setNombre( Usuario *const u, char nombre[] )
{
	strcpy(u->nombre, nombre);
}

char [] getPassword(Usuario *const u ){
      	return u->password;
}
void setPassword( Usuario *const u, char passw[] )
{
 	strcpy(u->password, passw);
}















