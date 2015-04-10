#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"


int main( )
{  
   Usuario  u;
        construct(&u ,12,"Nua", "pass");
        printf("Usuario %d,  %s , %s ", u.usuario_id, u.nombre, u.password);
   return 0;
}

