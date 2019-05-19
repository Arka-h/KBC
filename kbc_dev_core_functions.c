#include"kbc_game.h"
char* string_1 = "Welcome to Kaun Banega Crorepati 2019";
char* string_2 = "Please read the instructions carefully before starting the game...";
/* 
************************************************************************************************************************** 
 KBC Game core functions
************************************************************************************************************************** 
*/
void delay(int number_of_milliseconds) 
{ 
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + number_of_milliseconds*1000); 
} 

void sound(char z)
	// Note that this function can only work in some cases, its not general 
	//It's Ubuntu specific, as it is direct command on terminal.[Idk if its Linux specific.
{   
   /*Use something else here*/
	switch (z)
	{
		case 'E'/*Entry*/        :  system("canberra-gtk-play -V 0.0 -f Sounds/Entry.wav");break;
		case 'Q'/*Question*/     :  system("canberra-gtk-play -V 0.0 -f Sounds/KBC_Next_question.wav");break;
		case 'S'/*Suspence*/     :  system("canberra-gtk-play -V 0.0 -f Sounds/Suspence.wav");break;
		case 'L'/*Lock*/         :  system("canberra-gtk-play -V 0.0 -f Sounds/Lock.wav");break;
		case 'C'/*Checkpoint*/   :  system("canberra-gtk-play -V 0.0 -f Sounds/KBC_Win_question.wav");break;
		case 'W'/*Wrong*/        :  system("canberra-gtk-play -V 0.0 -f Sounds/KBC_Wrong_Ans.wav");break;

	}
}


void option_reset()
{
	for(int i=0;i<4;i++)
	{
		gtk_widget_hide((GtkWidget*)game->option_[i]);
		gtk_widget_hide((GtkWidget*)game->option__[i]);
		gtk_widget_show((GtkWidget*)game->option[i]);	
	}
}

short int get_question(int n)
{
	char temp[300];
	if(n == 0)
	{
		// display_message(1);
		// delay(3000);
		// display_message(2);
		g_timeout_add(150,(GSourceFunc)gtk_label_delay_print,string_2);
	}
	if((n<5)&&(n>=0))
	{
		file_p = fopen("Files/KBC_QBE.bin","r");
		fread(&easy,sizeof(question_paper_30),1,file_p);
		file_error_function();
		
		sprintf(temp,"%d. %s",n+1,easy.questions[x.easy_index[n]].string);
		printf("\n %s",temp);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);
		
		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%c) %s",65+i,easy.options[x.easy_index[n]][i].string);
			printf("\n%s",temp);
			gtk_button_set_label((GtkButton*)game->option[i],temp);
			gtk_button_set_label((GtkButton*)game->option_[i],temp);
			gtk_button_set_label((GtkButton*)game->option__[i],temp);
			printf(" %c",65+easy.correct_ans[x.easy_index[n]]);
			
		}
		
		fclose(file_p);
		option_reset();

		return easy.correct_ans[x.easy_index[n]];
	}

	else if((n<10)&&(n>=5))//create exception for checkpoint
	{
		n-=5;
		file_p = fopen("Files/KBC_QBM.bin","r");
		fread(&medium,sizeof(question_paper_45),1,file_p);
		file_error_function();
		
		sprintf(temp,"%d. %s",n+6,medium.questions[x.medium_index[n]].string);
		printf("\n %s",temp);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);

		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%c) %s",65+i,medium.options[x.medium_index[n]][i].string);
			printf("\n%s",temp);
			gtk_button_set_label((GtkButton*)game->option[i],temp);
			gtk_button_set_label((GtkButton*)game->option_[i],temp);
			gtk_button_set_label((GtkButton*)game->option__[i],temp);
			printf(" %c",65+medium.correct_ans[x.medium_index[n]]);
		}
		
		fclose(file_p);
		option_reset();
		return medium.correct_ans[x.medium_index[n]];
	}
	else if((n<15)&&(n>=10))//create exception for checkpoint
	{
		n-=10;
		file_p = fopen("Files/KBC_QBH.bin","r");
		fread(&hard,sizeof(question_paper_30),1,file_p);
		file_error_function();
		
		sprintf(temp,"%d. %s",n+11,hard.questions[x.hard_index[n]].string);
		printf("%s",temp);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);

		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%c) %s",65+i,hard.options[x.hard_index[n]][i].string);
			printf("\n%s",temp);
			gtk_button_set_label((GtkButton*)game->option[i],temp);
			gtk_button_set_label((GtkButton*)game->option_[i],temp);
			gtk_button_set_label((GtkButton*)game->option__[i],temp);
			printf(" %c",65+hard.correct_ans[x.hard_index[n]]);
		}
		
		fclose(file_p);
		option_reset();
		return hard.correct_ans[x.hard_index[n]];
		
	}
}

void check_answer(GtkToggleButton* button,gpointer user_data)
{
	DATA*game = user_data;
	char dummy[4][9];//to run in loop
	sprintf(dummy[0],"option_1");
	sprintf(dummy[1],"option_2");
	sprintf(dummy[2],"option_3");
	sprintf(dummy[3],"option_4");

	char string[100] = "THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.";
	for(int i=0;i<4;i++)
	{
		if(strcmp(gtk_widget_get_name((GtkWidget*)button),dummy[i])==0)
		{
			// delay(500);
			gtk_widget_show((GtkWidget*)game->option_[i]);
			gtk_widget_hide((GtkWidget*)game->option[i]);
			
			
			thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'L');
			pthread_join(thread_1,NULL);
			delay(10000);
			if(correct_ans==i)
				{
				
					sprintf(string,"%s%s",string,level[current_question].money);
  					// gtk_host_label_change_display(int n);
  					change_final_screen_display(string);//silently changing money earned.
  					
					if(current_question == 14)
						{
							sprintf(string,"%s%s",string,"1,00,00,000");
							change_final_screen_display(string);
							thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'E');
							delay(2000);
							result_screen(game->withdraw,user_data);
							pthread_join(thread_1,NULL);
						}
					else
						{
							current_question++;
							next_question();
							gtk_widget_hide((GtkWidget*)game->q[current_question-1]);
  							gtk_widget_show((GtkWidget*)game->q_[current_question-1]);//tick change
						}

				}
			else 
				{
					delay(500);
					// gtk_host_label_change_display(int n)
					change_final_screen_display(string);
					result_screen(game->withdraw,user_data);
				}

		}
		else if(strcmp(gtk_widget_get_name((GtkWidget*)button),dummy[i])!=0)
		{
			gtk_widget_hide((GtkWidget*)game->option[i]);
			gtk_widget_show((GtkWidget*)game->option__[i]);
		}	
	}
	
	option_reset();
}
void next_question()
{
	correct_ans = get_question(current_question);
}

void change_final_screen_display(char* string)
{
	if((strcmp(string,"THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.")==0)&&(current_question>=0)&&(current_question<4))
	{
		thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'W');
		sprintf(string,"%s0",string);
		gtk_label_set_label((GtkLabel*)game->end_label,string);
		pthread_join(thread_1,NULL);
	}
	else if((strcmp(string,"THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.")==0)&&(current_question>4)&&(current_question<9))
	{
		thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'W');		
		sprintf(string,"%s10,000",string);
		gtk_label_set_label((GtkLabel*)game->end_label,string);
		pthread_join(thread_1,NULL);
	}
	else if((strcmp(string,"THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.")==0)&&(current_question>9)&&(current_question<14))
	{
		thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'W');		
		sprintf(string,"%s3,20,000",string);
		gtk_label_set_label((GtkLabel*)game->end_label,string);
		pthread_join(thread_1,NULL);
	}
	else if((strcmp(string,"THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.")!=0)&&(current_question==4||current_question==9))
	{
		thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'C');		
		gtk_label_set_label((GtkLabel*)game->end_label,string);
		pthread_join(thread_1,NULL);
	}
	else if((strcmp(string,"THANK YOU FOR JOINING US TODAY\nYOU HAVE WON Rs.")!=0)&&\
			(current_question!=4)&&\
			(current_question!=9)&&\
			(current_question!=14))
	{
		thread_1 = pthread_create(&thread_1,NULL,(thred_function)sound, (thred_parameter)'Q');		
		gtk_label_set_label((GtkLabel*)game->end_label,string);
		pthread_join(thread_1,NULL);
	}
}

void unique_random(Index* q)
{	
	//Maintains a register of all questions in question bank
	static gboolean e[30]={FALSE};
	static gboolean m[45]={FALSE};
	static gboolean h[30]={FALSE};
	
	static int loop = 0;//Checks the value of the number of times this function is called.	 
	
		int i=0,j=0,k=0;
		
		while(i<5)
		{
			q->easy_index[i]= rand()%30;

			if(e[q->easy_index[i]] == FALSE)
			{
			   e[q->easy_index[i]] = TRUE;
				i++;
			}
		}
		while(j<5)
		{
			q->medium_index[j]= rand()%45;

			if(e[q->medium_index[j]] == FALSE)
			{
			   e[q->medium_index[j]] = TRUE;
				j++;
			}
		}
		while(k<5)
		{
			q->hard_index[k]= rand()%30;

			if(e[q->hard_index[k]] == FALSE)
			{
			   e[q->hard_index[k]] = TRUE;
				k++;
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
			}
}
void file_error_function()//Error if file_pointer doesn't find file.
{
	if (file_p== NULL)
	{
		fprintf(stderr, "\nError opening file1\n");
		exit (1);
	}
}
//idea of killing bug by printing ^c on terminal


gboolean gtk_label_delay_print(gpointer string)
{
	char copy[300];
	static int i = 0;
	
		sprintf(copy,"%s",(char*)string);
     	*(copy+i+1)='\0';
     	i++;
     	gtk_label_set_label(game->host_label,copy);
		if(i == strlen((char*)string))
			{
				i=0;
				return FALSE;
			}
		else return TRUE;	
}
// void display_message(int n)
// {
// 	if(n==1)
// 	{
// 		g_timeout_add(200,(GSourceFunc)gtk_label_delay_print,string_1);
// 	}
// 	else if(n==2)
// 	{
		
// 	}
// }
