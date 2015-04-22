#include <libintl.h>
#include <locale.h>
#include "Ventana.h"
#include "interf_principal.h"
#define _(String) gettext(String)
int main(int argc, char *argv[]){

  bind_textdomain_codeset("Point-Store", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("Point-Store", "idioma");
  textdomain("Point-Store");
  MyApp *app;
      
        gtk_init (&argc, &argv);
        app = g_slice_new (MyApp);
        app->windows = NULL;
        
        runMain(NULL, app);
        gtk_main ();
        g_slice_free (MyApp, app);        
  return 0;

}


