#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#define STR typedef struct 
STR 
{	
	
	GtkWindow *kbc_intro;
	GtkMenuItem *menu_about1;
	GtkLabel *press_key1;
	GtkLevelBar *level_bar1;
	
}DATA;


int main( int argc, char* argv[]) //FORMALITIES
{	
	//Declarations
	GtkBuilder *builder;
	GtkWindow *main_window;
	GError *err = NULL;
	//namaskar..
	gtk_init(&argc, &argv);
	
	DATA *p;
	
	p = g_slice_new( DATA );//mem alloc
	
	builder = gtk_builder_new();//gtk_builder_new(); is a function returning the address of the new builder.
	gtk_builder_add_from_file(builder,"INTRO.glade",&err);

    if (err != NULL) {
        fprintf (stderr, "Unable to read file: %s\n", err->message);
        g_error_free(err);
        return 1;
    }//searches address in directory to give builder location of kbc.glade
	
	p->kbc_intro = GTK_WINDOW(gtk_builder_get_object(builder, "KBC_INTRO"));
	

	//getting the window from :builder,named : Hello;
	//p->press_key1 =  GTK_LABEL(gtk_builder_get_object(builder, "press_key"));
	//p->level_bar1 = GTK_LEVEL_BAR(gtk_builder_get_object(builder,"level_bar"));

	gtk_builder_connect_signals(builder,p);
	g_object_unref(builder);
	
	gtk_widget_show(p->kbc_intro);//shows window
	gtk_main();//runs main gtk*/
	
	return 0;
}
void on_window_main_destroy()
{
	gtk_main_quit();
}
/*

void show_about(GtkMenuItem *menu, gpointer user_data){
	DATA *p = user_data;
	gtk_window_present(p->about);
}*/