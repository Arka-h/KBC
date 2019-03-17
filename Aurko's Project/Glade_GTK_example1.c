
#include <gtk/gtk.h>
#define STRT typedef struct

STRT
{
	GtkWidget *w_lbl_time;
}app_widgets;

gboolean timer_handler(app_widgets *widgets);

int main( int argc, char* argv[]) 
{	
	GtkBuilder *builder;
	GtkWidget *window;
	app_widgets *widgets =g_slice_new(app_widgets);
	
	gtk_init(&argc,&argv);
	
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "KBC.glade"
	
	return 0;
}
