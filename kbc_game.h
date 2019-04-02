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


STR//typedef struct
{
	int easy_index[5];
	int medium_index[5];
	int hard_index[5];
}Index;

STR
{
    char money[12];
}Level;

STR
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
  *withdraw;


  GtkLabel\
  *intro_label,\
  *question_label,\
  *host_label,\
  *end_label;


  GtkToggleButton\
  *option[4],\
  *option_[4],\
  *option__[4],\
  *start_game;


  GtkButton\
  *q[15],\
  *q_[15],\
  *exit_button,\
  *button_50_50,\
  *button_50_50_,\
  *button_audience_vote,\
  *button_audience_vote_,\
  *phone_a_friend,\
  *phone_a_friend_,\
  *joker ,\
  *joker_;


  GtkImage\
  *audience_cover_image,\
  *audience_option[4],\
  *image_fore[12];


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
// question_paper_30* hard;
// question_paper_45* medium;
// question_paper_30* easy;
/*Ask why this approach doesn't work??*/
question_paper_30 hard;
question_paper_45 medium;
question_paper_30 easy;
// easy = (question_paper_30*)file_p;
DATA *game;
Level level[15];
pthread_t thread_1;//threads
int current_question;
short int correct_ans;

/* 
************************************************************************************************************************** 
End of gtk objects structs...
************************************************************************************************************************** 
*/

//function prototypz with uses...CORE followed by GUI functions...


//CORE functions-->

/*
Delays execution by some number of milliseconds.
*/
void delay(int number_of_milliseconds); 

/*
Prints on the widget at the required delay on a button
*/
void gtk_button_delay_print(GtkButton*button,char* string,int milisec);

/*
Prints on the widget at the required delay on a label
*/
void gtk_label_delay_print(GtkLabel*label,char* string,int milisec);

/*
Unique_Random selection of 5 numbers 
in the corresponding ranges, for unique selection,
q is ptr to Index having,
the chosen random question numbers.
*/
void unique_random(Index* q);

/*
Inputs the current question, and outputs the correct answer 
to that question, in the meantime,fetching the 
corresponding questions,options,correct answer from the bin files.
*/
short int get_question(int n);

/*
Passed as the callback function attached to every button;
and checks if the button matches the current question's 
correct answer, changes values accordingly
*/
void check_answer(GtkToggleButton* button,gpointer user_data);

/*
this prepares the screen for the next question and
refreshes everything to default values.
*/
void next_question(void);

/*
This function silently changes the final screen text 
as one plays the game, to update as its value as they win.
*/
void change_final_screen_display(char* string);

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


/*
Sets the intro label to the text required
*/
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

/*
calls phone a friend window and changes the icon to grey.
*/
void phone_a_friend_call(GtkButton*button ,gpointer user_data)/*new*/

/*
calls the joker to do what it has to do. 
*/
void joker_select(GtkButton*button,gpointer user_data)/*new*/


/*
To be removed after taking care of the bug of strcmp() error
*/
void option0_toggled(GtkToggleButton*button,gpointer user_data);
gboolean option_0(gpointer user_data);
void option1_toggled(GtkToggleButton*button,gpointer user_data);
gboolean option_1(gpointer user_data);
void option2_toggled(GtkToggleButton*button,gpointer user_data);
gboolean option_2(gpointer user_data);
void option3_toggled(GtkToggleButton*button,gpointer user_data);
gboolean option_3(gpointer user_data);

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
