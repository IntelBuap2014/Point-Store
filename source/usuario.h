#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct Usuario
{
   char  nombre[45];
   char  password[20];
   int   usuario_id;
} Usuario ;

typedef Usuario *ptrUsuario;

ptrUsuario  construct(int usuario_id, char nombre[], char password [] )
{
	 ptrUsuario u = (struct Usuario *) malloc (sizeof(struct Usuario));
 	 
	 u->usuario_id=usuario_id;
 	 strcpy(u->nombre, nombre);
 	 strcpy( u->password,password);	

     	 return u;
}

int getId (ptrUsuario u){
	return u->usuario_id;
}

void  setId(ptrUsuario u, int usuario_id ){
	u->usuario_id=usuario_id;
}

char* getNombre(Usuario *const u ){
      	return u->nombre;
}

void setNombre( ptrUsuario u, char nombre[] )
{
	strcpy(u->nombre, nombre);
}

char* getPassword(ptrUsuario u ){
      	return u->password;
}

void setPassword( ptrUsuario u, char passw[] )
{
 	strcpy(u->password, passw);
}





