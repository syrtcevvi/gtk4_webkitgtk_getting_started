#include<gtk/gtk.h>

void application_activate(GtkApplication *application, gpointer _user_data) {
    GtkWidget *main_window = gtk_application_window_new(application);
    gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

    GtkWidget *hello_world_label = gtk_label_new("Hello World!");
    gtk_window_set_child(GTK_WINDOW(main_window), hello_world_label);

    gtk_window_present(GTK_WINDOW(main_window));
}

int main(int argc, char **argv) {
    GtkApplication *application = gtk_application_new(
        "com.gtk4_webkitgtk.getting_started",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(application, "activate", G_CALLBACK(application_activate), NULL);
    g_application_run(G_APPLICATION(application), argc, argv);

    return 0;
}