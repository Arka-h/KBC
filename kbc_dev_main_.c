#include "kbc_game.h"


/*The main file...*/
int main( int argc, char* argv[]) 
{ 
	GtkCssProvider *cssprovider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssprovider,"kbc_dark_theme.css",NULL);

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
  game->kbc_intro =     GTK_WINDOW(gtk_builder_get_object(builder, "KBC_INTRO"));
  game->about_devs =    GTK_WINDOW(gtk_builder_get_object(builder, "ABOUT_DEVS"));
  game->instructions =  GTK_WINDOW(gtk_builder_get_object(builder, "INSTRUCTIONS"));
  game->main_screen =   GTK_WINDOW(gtk_builder_get_object(builder, "MAIN_SCREEN"));
  game->audience_vote = GTK_WINDOW(gtk_builder_get_object(builder, "AUDIENCE_VOTE"));
  game->end_game =      GTK_WINDOW(gtk_builder_get_object(builder, "RESULT"));

  game->option[0] =  GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_1"));
  game->option[1] =  GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_2"));
  game->option[2] =  GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_3"));
  game->option[3] =  GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"option_4"));
  game->start_game = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"start_game"));

  game->audience_cover_image = GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_cover_image"));
  game->audience_option[0] =   GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_0"));
  game->audience_option[1] =   GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_1"));
  game->audience_option[2] =   GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_2"));
  game->audience_option[3] =   GTK_IMAGE(gtk_builder_get_object(builder,"audience_vote_option_3"));


  game->question_label = GTK_LABEL(gtk_builder_get_object(builder,"question_label"));
  game->intro_label =    GTK_LABEL(gtk_builder_get_object(builder,"intro_label"));
  game->host_label =     GTK_LABEL(gtk_builder_get_object(builder,"Info"));
  
  game->progress_bar =               GTK_PROGRESS_BAR(gtk_builder_get_object(builder,"progress_bar"));
  game->audience_vote_progress_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder,"audience_vote_progress_bar"));

  game->button_audience_vote =   GTK_BUTTON(gtk_builder_get_object(builder,"button"));
  game->button_50_50 =           GTK_BUTTON(gtk_builder_get_object(builder,"button_50_50"));
  game->button_50_50_ =          GTK_BUTTON(gtk_builder_get_object(builder,"button_50_50^"));
  game->button_audience_vote =   GTK_BUTTON(gtk_builder_get_object(builder,"audience_vote"));
  game->button_audience_vote_ =  GTK_BUTTON(gtk_builder_get_object(builder,"audience_vote^"));
  game->phone_a_friend =         GTK_BUTTON(gtk_builder_get_object(builder,"phone_a_friend"));
  game->phone_a_friend_ =        GTK_BUTTON(gtk_builder_get_object(builder,"phone_a_friend^"));
  game->joker =                  GTK_BUTTON(gtk_builder_get_object(builder,"joker"));
  game->joker_ =                 GTK_BUTTON(gtk_builder_get_object(builder,"joker^"));
  
  game->q[0] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q1"));
  game->q[1] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q2"));
  game->q[2] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q3"));
  game->q[3] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q4"));
  game->q[4] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q5"));
  game->q[5] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q6"));
  game->q[6] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q7"));
  game->q[7] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q8"));
  game->q[8] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q9"));
  game->q[9] =                   GTK_BUTTON(gtk_builder_get_object(builder,"q10"));
  game->q[10] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q11"));
  game->q[11] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q12"));
  game->q[12] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q13"));
  game->q[13] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q14"));
  game->q[14] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q15"));

  game->q_[0] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q1_"));
  game->q_[1] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q2_"));
  game->q_[2] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q3_"));
  game->q_[3] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q4_"));
  game->q_[4] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q5_"));
  game->q_[5] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q6_"));
  game->q_[6] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q7_"));
  game->q_[7] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q8_"));
  game->q_[8] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q9_"));
  game->q_[9] =                  GTK_BUTTON(gtk_builder_get_object(builder,"q10_"));
  game->q_[10] =                 GTK_BUTTON(gtk_builder_get_object(builder,"q11_"));
  game->q_[11] =                 GTK_BUTTON(gtk_builder_get_object(builder,"q12_"));
  game->q_[12] =                 GTK_BUTTON(gtk_builder_get_object(builder,"q13_"));
  game->q_[13] =                 GTK_BUTTON(gtk_builder_get_object(builder,"q14_"));
  game->q_[14] =                 GTK_BUTTON(gtk_builder_get_object(builder,"q15_"));

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























