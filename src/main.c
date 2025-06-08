#include<libadwaita-1/adwaita.h>
#include<webkit/webkit.h>

void _register_ui_widget_types() {
    GtkWidget *_web_view = webkit_web_view_new();
    g_object_unref(_web_view);
}

void application_activate(GtkApplication *application, gpointer _user_data) {
    /*
        When we use gtk_builder and xml file with ui definition we might want to use
        some types outside of the gtk4 and libadwaita libraries. In this example
        we use WebKitWebView. Try to comment this line out and check that you receive
        error message about using unknown type WebKitWebView.

        The error message may look like the following: "failed to add UI from file resources/main_window.ui: 
        resources/main_window.ui:15:1 Invalid object type 'WebKitWebView'"

        To opt out this error we need to create a dummy object for each "foreign" type.
    */
    _register_ui_widget_types();

    GtkBuilder *ui_builder = gtk_builder_new_from_file("resources/main_window.ui");

    GtkWidget *main_window = GTK_WIDGET(gtk_builder_get_object(ui_builder, "main_window"));
    gtk_window_set_application(GTK_WINDOW(main_window), GTK_APPLICATION(application));
    
    GtkWidget *web_view = GTK_WIDGET(gtk_builder_get_object(ui_builder, "web_view"));
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web_view), "https://github.com/");

    g_object_unref(ui_builder);
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