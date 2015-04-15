#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"


int main( )
{  
   ptrUsuario u = construct(12,"Nua", "pass");		
   
   printf( "Usuario id : %d\n",getId(u));
   printf( "Usuario Nombre : %s\n",getNombre(u));
   printf( "Usuario Password : %s\n",getPassword(u));

   return 0;
}

