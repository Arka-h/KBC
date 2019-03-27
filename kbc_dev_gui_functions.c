#include"kbc_game.h"

/* 
************************************************************************************************************************** 
GUI Functions
************************************************************************************************************************** 
*/


void game_restart(GtkButton*button, gpointer user_data)
{	
	DATA *game = user_data;
	unique_random(&x);

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
	gtk_window_present(game->kbc_intro);
	gtk_label_set_label(game->intro_label,"Welcome to KAUN BANEGA CROREPATI 2019...");
	intro_level_bar(game->start_game,user_data);
}

void set_intro_label(float fraction, GtkLabel *label){

	if((fraction >= 1.0/4) && (fraction<2.0/3)){
		gtk_label_set_label(label,"Follow the instructions for further details...");
	}
	if(fraction>=2.0/3){
		gtk_label_set_label(label,"See the About Developers to view details about team...");
	}

}

gboolean fill(GtkProgressBar* bar,gpointer user_data)
{
	DATA *game = user_data;

	float fraction;
	fraction = gtk_progress_bar_get_fraction(bar);
	fraction += 0.00026;//since callback after 3ms.Total time 60s.
	gtk_progress_bar_set_fraction(bar,fraction);
	if(fraction <= 1.0)
		return TRUE;
	else
	{ 
		gtk_progress_bar_set_fraction(bar,0);
		//change_screen
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

	g_timeout_add(2.3/*Interval after which function will run*/,(GSourceFunc)entry_fill/*Return gboolean FALSE to exit else wait for 2.3 milisec*/, user_data);//non-modular function,(?threads maybe?)
	g_timeout_add(23500,(GSourceFunc)start_game, user_data);//23500

	pthread_join(thread_1,NULL);
}

static gboolean entry_fill(gpointer user_data){

	DATA *game = user_data;

	float fraction;
	fraction = gtk_progress_bar_get_fraction(game->progress_bar);
	set_intro_label(fraction, game->intro_label);
	fraction += 0.000152;
	gtk_progress_bar_set_fraction(game->progress_bar,fraction);

	if(fraction <= 1.0)
		return TRUE;
	else
	return FALSE;
}

gboolean start_game(gpointer user_data)
{
  DATA *game = user_data;

  gtk_widget_hide((GtkWidget *)game->instructions);
  gtk_widget_hide((GtkWidget *)game->about_devs);
  gtk_widget_hide((GtkWidget *)game->kbc_intro);
  gtk_window_present(game->main_screen);
  gtk_window_fullscreen(game->main_screen);
  // gtk_window_fullscreen(game->main_screen);

	
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
// void print_strings(int n)
// {
// 	/*Each n will be string number to be displayed in sequence*/
// 	switch(n)
// 	{
// 		case 0 :{	while(string[0][int i]!=)
// 					printf("%c",string[0][i]);i++;
// 	}

// }

//uninteresting peice of code doing exactly what the function name suggests...
void hide_audience_vote(GtkButton *button,gpointer user_data)
{
	DATA*game = user_data;

	gtk_widget_hide((GtkWidget*)game->audience_vote);
	gtk_widget_show((GtkWidget*)game->audience_cover_image);

}

void show_audience_vote(GtkButton *button,gpointer user_data)
{
  DATA *game = user_data;
  gtk_window_present(game->audience_vote);
  g_timeout_add(6,(GSourceFunc)fill, game->audience_vote_progress_bar);

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

void change_50_50(GtkButton*button,gpointer user_data)
{
	DATA*game = user_data;
	gtk_widget_hide(GTK_WIDGET((GtkWidget*)button));
	gtk_widget_show(GTK_WIDGET((GtkWidget*)game->button_audience_vote_));
}
void change_audience_vote(GtkButton*button,gpointer user_data)
{
	DATA*game = user_data;
	gtk_widget_hide(GTK_WIDGET((GtkWidget*)button));
	gtk_widget_show(GTK_WIDGET((GtkWidget*)game->button_50_50_));
}