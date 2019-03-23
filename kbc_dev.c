#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <time.h>
#include <pthread.h>
#define STR typedef struct 
#define thred_function void * (*)(void *) //pthread function cast 
#define thred_parameter void * restrict   //pthread parameter cast
//Setting up some data_types...
FILE *file_p;

STR
{
	int easy_index[5];
	int medium_index[5];
	int hard_index[5];
}Index;
Index question;

STR//typedef struct
{
	char string[450];
}Question;
//Question data type.

STR
{
	char string[200];
}Option;
//Option data type.
//used below
STR
{
	short int correct_ans[30] ;//30 correct answers.
	Question questions[30];//30 questions.
	Option options[30][4];//4 options for each question.
}question_paper_30;
//Two sizes of Question_paper data types
STR
{
	short int correct_ans[45] ;//45 correct answers.
	Question questions[45] ;//45 questions
	Option options[45][4] ;//4 options for each question.
}question_paper_45;

//global declarations.
question_paper_30 hard;
question_paper_45 medium;
question_paper_30 easy;
//end of file handling structs and global declarations...



//GUI related data types and global declarations


STR 
{
  
  GtkWindow *kbc_intro,*audience_vote,*instructions,*number,*phone_f/*passive for now*/,*end_game,*main_screen,*about_devs;
  GtkMenuItem *menu_about;
  GtkLabel *intro_label, *question_label, *host_label;
  GtkToggleButton *option[4], *start_game;
  GtkButton *q15,*q14,*q13,*q12,*q11,*q10,*q9,*q8,*q7,*q6,*q5,*q4,*q3,*q2,*q1,*button_50_50,*button_audience_vote,*phone_a_friend;
  GtkButton *q15_,*q14_,*q13_,*q12_,*q11_,*q10_,*q9_,*q8_,*q7_,*q6_,*q5_,*q4_,*q3_,*q2_,*q1_,*button_50_50_,*button_audience_vote_,*phone_a_friend_;
  GtkImage *audience_cover_image,*audience_option[4];
  GtkProgressBar *progress_bar, *audience_vote_progress_bar;

}DATA;

//GUI objects declarations 
DATA *game;
pthread_t thread_1;//threads

//end of gtk objects structs...


//function prototypz with uses...CORE followed by GUI functions...


//CORE functions-->

/*
Unique_Random selection of 5 numbers 
in the corresponding ranges, for unique selection,
q is ptr to Index having,
the chosen random question numbers.
*/
void unique_random(Index* q);

/*Error if file_pointer doesn't find file.*/
void file_error_function();

/*
The main algo running the game is the 
main_quiz function that gets called again and again, 
until the user wins or loses.

int main_quiz(int r,FILE*stdin);
Some major changes required like removal of getchar equivalent, 
New functions required to print text into the widget.
*/

//GUI functions-->


//The crux of the interface below...
/*
running the specific sound file designated by the 
char 
E-Entry,
Q-Question,
S-Suspence,
L-Lock,
C-Checkpoint,
W-Wrong.
*/
void sound(char z);

/*
Uses the pthread library to generate threads that runs parallely 
and plays the intro sound with incrementing the progress bar, 
and uses recursively calls sub-functions ,
at specific intervals of time to do so 
*/
void intro_level_bar (GtkToggleButton *button,gpointer user_data);

/*
Intermediate function that, fills the intro gtk_progress_bar 
progress bar1 specifically(modify this), 
returns false until float fraction = 1.0
*/
static gboolean entry_fill(gpointer user_data);

static gboolean fill(GtkProgressBar *bar,gpointer user_data);


/*Sets the intro label to the text required*/
void set_intro_label(float fraction, GtkLabel *label);

/*
Calls main screen,
hides the entry screen and 
all the other widgets, 
returns 0
*/
gboolean start_game(gpointer user_data);

/*
This restarts the game with fresh questions,
and hides all necessary windows,
reseting the progress bar.
*/
void game_restart(GtkButton* button,gpointer user_data);


//The following functions do exactly what their name suggests...
void result_screen(GtkMenuItem *button,gpointer user_data);
void show_about_devs(GtkMenuItem *menuitem, gpointer user_data);
void show_instructions(GtkMenuItem *menuitem, gpointer user_data);
void hide_instructions(GtkButton *button, gpointer user_data);
void show_audience_vote(GtkButton *button,gpointer user_data);
void hide_audience_vote(GtkButton *button,gpointer user_data);
void close_window(GtkWindow *window);
void hide_window(GtkButton *button);


/* 
************************************************************************************************************************** 
 end of function prototypes...
************************************************************************************************************************** 
*/

//main starts from here...

int main( int argc, char* argv[]) 
{ 
  //First GUI formalities...

  //Declarations
  GtkBuilder *builder;

  GError *err = NULL;
  //Initialisations or namaskar.. 
  gtk_init(&argc, &argv);
  
  //Mem Alloc
  game = g_slice_new( DATA );

  //gtk_builder_new(); is a function returning the address of the new builder.
  builder = gtk_builder_new();

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
  
  //setting up of graphics done
  //file handling part

	srand(time(0));

	file_p = fopen("KBC_QBE.bin","r");
	file_error_function();
	fread(&easy,sizeof(question_paper_30),1,file_p);

	file_p = fopen("KBC_QBM.bin","r");
	file_error_function();
	fread(&medium,sizeof(question_paper_45),1,file_p);


	file_p = fopen("KBC_QBH.bin","r");
	file_error_function();
	fread(&hard,sizeof(question_paper_30),1,file_p);

	//closing file
	fclose(file_p);
/*
	int a=main_quiz(0,stdin);
	major modification and remodelling  required to :
	*call thread to run this function itself
	*or change the way this function behaves altogether, 
	 by operating on the basis of button callbacks
	*change text of the label of the widgets of the main as well as the end_game page, 
	*call threads for music,
	*remove dependency of the value of 
*/

	// result(); develop this function



  //shows window
  gtk_widget_show(GTK_WIDGET((GtkWidget *)game->kbc_intro));
  gtk_toggle_button_set_active(game->start_game,TRUE);
  gtk_main();//runs main gtk
	
  return 0;
}

void sound(char z)
	// Note that this function can only work in some cases, its not general 
	//It's Ubuntu specific, as it is direct command on terminal.[Idk if its Linux specific.
{   
   
	switch (z)
	{
	case 'E'/*Entry*/        :  system("canberra-gtk-play -f KBC_Entry.wav");break;
	case 'Q'/*Question*/     :  system("canberra-gtk-play -f KBC_Next_question.wav");break;
	case 'S'/*Suspence*/     :  system("canberra-gtk-play -f KBC_Suspence1.wav");break;
	case 'L'/*Lock*/         :  system("canberra-gtk-play -f KBC_Lock.wav");break;
	case 'C'/*Checkpoint*/   :  system("canberra-gtk-play -f KBC_Win_question.wav");break;
	case 'W'/*Wrong*/        :  system("canberra-gtk-play -f KBC_Wrong_Ans.wav");break;

	}
}

gboolean start_game(gpointer user_data)
{
  DATA *game = user_data;

  gtk_widget_hide((GtkWidget *)game->instructions);
  gtk_widget_hide((GtkWidget *)game->about_devs);
  gtk_widget_hide((GtkWidget *)game->kbc_intro);

  gtk_window_present(game->main_screen);
  // gtk_window_fullscreen(game->main_screen);

	
	return FALSE;
}

void game_restart(GtkButton *button, gpointer user_data)
{	
	DATA *game = user_data;
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

void intro_level_bar (GtkToggleButton *button,gpointer user_data)
{
	DATA *game = user_data;

	gtk_widget_hide((GtkWidget *)button);
    gtk_widget_show((GtkWidget *)game->progress_bar);

	thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'E');
	
	gtk_progress_bar_set_fraction(game->progress_bar,0.0);

	g_timeout_add(2.3/*Interval after which function will run*/,(GSourceFunc)entry_fill/*Return gboolean FALSE to exit else wait for 2.3 milisec*/, user_data);//non-modular function,(?threads maybe?)
	g_timeout_add(1,(GSourceFunc)start_game, user_data);//23500

	pthread_join(thread_1,NULL);
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
void show_audience_vote(GtkButton *button,gpointer user_data)
{
  DATA *game = user_data;
  gtk_window_present(game->audience_vote);
  g_timeout_add(6,(GSourceFunc)fill, game->audience_vote_progress_bar);

}
void close_window(GtkWindow *window){
  gtk_window_close(window);
}

void hide_window(GtkButton *button){
  GtkWidget *widget = gtk_widget_get_toplevel(GTK_WIDGET(button));//gets parent window
  gtk_widget_hide(widget);
}
//Program CORE functions..
/*
int main_quiz(int r,FILE*stdin)
{
	int i=0;
	int response;

	if(r==0)
	{   int E[5];
		unique_random(E,5,30);//Random selection of the questions. 
		for (i=0;i<5;)
		{   
			printf("\n%d)%s\n",i+1,easy.questions[E[i]].string);
			
		 //delay(0.3); required after gtk addition
		 sound('Q');
		
			for(int j=0;j<4;j++)
			{
				delay(1);//so that options feel like they are sequencially printing
				printf("\n%d| %s\n",1+j,easy.options[dynamic_question_bank.easy_index[i]][j].string);
			}
				//sound('S');
		//simulatneous start needed
		//not sequencial
		//want it to terminate sound by the enter key, that prompts scanf();
				scanf(" %d",&response);
				sound('L');//lock
				response--;

				if (easy.correct_ans[E[i]]==response)//if(correct input)
				{
					i++;
					printf("\n Correct Answer! \n ");
					delay(1);//delay till next question
					if(i==5)
					{   printf("\n CONGRATULATIONS YOU HAVE WON Rs.10,000\n ");
						sound('C');
						return main_quiz(1,stdin);
					}
				}
				else
				{   printf("\n Wrong answer \n");
					sound('W');

					printf("\npress any char to continue\n");
					scanf(" %c",&aux);
					return 0;
				}
		}
	}
	else if(r==1)
	{   int M[5];
		unique_random(M,5,45);
		for (i=0;i<5;)
		{   
			printf("\n%d)%s\n",i+6,medium.questions[M[i]].string);
			if(i!=0)
			{
		 //delay(0.3); required after gtk addition
		 sound('Q');
		}
			for(int j=0;j<4;j++)
			{
				delay(1);
				printf("\n%d| %s\n",1+j,medium.options[M[i]][j].string);
			}
				//sound('S');
				scanf("%d",&response);
				sound('L');
				response--;

				if (medium.correct_ans[M[i]]==response)
				{
					i++;
					printf("\n Correct Answer! \n ");
					delay(1);
					if(i==5)
					{   printf("\n CONGRATULATIONS YOU HAVE WON Rs.3,20,000\n ");
						sound('C');
						return main_quiz(2,stdin);
					}
				}
				else
				{   printf("\n Wrong answer \n");
					sound('W');

					printf("\npress any char to continue\n");
					scanf(" %c",&aux);
					return 1;
				}
	}
	}

	else if(r==2)
	{   int H[5];
		unique_random(H,5,30);
		for (i=0;i<5;)
		{   
			printf("\n%d)%s\n",i+1,hard.questions[H[i]].string);
			if(i!=0)
			{
		 //delay(0.3); required after gtk addition
		 sound('Q');
		}
			for(int j=0;j<4;j++)
			{
				delay(1);
				printf("\n%d| %s\n",1+j,hard.options[H[i]][j].string);
			}
				//sound('S');
				scanf("%d",&response);
				sound('L');
				response--;

				if (hard.correct_ans[H[i]]==response)
				{
					i++;
					printf("\n Correct Answer! \n ");
					delay(1);
					if(i==5)
					{   printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.1 Cr.\n\n\n\n\n\n\npress any char to exit\n");
						scanf(" %c",&aux);
						sound('E');
					}
				}
				else
				{   printf("\n Wrong answer \n");
					sound('W');

					printf("\npress any char to continue\n");
					scanf(" %c",&aux);
					return 2;
				}
		}
	}
}
*/
/*void result()
	{
		if(a==0)
		{
			system("clear");

			printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.0\n\n\n\n\n\n\npress any char to exit\n");
			scanf(" %c",&aux);
		}
		else if(a==1)
		{
			system("clear");
		
			printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.10,000\n\n\n\n\n\n\npress any char to exit\n");
			scanf(" %c",&aux);
		}
		else if(a==2)
		{
			system("clear");
		
			printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.3,20,000.\n\n\n\n\n\n\npress any char to exit\n");
			scanf(" %c",&aux);
		}
	}*/

void unique_random(Index* q)
{	
	//Maintains a register of all questions in question bank
	static gboolean e[30];
	static gboolean m[45];
	static gboolean h[30];

	for(int i=0;i<30;i++)
		e[i] = FALSE;
	for(int i=0;i<45;i++)
		m[i] = FALSE;
	for(int i=0;i<30;i++)
		h[i] = FALSE;

	static int loop = 0;//Checks the value of the number of times this function is called.
	//q->easy_index
	 
	
		int i=0;
		
		while(i<5)
		{
			q->easy_index[i]= rand()%30;

			if(e[q->easy_index[i]] == FALSE)
			{
			   e[q->easy_index[i]] = TRUE;
				i++;
			}

			q->medium_index[i]= rand()%45;

			if(e[q->medium_index[i]] == FALSE)
			{
			   e[q->medium_index[i]] = TRUE;
				i++;
			}

			q->hard_index[i]= rand()%30;

			if(e[q->hard_index[i]] == FALSE)
			{
			   e[q->hard_index[i]] = TRUE;
				i++;
			}
		}

		if(++loop == 6)
			{
				for(int i=0;i<30;i++)
					e[i] = FALSE;
				for(int i=0;i<45;i++)
					m[i] = FALSE;
				for(int i=0;i<30;i++)
					h[i] = FALSE;
				loop  =  0;
			};
}

void file_error_function()//Error if file_pointer doesn't find file.
{
	if (file_p== NULL)
	{
		fprintf(stderr, "\nError opening file1\n");
		exit (1);
	}
}
/*
killing a bug due to thread...
void kill_thread(){
	pthread_cancel(thread_1);
	pthread_join(thread_1,NULL);
}

void exit_with_thread(GtkMenuItem *menuitem, gpointer user_data){
	kill_thread();
	gtk_main_quit();
}
*/
// gtk_button_set_label(GtkToggleButton *button,"hello");
// use this function to set label to button




















