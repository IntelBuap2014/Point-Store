#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>
#define _(String) gettext(String)

int main(int argc, char *argv[]){
  bind_textdomain_codeset("Point-Store", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("Point-Store", "idioma");
  textdomain("Point-Store");
  GtkWidget *window;
  GtkWidget *frame;
  GtkWidget *box1;
  GtkWidget *box2;
  GtkWidget *label1;
  GtkWidget *entry1;
  GtkWidget *box3;
  GtkWidget *label2;
  GtkWidget *entry2;
  GtkWidget *box5;
  GtkWidget *box4;
  GtkWidget *button1;
  GtkWidget *box6;
  
  gtk_init(&argc, &argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "PointStore");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  
  frame = gtk_frame_new(_("Verificar Existencia"));
  gtk_container_add(GTK_CONTAINER(window), frame);
  
  box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(frame),box1);
  
  box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label1 = gtk_label_new(_("Código"));
  entry1 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box2, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box2), label1, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box2), entry1, FALSE, FALSE, 0);
  
  box3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label2 = gtk_label_new(_("Nombre"));
  entry2 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box3, TRUE, TRUE, 10);
  gtk_box_pack_start(GTK_BOX(box3), label2, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box3), entry2, FALSE, FALSE, 10);
  
  box4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  box5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  button1 = gtk_button_new_with_label(_("Aceptar"));
  box6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  
  gtk_box_pack_start(GTK_BOX(box1), box4, FALSE, FALSE, 10);
  gtk_box_pack_start(GTK_BOX(box4), box5, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box4), button1, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box4), box6, FALSE, FALSE, 0);
  
  gtk_box_set_homogeneous(GTK_BOX(box2), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box3), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box4), TRUE);
  
  gtk_widget_show_all(window);
  
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
  
  gtk_main();
  
  return 0;
}