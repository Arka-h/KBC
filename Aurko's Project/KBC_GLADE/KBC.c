#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#define STR typedef struct 
STR 
{	
	GtkWidget *KBC_Intro;
	GtkMenuItem *menu_about1;
	GtkLabel *press_key1;
	GtkLevelBar *level_bar1;
	
}DATA;


int main( int argc, char* argv[]) //FORMALITIES
{	
	//Declarations
	GtkBuilder *builder;
	GtkWidget *main_window;
	//namaskar..
	gtk_init(&argc, &argv);
	
	DATA *p;
	
	p = g_slice_new( DATA );//mem alloc
	
	builder = gtk_builder_new();//gtk_builder_new(); is a function returning the address of the new builder.
	gtk_builder_add_from_file(builder,"KBC.glade",NULL);//searches address in directory to give builder location of kbc.glade
	
	main_window = GTK_WIDGET(gtk_builder_get_object(builder, "KBC_INTRO"));
	//getting the window from :builder,named : Hello;
	p->press_key1 =  GTK_LABEL(gtk_builder_get_object(builder, "press_key"));
	p->level_bar1 = GTK_LEVEL_BAR(gtk_builder_get_object(builder,"level_bar"));

	gtk_builder_connect_signals(builder,p);
	g_object_unref(builder);
	
	gtk_widget_show(main_window);//shows window
	gtk_main();//runs main gtk*/
	
	return 0;
}
void on_window_main_destroy()
{
	gtk_main_quit();
}
