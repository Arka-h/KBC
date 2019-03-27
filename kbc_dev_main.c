#include "kbc_game.h"


/*The main file...*/
int main( int argc, char* argv[]) 
{ 
	GtkCssProvider *cssprovider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssprovider,"untitled.css",NULL);

  GtkBuilder *builder;//declarations...
  GError *err = NULL;
  gtk_init(&argc, &argv);//Initialisations or namaskar.. 
  game = g_slice_new( DATA );//Mem Alloc
  builder = gtk_builder_new();  //gtk_builder_new()is a function 
  								//returning the address of the new builder.
//searches address in directory to give builder location of kbc.glade
  gtk_builder_add_from_file(builder,"kbc_dev_1.glade",&err);
	if (err != NULL) {
		fprintf (stderr, "Unable to read file: %s\n", err->message);
		g_error_free(err);
		return 1;
	}
  //linking of objects in code with that of the xml glade file...  
  game->kbc_intro = GTK_WINDOW(gtk_builder_get_object(builder, "KBC_INTRO"));
  game->about_devs = GTK_WINDOW(gtk_builder_get_object(builder, "ABOUT_DEVS"));
  game->instructions = GTK_WINDOW(gtk_builder_get_object(builder, "INSTRUCTIONS"));
  game->main_screen = GTK_WINDOW(gtk_builder_get_object(builder, "MAIN_SCREEN"));
  game->audience_vote = GTK_WINDOW(gtk_builder_get_object(builder, "AUDIENCE_VOTE"));
  game->end_game = GTK_WINDOW(gtk_builder_get_object(builder, "RESULT"));

  game->option[0] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_1"));
  game->option[1] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_2"));
  game->option[2] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_3"));
  game->option[3] = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_4"));
  game->start_game = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"start_game"));

  game->audience_cover_image = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_cover_image"));
  game->audience_option[0] = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_0"));
  game->audience_option[1] = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_1"));
  game->audience_option[2] = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_2"));
  game->audience_option[3] = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_3"));


  game->question_label = GTK_LABEL(gtk_builder_get_object(builder,"question_label"));
  game->intro_label = GTK_LABEL(gtk_builder_get_object(builder,"intro_label"));
  game->host_label = GTK_LABEL(gtk_builder_get_object(builder,"Info"));
  
  game->progress_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder,"progress_bar"));
  game->audience_vote_progress_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder,"audience_vote_progress_bar"));

  game->button_audience_vote = GTK_BUTTON(gtk_builder_get_object(builder,"button"));

  gtk_builder_connect_signals(builder,game);//connecting signals.
  g_object_unref(builder);//un-referencing the builder.
  

  gtk_style_context_add_provider_for_screen(gtk_widget_get_screen((GtkWidget*)game->kbc_intro),\
  	GTK_STYLE_PROVIDER(cssprovider),\
  	GTK_STYLE_PROVIDER_PRIORITY_USER);

	srand(time(0));

  //shows window
  game_restart( game->button_audience_vote ,game);
  gtk_main();//runs main gtk
	
  return 0;
}























