#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

GtkWidget *button;
GtkWidget *laaaa;

int main( int argc, char* argv[]) 
{	
	//Declarations
	GtkWidget *builder;
	GtkWidget *window;
	//namaskar..
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new();//gtk_builder_new(); is a function returning the address of the new builder.
	gtk_builder_add_from_file (builder,"Example_1.glade",NULL);//searches address in directory to give builder location of example_1.glade
	
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "Hello"));
	//getting the window from :builder,named : Hello;
	laaaa =  GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
	button = GTK_WIDGET(gtk_builder_get_object(builder, "Hello"));
	
	gtk_widget_show(window);//shows window
	gtk_main();//runs main gtk
	
	return 0;
}
//call when button is clicked.
void FUNC()
{
	static unsigned int count=0;//static is necessary as the function is defined only when the button is clicked, each time, it refreshes
	char string_count[30] = {0};
	gtk_label_set_text(GTK_LABEL(button),"Hello World");
	count++;
	sprintf(string_count, "%d",count);
	gtk_label_set_text(GTK_LABEL(laaaa),string_count);
}
// called when window is closed.
void on_window_main_destroy()
{
	gtk_main_quit();
}
