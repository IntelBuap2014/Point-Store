#include <stdio.h>
#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

#define _(cadena) gettext(cadena)


typedef struct produc_data{
    GtkWidget *EtNombre;
    GtkWidget *EtMarca;
    GtkWidget *EtDescr;
    GtkWidget *EtCodBar;
} produc_data;

static gboolean callback(GtkWidget *widget, gpointer data){
  produc_data* pd = (produc_data*)data;

  const gchar *Nombre,
              *Codigo,
              *Marca,
              *Descripcion;

  Codigo = gtk_entry_get_text(GTK_ENTRY(pd->EtCodBar));
  Nombre = gtk_entry_get_text(GTK_ENTRY(pd->EtNombre));
  Marca = gtk_entry_get_text(GTK_ENTRY(pd->EtMarca));
  Descripcion = gtk_entry_get_text(GTK_ENTRY(pd->EtDescr));

  g_print("Se escribio el producto con codigo %s , de nombre %s de la marca %s %s \n", Codigo, Nombre, Marca, Descripcion);
}

int main(int argc, char *argv[]) {


  bind_textdomain_codeset ("Point-Store", "UTF-8");
  setlocale(LC_ALL, "");
  bindtextdomain("Point-Store", "idioma");
  textdomain("Point-Store");


  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *lblNombre;
  GtkWidget *lblMarca;
  GtkWidget *lblDescr;
  GtkWidget *lblCodBar;

  GtkWidget *btnReg;
  GtkWidget *btnCerrar;
  GtkWidget *frame;

  produc_data* pd = g_malloc(sizeof(*pd));

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), _("Nuevo Producto"));
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  frame = gtk_frame_new(_("Información del producto"));
  gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_ETCHED_IN);

  table = gtk_table_new(6, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);

  lblNombre = gtk_label_new(_("Nombre: "));
  lblMarca = gtk_label_new(_("Marca: "));
  lblDescr = gtk_label_new(_("Descripcion del Producto: "));
  lblCodBar = gtk_label_new(_("Codigo de Barras: "));


  gtk_table_attach(GTK_TABLE(table), lblCodBar, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblNombre, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblMarca,  0, 1, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), lblDescr,  0, 1, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_entry_set_max_length( pd->EtCodBar, 15);
  pd->EtNombre = gtk_entry_new();
  pd->EtMarca = gtk_entry_new();
  pd->EtDescr = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table), pd->EtCodBar, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), pd->EtNombre, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), pd->EtMarca, 1, 2, 2, 3, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), pd->EtDescr, 1, 2, 3, 4, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  btnReg = gtk_button_new_with_label(_("Registrar"));
  btnCerrar = gtk_button_new_with_label(_("Cerrar"));

  g_signal_connect(btnReg,"clicked",G_CALLBACK(callback),(gpointer)pd);
  g_signal_connect(G_OBJECT(btnCerrar), "clicked",G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_table_attach(GTK_TABLE(table), btnReg, 1, 2, 4, 5, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), btnCerrar, 1, 2, 5, 6, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  gtk_widget_show(table);
  gtk_widget_show(lblCodBar);
  gtk_widget_show(lblNombre);
  gtk_widget_show(lblMarca);
  gtk_widget_show(lblDescr);
  gtk_widget_show(pd->EtCodBar);
  gtk_widget_show(pd->EtNombre);
  gtk_widget_show(pd->EtMarca);
  gtk_widget_show(pd->EtDescr);
  gtk_widget_show(btnReg);
  gtk_widget_show(btnCerrar);
  gtk_widget_show(window);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
