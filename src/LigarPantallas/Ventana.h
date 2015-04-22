#include <gtk/gtk.h>

typedef struct
{
        GSList *windows;


        /* etc... whatever application vars you need */
} MyApp;


on_window_destroy (GtkWidget *widget, MyApp *app)
{
        app->windows = g_slist_remove (app->windows, widget);

        if (g_slist_length (app->windows) == 0)
        {
                /* last window was closed... exit */

                g_debug ("Exiting...");
                g_slist_free (app->windows);
                gtk_main_quit ();
        }
}

