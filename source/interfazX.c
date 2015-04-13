#include <gtk/gtk.h>
#include <libintl.h>
#include <locale.h>

int main(int argc, char *argv[]) {
bind_textdomain_codeset ("Point-Store", "UTF-8");
setlocale(LC_ALL, "");
bindtextdomain("Point-Store", "idioma");
textdomain("Point-Store");

  GtkWidget *window;
  GtkWidget *table;

  GtkWidget *label1;
  GtkWidget *label2;

  GtkWidget *entry1;
  GtkWidget *entry2;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Verificar existencxyz");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  table = gtk_table_new(2, 2, FALSE);
  gtk_container_add(GTK_CONTAINER(window), table);

  label1 = gtk_label_new("x");
  label2 = gtk_label_new("y");

  gtk_table_attach(GTK_TABLE(table), label1, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), label2, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  entry1 = gtk_entry_new();
  entry2 = gtk_entry_new();

  gtk_table_attach(GTK_TABLE(table), entry1, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
  gtk_table_attach(GTK_TABLE(table), entry2, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

  gtk_widget_show(table);

  gtk_widget_show(label1);
  gtk_widget_show(label2);

  gtk_widget_show(entry1);
  gtk_widget_show(entry2);

  gtk_widget_show(window);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_main();

  return 0;
}
