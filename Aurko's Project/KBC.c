#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <time.h>
#define STR typedef struct 



STR 
{	
	
	GtkWindow *kbc_intro,*audience_v,*instructions,*number,*phone_f,*end_game,*main_screen,*about_devs;
	GtkMenuItem *menu_about1;
	GtkLabel *press_key1,*question_label;
	GtkLevelBar *level_bar1;
	GtkToggleButton *option_1,*option_2,*option_3,*option_4;
	
}DATA;

int main( int argc, char* argv[]) //FORMALITIES
{	
	
	//Declarations
	GtkBuilder *builder;
	GtkWindow *main_window;
	GError *err = NULL;
	//namaskar..
	gtk_init(&argc, &argv);
	
	DATA *data;
	
	data = g_slice_new( DATA );//mem alloc
	
	builder = gtk_builder_new();//gtk_builder_new(); is a function returning the address of the new builder.
	gtk_builder_add_from_file(builder,"kbc_dev.glade",&err);

    if (err != NULL) {
        fprintf (stderr, "Unable to read file: %s\n", err->message);
        g_error_free(err);
        return 1;
    }//searches address in directory to give builder location of kbc.glade
	
	data->kbc_intro = GTK_WINDOW(gtk_builder_get_object(builder, "KBC_INTRO"));
	data->about_devs = GTK_WINDOW(gtk_builder_get_object(builder, "ABOUT_DEVS"));
	data->instructions = GTK_WINDOW(gtk_builder_get_object(builder, "INSTRUCTIONS"));
	data->main_screen = GTK_WINDOW(gtk_builder_get_object(builder, "MAIN_SCREEN"));
	data->option_1 = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_1"));
	data->option_2 = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_2"));
	data->option_3 = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_3"));
	data->option_4 = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_4"));
	data->question_label = GTK_LABEL(gtk_builder_get_object(builder,"question_label"));
	gtk_builder_connect_signals(builder,data);
	g_object_unref(builder);
	

	
	gtk_window_fullscreen(data->kbc_intro);
	gtk_widget_show(GTK_WIDGET(data->kbc_intro));//shows window
	


	
	gtk_main();//runs main gtk*/
	


	
	
	return 0;
}

void show_about_devs(GtkMenuItem *menuitem, gpointer user_data){
	DATA *p = user_data;

	gtk_window_present(p->about_devs);
}

void show_instructions(GtkMenuItem *menuitem, gpointer user_data){
	DATA *data = user_data;

	gtk_window_present(data->instructions);
}

void hide_instructions(GtkMenuItem *menuitem, gpointer user_data){
	DATA *data = user_data;

	gtk_widget_hide(GTK_WIDGET(data->instructions));

}
void close_window(GtkWindow *window, gpointer data){
	gtk_window_close(window);
}

void hide_window(GtkButton *button){
	GtkWidget *widget = gtk_widget_get_toplevel(GTK_WIDGET(button));//gets parent window
	gtk_widget_hide(widget);
}

void start_game(GtkButton *button, gpointer user_data){
	DATA *data = user_data;

	gtk_window_fullscreen(data->main_screen);
	gtk_window_present(data->main_screen);

	gtk_window_close(data->instructions);
	gtk_window_close(data->about_devs);
	gtk_window_close(data->kbc_intro);
	
}

// gtk_button_set_label(GtkToggleButton *button,"hello");
// use this function to set label to button




















