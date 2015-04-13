#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
#define _(cadena) gettext (cadena)
//Funcion que recibe los datos del login*
void imprime( GtkWidget *widget, gpointer   data )
{
	g_print ("Se buscan los datos en la base segun el criterio\n");
}
//Funcion main
int main( int   argc, char *argv[] )
{


	bind_textodomain_codeset("Point-Store","UTF-8");
	setlocale(LC_ALL, "");
	bindtextdomain("Point-Store", "idioma");
	textdomain("Point-Store");
        //Definicion de los elementos de la interfaz (Todas las clases se heredan de GtkWidget)
        static GtkWidget* window = NULL;        //Ventana principal
        GtkWidget *frame_search;                //Frame con titulo (Login)
        GtkWidget *caja_vertical;               //Contenedor para alinear los elemento verticalmente
        GtkWidget *caja_usuario;                //Contenedor para alinear los elementos del usuario horizontalmente
        GtkWidget *caja_code;                   //Contenedor para alinear los elementos del codeord horizontalmente
        GtkWidget *caja_boton;                  //Contenedor para alinear el boton horizontalmente
        GtkWidget *boton;                       //Boton 
        GtkWidget* usuario;                     //Etiqueta de usuario
        GtkWidget* entrada_usuario;             //Campo del usuario
        GtkWidget* code;                       //Etiqueta de codeord
        GtkWidget* entrada_code;               //Campo de codeord
        gtk_init (&argc, &argv);
        //Se inicializa la ventana principal
        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS);
        gtk_window_set_title (GTK_WINDOW (window), "PointStore");
        //Señal para terminar el proceso
        g_signal_connect (G_OBJECT (window), "destroy",
                                G_CALLBACK (gtk_main_quit),
                                NULL);
        gtk_container_set_border_width (GTK_CONTAINER (window), 10);
        //Se inicializa el frame con el titulo correspondiente
        frame_search = gtk_frame_new ("Buscar");
        //Se agrega el frame a la ventana principal
        gtk_container_add (GTK_CONTAINER (window), frame_search);
        //Se incializa el contenedor vertical
        caja_vertical = gtk_vbox_new (FALSE, 0);
        gtk_container_set_border_width (GTK_CONTAINER (caja_vertical), 10);
        //Se agrega el contenedor al frame
        gtk_container_add (GTK_CONTAINER (frame_search), caja_vertical);
        //Se inicializa el contenedor del usuario
        caja_usuario = gtk_hbutton_box_new ();
        gtk_container_set_border_width (GTK_CONTAINER (caja_usuario), 5);
        // Apariencia de la Caja
        gtk_button_box_set_layout (GTK_BUTTON_BOX (caja_usuario), GTK_BUTTONBOX_SPREAD);
        gtk_box_set_spacing (GTK_BOX (caja_usuario), 40);
        //Se inicializa la etiquete de usuario
        usuario=gtk_label_new("Buscar por Codigo");
        //Se agrega la etiqueta en el contenedor de usuario
        gtk_container_add (GTK_CONTAINER (caja_usuario), usuario);
        //Se inicializa el campo de usuario
        entrada_usuario=gtk_entry_new ();
        //Se agrega el campo al contenedor de usuario
        gtk_container_add (GTK_CONTAINER (caja_usuario), entrada_usuario);
        //Se agrega el contenedor de usuario al contenedor vertical
        gtk_box_pack_start (GTK_BOX (caja_vertical),caja_usuario,TRUE, TRUE, 20);
        //Se inicializa el contenedor de codeord
        caja_code = gtk_hbutton_box_new ();
        gtk_container_set_border_width (GTK_CONTAINER (caja_code), 5);
        // Apariencia de la Caja
        gtk_button_box_set_layout (GTK_BUTTON_BOX (caja_code), GTK_BUTTONBOX_SPREAD);
        gtk_box_set_spacing (GTK_BOX (caja_code), 40);
//Se inicializa la etiqueta de codeord
        code=gtk_label_new("Bucar por Nombre");
        //Se agrega la etiqueta al contenedor de codeord
        gtk_container_add (GTK_CONTAINER (caja_code),code);
        //Se inicializa el campo de codeord
        entrada_code=gtk_entry_new ();
        //Se configura para no mostrar los caracteres que se ingresen
        gtk_entry_set_visibility (GTK_ENTRY(entrada_code), TRUE);
        //Se agrega el campo de codeord al contenedor
        gtk_container_add (GTK_CONTAINER (caja_code), entrada_code);
        //Se agrega el contenedor de codeord al contenedor vertical
        gtk_box_pack_start (GTK_BOX (caja_vertical),caja_code,TRUE, TRUE, 20);
        //Se inicializa el contenedor de boton
        caja_boton = gtk_hbutton_box_new ();
        gtk_container_set_border_width (GTK_CONTAINER (caja_boton), 5);
        gtk_button_box_set_layout (GTK_BUTTON_BOX (caja_boton), GTK_BUTTONBOX_SPREAD);
        gtk_box_set_spacing (GTK_BOX (caja_boton), 40);
        //Se inicializa el boton
        boton = gtk_button_new ();
	GtkWidget  *image1= gtk_image_new_from_file("search.png");
	gtk_button_set_image (GTK_BUTTON(boton),image1);
        //Se asocia el evento "cliked" con el boton y se llama a la funcion imprime
        g_signal_connect_swapped (G_OBJECT (boton), "clicked",
                                G_CALLBACK (imprime), NULL);
        //Se agrega el boton al contenedor
        gtk_container_add (GTK_CONTAINER (caja_boton), boton);
        //Se agrega el contenedor de boton al contenedor vertical
        gtk_box_pack_start (GTK_BOX (caja_vertical),caja_boton,TRUE, TRUE, 20);
        //Se muestran todos los objetos
        gtk_widget_show_all (window);
        gtk_main ();
        return 0;
}






