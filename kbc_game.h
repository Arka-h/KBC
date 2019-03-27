/* 
 *
 *Kbc_game_h header file for all versions of Kaun Banega Crorepati
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <time.h>
#include <pthread.h>


#define STR typedef struct 

#define thred_function void * (*)(void *)  
#define thred_parameter void * restrict   

STR
{
	int easy_index[5];
	int medium_index[5];
	int hard_index[5];
}Index;


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
	Question questions[30];    //30 questions.
	Option options[30][4];     //4 options for each question.
}question_paper_30;
								//Two sizes of Question_paper data types
STR
{
	short int correct_ans[45] ;//45 correct answers.
	Question questions[45] ;   //45 questions
	Option options[45][4] ;    //4 options for each question.
}question_paper_45;

							//global declarations.

							//end of file handling structs and global declarations...



							//GUI related data types and global declarations
STR 
{
  
  GtkWindow\
  *kbc_intro,\
  *audience_vote,\
  *instructions,\
  *number,\
  *phone_f,\
  *end_game,\
  *main_screen,\
  *about_devs;


  GtkMenuItem\
  *menu_about;


  GtkLabel\
  *intro_label,\
  *question_label,\
  *host_label;


  GtkToggleButton\
  *option[4],\
  *start_game;


  GtkButton\
  *q15,*q14,*q13,*q12,*q11,*q10,*q9,*q8,*q7,*q6,*q5,*q4,*q3,*q2,*q1,\
  *q15_,*q14_,*q13_,*q12_,*q11_,*q10_,*q9_,*q8_,*q7_,*q6_,*q5_,*q4_,*q3_,*q2_,*q1_,\
  *button_50_50,\
  *button_50_50_,\
  *button_audience_vote,\
  *button_audience_vote_,\
  *phone_a_friend,\
  *phone_a_friend_;


  GtkImage\
  *audience_cover_image,\
  *audience_option[4];


  GtkProgressBar\
  *progress_bar,\
  *audience_vote_progress_bar;

}DATA;

//GUI objects declarations 
/* 
************************************************************************************************************************** 
Allocation
************************************************************************************************************************** 
*/
FILE *file_p;
Index x;

question_paper_30* hard;
question_paper_45* medium;
question_paper_30* easy;

DATA *game;
pthread_t thread_1;//threads

/* 
************************************************************************************************************************** 
End of gtk objects structs...
************************************************************************************************************************** 
*/

//function prototypz with uses...CORE followed by GUI functions...


//CORE functions-->

/*
Unique_Random selection of 5 numbers 
in the corresponding ranges, for unique selection,
q is ptr to Index having,
the chosen random question numbers.
*/
void unique_random(Index* q);

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

void sound(char);

/*Error if file_pointer doesn't find file.*/
void file_error_function();




//GUI functions-->




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

/*
Intermediate function that, fills the audience vote gtk_progress_bar 
/
returns false until float fraction = 1.0
*/
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
void game_restart(GtkButton*button, gpointer user_data);


//The following functions do exactly what their name suggests...
void result_screen(GtkMenuItem *button,gpointer user_data);
void show_about_devs(GtkMenuItem *menuitem, gpointer user_data);
void show_instructions(GtkMenuItem *menuitem, gpointer user_data);
void hide_instructions(GtkButton *button, gpointer user_data);
void show_audience_vote(GtkButton *button,gpointer user_data);
void hide_audience_vote(GtkButton *button,gpointer user_data);
void close_window(GtkWindow *window);
void hide_window(GtkButton *button);



// end of function prototypes...

/* 
************************************************************************************************************************** 
 end of KBC Game Header
************************************************************************************************************************** 
*/
