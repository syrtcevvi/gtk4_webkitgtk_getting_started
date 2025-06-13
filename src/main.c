#include<libadwaita-1/adwaita.h>
#include<webkit/webkit.h>

void _register_ui_widget_types() {
    GtkWidget *_web_view = webkit_web_view_new();
    //* This is a floating object reference, nobody owns it, so it should be removed via g_object_ref_sink
    //* rather than via g_object_unref in order to avoid a runtime warning
    g_object_ref_sink(_web_view);
}

void application_quit(
    GSimpleAction *action,
    GVariant *_parameter,
    gpointer user_data
) {
    g_application_quit(G_APPLICATION(user_data));
}

void _register_application_actions(GtkApplication *application) {
    const GActionEntry application_action_entries[] = {
        {"quit", application_quit, NULL, NULL, NULL}
    };
    g_action_map_add_action_entries(
        G_ACTION_MAP(application), application_action_entries,
        G_N_ELEMENTS(application_action_entries), application
    );
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
    _register_application_actions(application);

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
        #ifndef GLIB_VERSION_2_74
        G_APPLICATION_FLAGS_NONE
        #else
        G_APPLICATION_DEFAULT_FLAGS
        #endif
    );

    g_signal_connect(application, "activate", G_CALLBACK(application_activate), NULL);
    g_application_run(G_APPLICATION(application), argc, argv);

    return 0;
}