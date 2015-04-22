#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
#include "otra_interfaz.h"

#define _(String) gettext(String)
void
runMain(GtkWidget *widget, MyApp *app)
{


 GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *box1;
  GtkWidget *box2;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;
  GtkWidget *button4;
  GtkWidget *button;

  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "PointStore");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  
  frame = gtk_frame_new(_("Principal"));
  box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  
  gtk_container_add(GTK_CONTAINER(window), frame);
  gtk_container_add(GTK_CONTAINER(frame),box1);
  gtk_container_add (GTK_CONTAINER (window), button);

  
  box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  button1 = gtk_button_new_with_label(_("Inventario"));
  button2 = gtk_button_new_with_label(_("Facturas"));
  button3 = gtk_button_new_with_label(_("Clientes"));
  button4 = gtk_button_new_with_label(_("Ventas"));
  button = gtk_button_new_with_label(_("Login"));

  
  gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(box2), button1, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box2), button2, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box2), button3, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box2), button4, FALSE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box2), button, FALSE, TRUE, 10);
  	
  gtk_box_set_homogeneous(GTK_BOX(box2), TRUE);
  gtk_widget_show_all(window);

  /* ONCLICK */

  g_signal_connect (G_OBJECT (window), "destroy",
                          G_CALLBACK (on_window_destroy), app);

  g_signal_connect (G_OBJECT (button), "clicked",
                          G_CALLBACK (otraInterfaz), app);

 g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);


  
 
}
