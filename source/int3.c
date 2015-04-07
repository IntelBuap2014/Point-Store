#include <gtk/gtk.h>

int main(int argc, char *argv[]) {

  GtkWidget *window;
  GtkWidget *table;
  GtkWidget *lblNombre;
  GtkWidget *lblMarca;
  GtkWidget *lblDescr;
  GtkWidget *lblCodBar;
  GtkWidget *EtNombre;
  GtkWidget *EtMarca;
  GtkWidget *EtDescr;
  GtkWidget *EtCodBar;
  GtkWidget *btnReg;
  GtkWidget *frame;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Nuevo Producto");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  frame = gtk_frame_new("Información del producto");
  gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);

  table = gtk_table_new(5, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);

  lblNombre = gtk_label_new("Nombre: ");
  lblMarca = gtk_label_new("Marca: ");
  lblDescr = gtk_label_new("Descripcion del Producto: ");
  lblCodBar = gtk_label_new("Codigo de Barras: ");

  gtk_table_attach(GTK_TABLE(table), lblCodBar, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblNombre, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblMarca,  0, 1, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblDescr,  0, 1, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  EtCodBar = gtk_entry_new();
  EtNombre = gtk_entry_new();
  EtMarca = gtk_entry_new();
  EtDescr = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table), EtCodBar, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), EtNombre, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), EtMarca, 1, 2, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), EtDescr, 1, 2, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  btnReg = gtk_button_new_with_label("Registrar");
  g_signal_connect(G_OBJECT(btnReg), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window)); // Cambiara a posteriori para enviar resultados a BD

  gtk_table_attach(GTK_TABLE(table), btnReg, 1, 2, 4, 5, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  gtk_widget_show(table);

  gtk_widget_show(lblCodBar);
  gtk_widget_show(lblNombre);
  gtk_widget_show(lblMarca);
  gtk_widget_show(lblDescr);
  gtk_widget_show(EtCodBar);
  gtk_widget_show(EtNombre);
  gtk_widget_show(EtMarca);
  gtk_widget_show(EtDescr);
  gtk_widget_show(btnReg);
  gtk_widget_show(window);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
