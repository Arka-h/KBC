#include"kbc_game.h"
/* 
************************************************************************************************************************** 
 KBC Game core functions
************************************************************************************************************************** 
*/
	

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

	// file_p = fopen("KBC_QBM.bin","r");
	// file_error_function();
	// fread(&medium,sizeof(question_paper_45),1,file_p);
	// fclose(file_p);

gboolean get_question(int question_number)
{
	if((question_number<5)&&(question_number>=0))
	{
		file_p = fopen("KBC_QBE.bin","r");
		fread(easy,sizeof(question_paper_30),1,file_p);
		file_error_function();
		
		easy = (question_paper_30*)file_p;
		char temp[450];
		sprintf(temp,"%s",easy->questions[x.easy_index[question_number]].string);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);
		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%s",easy->options[x.easy_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option[question_number],temp);
			sprintf(temp,"%s",easy->options[x.easy_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option_[question_number],temp);	
		}
		
		fclose(file_p);
	}

	else if((question_number<10)&&(question_number>=5))
	{
		question_number-=5;
		file_p = fopen("KBC_QBM.bin","r");
		fread(medium,sizeof(question_paper_45),1,file_p);
		file_error_function();

		medium = (question_paper_45*)file_p;
		char temp[450];
		sprintf(temp,"%s",medium->questions[x.medium_index[question_number]].string);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);
		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%s",medium->options[x.medium_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option[question_number],temp);
			sprintf(temp,"%s",medium->options[x.medium_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option_[question_number],temp);	
		}
		
		fclose(file_p);
	}
	else if((question_number<15)&&(question_number>=10))
	{
		question_number-=10;
		file_p = fopen("KBC_QBH.bin","r");
		fread(hard,sizeof(question_paper_30),1,file_p);
		file_error_function();

		hard = (question_paper_30*)file_p;
		char temp[450];
		sprintf(temp,"%s",hard->questions[x.hard_index[question_number]].string);
		gtk_label_set_label((GtkLabel*)game->question_label,temp);
		for(int i=0;i<4;i++)
		{
			sprintf(temp,"%s",hard->options[x.hard_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option[question_number],temp);
			sprintf(temp,"%s",hard->options[x.hard_index[question_number]]->string);
			gtk_button_set_label((GtkButton*)game->option_[question_number],temp);	
		}

		fclose(file_p);
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

// void delay_print(GtkLabel*label,char *string,int milisec)
// {
// 	char* access = (char*)malloc(2*sizeof(string));
// 	for(int i=0;i<sizeof(string);i++)
// 	{
// 		access+2*i=string;
// 		*(access+2*i-1)='\0'
// 	}
// 	g_timeout_add(milisec,(GSourceFunc),)
	
// }