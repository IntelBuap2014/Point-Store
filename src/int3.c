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
  GtkWidget *box4;
  GtkWidget *label3;
  GtkWidget *entry3;
  GtkWidget *box5;
  GtkWidget *box6;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *box7;
  GtkWidget *label4;
  GtkWidget *entry4;
  
  gtk_init(&argc, &argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "PointStore");
  gtk_container_set_border_width(GTK_CONTAINER(window),10);
  
  frame = gtk_frame_new(_("Nuevo Producto"));
  box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  
  gtk_container_add(GTK_CONTAINER(window), frame);
  gtk_container_add(GTK_CONTAINER(frame), box1);
  
  box7 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label4 = gtk_label_new(_("Código de Barras"));
  entry4 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box7, FALSE, FALSE, 8);
  gtk_box_pack_start(GTK_BOX(box7), label4, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box7), entry4, FALSE, FALSE, 0);  
  
  box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label1 = gtk_label_new(_("Nombre"));
  entry1 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, FALSE, 8);
  gtk_box_pack_start(GTK_BOX(box2), label1, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box2), entry1, FALSE, FALSE, 0);
  
  box3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label2 = gtk_label_new(_("Marca"));
  entry2 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box3, FALSE, FALSE, 8);
  gtk_box_pack_start(GTK_BOX(box3), label2, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box3), entry2, FALSE, FALSE, 0);
  
  box4 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  label3 = gtk_label_new(_("Descripción del Producto"));
  entry3 = gtk_entry_new();
  
  gtk_box_pack_start(GTK_BOX(box1), box4, FALSE, FALSE, 8);
  gtk_box_pack_start(GTK_BOX(box4), label3, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box4), entry3, FALSE, FALSE, 10);
  
  box5 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
  box6 = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  button1 = gtk_button_new_with_label(_("Registrar"));
  button2 = gtk_button_new_with_label(_("Cerrar"));
  
  gtk_box_pack_start(GTK_BOX(box1), box5, FALSE, FALSE, 8);
  gtk_box_pack_start(GTK_BOX(box5), box6, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(box5), button1, FALSE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box5), button2, FALSE, TRUE, 0);
  
  gtk_box_set_homogeneous(GTK_BOX(box2), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box3), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box4), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box5), TRUE);
  gtk_box_set_homogeneous(GTK_BOX(box7), TRUE);
  
  gtk_widget_show_all(window);
  
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_main();
  return 0;
}