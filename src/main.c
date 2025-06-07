#include<libadwaita-1/adwaita.h>
#include<webkit/webkit.h>

void application_activate(GtkApplication *application, gpointer _user_data) {
    GtkWidget *main_window = adw_application_window_new(application);
    gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

    GtkWidget *window_content_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget *window_header_bar = adw_header_bar_new();
    gtk_box_append(GTK_BOX(window_content_box), window_header_bar);

    GtkWidget *web_view = webkit_web_view_new();
    gtk_widget_set_vexpand(web_view, TRUE);
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web_view), "https://github.com/");
    gtk_box_append(GTK_BOX(window_content_box), web_view);

    adw_application_window_set_content(ADW_APPLICATION_WINDOW(main_window), window_content_box);
    gtk_window_present(GTK_WINDOW(main_window));
}

int main(int argc, char **argv) {
    AdwApplication *application = adw_application_new(
        "com.gtk4_webkitgtk.getting_started",
        G_APPLICATION_DEFAULT_FLAGS
    );

    g_signal_connect(application, "activate", G_CALLBACK(application_activate), NULL);
    g_application_run(G_APPLICATION(application), argc, argv);

    return 0;
}