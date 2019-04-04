#include"kbc_game.h"

/* 
************************************************************************************************************************** 
GUI Functions
************************************************************************************************************************** 
*/

void choose_50_50(GtkButton*button, gpointer user_data)/*new*/
{
	/*Related to random selection of 2 numbers
		0             1 
		2             3
	*/
	DATA *game = user_data;
	
	gtk_widget_hide((GtkWidget*)button);
	gtk_widget_show((GtkWidget*)game->button_50_50_);

	if((correct_ans==0)||(correct_ans==3))
	{
		gtk_widget_hide((GtkWidget*)game->option[1]);
		gtk_widget_show((GtkWidget*)game->option_[1]);
		gtk_widget_hide((GtkWidget*)game->option[2]);
		gtk_widget_show((GtkWidget*)game->option_[2]);
	}
	else if((correct_ans==1)||(correct_ans==2))
	{
		gtk_widget_hide((GtkWidget*)game->option[0]);
		gtk_widget_show((GtkWidget*)game->option_[0]);
		gtk_widget_hide((GtkWidget*)game->option[3]);
		gtk_widget_show((GtkWidget*)game->option_[3]);
	}
}

gboolean option_0(gpointer user_data)/*new*/
{
		DATA*game = user_data;

		gtk_widget_hide((GtkWidget*)game->option[0]);
		gtk_widget_show((GtkWidget*)game->option_[0]);
		// check_answer(0);
		return FALSE;
}
void option0_toggled(GtkToggleButton*button,gpointer user_data)/*new*/
{
	DATA*game = user_data;
	g_timeout_add(5,(GSourceFunc)option_0,user_data);

}

gboolean option_1(gpointer user_data)/*new*/
{
		DATA*game = user_data;

		gtk_widget_hide((GtkWidget*)game->option[1]);
		gtk_widget_show((GtkWidget*)game->option_[1]);
		// check_answer(1);
		return FALSE;
}
void option1_toggled(GtkToggleButton*button,gpointer user_data)/*new*/
{
	DATA*game = user_data;
	g_timeout_add(5,(GSourceFunc)option_1,user_data);

}

gboolean option_2(gpointer user_data)/*new*/
{
		DATA*game = user_data;

		gtk_widget_hide((GtkWidget*)game->option[2]);
		gtk_widget_show((GtkWidget*)game->option_[2]);
		// check_answer(2);
		return FALSE;
}
void option2_toggled(GtkToggleButton*button,gpointer user_data)/*new*/
{
	DATA*game = user_data;
	g_timeout_add(5,(GSourceFunc)option_2,user_data);

}

gboolean option_3(gpointer user_data)/*new*/
{
		DATA*game = user_data;

		gtk_widget_hide((GtkWidget*)game->option[3]);
		gtk_widget_show((GtkWidget*)game->option_[3]);
		// check_answer(3);
		return FALSE;
}
void option3_toggled(GtkToggleButton*button,gpointer user_data)/*new*/
{
	DATA*game = user_data;
	g_timeout_add(5,(GSourceFunc)option_3,user_data);

}
void phone_a_friend_call(GtkButton*button ,gpointer user_data)//to implement, need to use delay print and progress bar
{
	DATA *game = user_data;
	
	gtk_widget_hide((GtkWidget*)button);
	gtk_widget_show((GtkWidget*)game->phone_a_friend_);
}

void joker_select(GtkButton*button,gpointer user_data)//to implement, need to change unique_random();
{
	DATA*game = user_data;
	gtk_widget_hide((GtkWidget*)button);
	gtk_widget_show((GtkWidget*)game->joker_);
}

void game_restart(GtkButton*button, gpointer user_data)
{	
	DATA *game = user_data;
	// fflush(stdin);
	unique_random(&x);
	
printf("\n");
	for(int i=0;i<5;i++)
	printf("%d ",x.easy_index[i]);
printf("\n");
	for(int i=0;i<5;i++)
	printf("%d ",x.medium_index[i]);
printf("\n");
	for(int i=0;i<5;i++)
	printf("%d ",x.hard_index[i]);
printf("\n");

	gtk_widget_hide((GtkWidget *)game->end_game);

	gtk_widget_hide((GtkWidget*)game->button_50_50_);
	gtk_widget_hide((GtkWidget*)game->button_audience_vote_);
	gtk_widget_hide((GtkWidget*)game->joker_);
	gtk_widget_hide((GtkWidget*)game->phone_a_friend_);

	gtk_widget_show((GtkWidget*)game->button_50_50);
	gtk_widget_show((GtkWidget*)game->button_audience_vote);
	gtk_widget_show((GtkWidget*)game->joker);
	gtk_widget_show((GtkWidget*)game->phone_a_friend);

	gtk_window_present(game->kbc_intro);
	gtk_label_set_label(game->intro_label,"Welcome to KAUN BANEGA CROREPATI 2019...");
	intro_level_bar(game->start_game,user_data);
}

void set_intro_label(float fraction, GtkLabel *label)
{

	if((fraction >= 1.0/4) && (fraction<2.0/3))
	{
		gtk_label_set_label(label,"Follow the instructions for further details...");
	}
	if(fraction>=2.0/3)
	{
		gtk_label_set_label(label,"See the About Developers to view details about team...");
	}

}


gboolean animation(gpointer user_data)
{
	DATA*game = user_data;

	static int i=0;
	static int counter=0;
	if(counter<=300)
	{
		if(i<10)
			{
				gtk_widget_hide((GtkWidget*)game->image_fore[i]);
				gtk_widget_show((GtkWidget*)game->image_fore[++i]);
				counter++;
				return TRUE;
			}
		else if(i==10)
			{
				gtk_widget_hide((GtkWidget*)game->image_fore[i]);
				gtk_widget_show((GtkWidget*)game->image_fore[++i]);
				counter++;
				return TRUE;
			}
		else if(i==11)
			{
				gtk_widget_hide((GtkWidget*)game->image_fore[i]);
				gtk_widget_show((GtkWidget*)game->image_fore[--i]);
				counter++;
				return TRUE;
			}
	}
	return FALSE;
}

gboolean fill(GtkProgressBar* bar,gpointer user_data)
{
	DATA *game = user_data;
	float fraction;
	fraction = gtk_progress_bar_get_fraction(bar);
	fraction += 0.00045;//adjusted for Total time 30s.
	gtk_progress_bar_set_fraction(bar,fraction);
	if(fraction <= 1.0)
		return TRUE;
	else
	{ 
		return FALSE;
	}

}
void intro_level_bar (GtkToggleButton *button,gpointer user_data)
{
	DATA *game = user_data;

	gtk_widget_hide((GtkWidget *)button);
    gtk_widget_show((GtkWidget *)game->progress_bar);

	thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'E');
	
	gtk_progress_bar_set_fraction(game->progress_bar,0.0);

	g_timeout_add(2.3/*Interval after which function will run*/,\
	(GSourceFunc)entry_fill/*Return gboolean FALSE to exit else wait for 2.3 milisec*/,\
	 user_data);//non-modular function,(?threads maybe?)

	g_timeout_add(50,(GSourceFunc)animation, user_data);//25 frames per second 1000/25
	g_timeout_add(12500,(GSourceFunc)start_game, user_data);//23500+11sec

	pthread_join(thread_1,NULL);
}

static gboolean entry_fill(gpointer user_data){

	DATA *game = user_data;

	float fraction;
	fraction = gtk_progress_bar_get_fraction(game->progress_bar);
	set_intro_label(fraction, game->intro_label);
	fraction += 0.0003;
	gtk_progress_bar_set_fraction(game->progress_bar,fraction);

	if(fraction <= 1.0)
		return TRUE;
	else
	return FALSE;
}

gboolean start_game(gpointer user_data)
{
  DATA *game = user_data;
  for(int i=0;i<current_question;i++)//reset symbols
  {
  	gtk_widget_hide((GtkWidget *)game->q_[i]);
  	gtk_widget_show((GtkWidget *)game->q[i]);
  }
  gtk_widget_hide((GtkWidget *)game->instructions);
  gtk_widget_hide((GtkWidget *)game->about_devs);
  gtk_widget_hide((GtkWidget *)game->kbc_intro);
  gtk_window_present(game->main_screen);
  gtk_window_fullscreen(game->main_screen);

  current_question = 0;
  next_question();
  	return FALSE;
}



void result_screen(GtkMenuItem *button,gpointer user_data)
{
	DATA *game = user_data;

	gtk_widget_hide((GtkWidget *)game->main_screen);
	gtk_widget_hide((GtkWidget *)game->instructions);
	gtk_widget_hide((GtkWidget *)game->about_devs);
	gtk_widget_show((GtkWidget *)game->end_game);
}

void hide_audience_vote(GtkButton *button,gpointer user_data)
{
	DATA*game = user_data;
	gtk_widget_show((GtkWidget*)game->audience_cover_image);
	gtk_widget_hide((GtkWidget*)game->audience_vote);

}
gboolean show_audience_vote_result(gpointer user_data)
{
	DATA*game = user_data;
    gtk_widget_show((GtkWidget*)game->audience_option[correct_ans]);
    gtk_widget_show((GtkWidget*)game->exit_button);
    gtk_widget_hide((GtkWidget*)game->audience_vote_progress_bar);
    gtk_widget_hide((GtkWidget*)game->audience_cover_image);
    gtk_widget_hide((GtkWidget*)game->button_audience_vote);
    gtk_widget_show((GtkWidget*)game->button_audience_vote_);

  return FALSE;
}
void show_audience_vote(GtkButton *button,gpointer user_data)/*mod*/
{
  DATA *game = user_data;
  gtk_widget_hide((GtkWidget*)game->audience_option[0]);
  gtk_widget_hide((GtkWidget*)game->audience_option[1]);
  gtk_widget_hide((GtkWidget*)game->audience_option[2]);
  gtk_widget_hide((GtkWidget*)game->audience_option[3]);
  gtk_window_present(game->audience_vote);
  gtk_widget_hide((GtkWidget*)game->exit_button);
  gtk_widget_show((GtkWidget*)game->audience_cover_image);
  gtk_widget_show((GtkWidget*)game->audience_vote_progress_bar);

  thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'S');

  gtk_progress_bar_set_fraction(game->audience_vote_progress_bar,0.0);

  g_timeout_add(5,(GSourceFunc)fill, game->audience_vote_progress_bar);
  g_timeout_add(18000,(GSourceFunc)show_audience_vote_result,user_data);

  pthread_join(thread_1,NULL);
}


/* 
************************************************************************************************************************** 
some small-small GUI functions as dessert
************************************************************************************************************************** 
*/


void show_about_devs(GtkMenuItem *menuitem, gpointer user_data){//shows developers page

  DATA *game = user_data;
  gtk_window_present(game->about_devs);
}

void show_instructions(GtkMenuItem *menuitem, gpointer user_data){//shows instructions page

  DATA *game = user_data;
  gtk_window_present(game->instructions);
}

void hide_instructions(GtkButton *button, gpointer user_data){

  DATA *game = user_data;
  gtk_widget_hide(GTK_WIDGET((GtkWidget *)game->instructions));

}

void close_window(GtkWindow *window){
  gtk_window_close(window);
}

void hide_window(GtkButton *button){
  GtkWidget *widget = gtk_widget_get_toplevel(GTK_WIDGET(button));//gets parent window
  gtk_widget_hide(widget);
}
