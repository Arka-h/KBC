//segmenta1tion fault happens when, scanf reads a char and tries to store it @ the location of int..
//srand() should be declared inside the main, and not universally


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STRT typedef struct
//declaration of global filepointer
FILE *file_p;
char aux;

STRT//typedef struct
{
    char string[450];
}Question;
//Question data type.

STRT
{
    char string[200];
}Option;
//Option data type.

STRT
{
    short int correct_ans[30] ;//30 correct answers.
    Question questions[30];//30 questions.
    Option options[30][4];//4 options for each question.
}Q_paper0;

STRT
{   short int correct_ans[45] ;
    Question questions[45] ;
    Option options[45][4] ;
}Q_paper1;

Q_paper0 hard;
Q_paper1 medium;
Q_paper0 easy;

void delay(float N)//magnification of 1 second.
{
    for(long int k=0;k<N*350000000;k++);//approx 1 sec[hit and try]
}
//Note that this can only and only be used when n<L[obviously].
void U_RANDOM(int* p,int n,int L)//Unique_Random selection of n numbers from limit 0 to L , p is ptr to integer array of in numbers. 
{ static short int a[L]={0};//Shadow of the L possibilities
        int i=0;
        
        while(i<n)
        {
            *(p+i)= rand()%L;

            if(a[*(p+i)]==0)
            {
                a[*(p+i)]++;
                i++;
            }
        }
}
void ERROR1()//Error if file_pointer doesn't find file.
{
    if (file_p== NULL)
    {
        fprintf(stderr, "\nError opening file1\n");
        exit (1);
    }
}
void SOUND(char z)
	// Note that this function can only work in some cases, its not general 
	//It's Ubuntu specific, as it is direct command on terminal.[Idk if its Linux specific.
{   switch (z)
    {
    case 'E'/*Entry*/        :  system("canberra-gtk-play -f ../Sounds/KBC_Entry.wav");break;
    case 'Q'/*Question*/     :  system("canberra-gtk-play -f ../Sounds/KBC_Next_question.wav");break;
    case 'S'/*Suspence*/     :  system("canberra-gtk-play -f ../Sounds/KBC_Suspence1.wav");break;
    case 'L'/*Lock*/         :  system("canberra-gtk-play -f ../Sounds/KBC_Lock.wav");break;
    case 'C'/*Checkpoint*/   :  system("canberra-gtk-play -f ../Sounds/KBC_Win_question.wav");break;
    case 'W'/*Wrong*/        :  system("canberra-gtk-play -f ../Sounds/KBC_Wrong_Ans.wav");break;

    }
}
//The crux of the game below
 int QUIZ(int r,FILE*stdin)
{
	int i=0;
	int response;

    if(r==0)
    {   int E[5];
        U_RANDOM(E,5,30);//Random selection of the questions. 
    	for (i=0;i<5;)
    	{   
            printf("\n%d)%s\n",i+1,easy.questions[E[i]].string);
            
	     //delay(0.3); required after gtk addition
	     SOUND('Q');
	    
            for(int j=0;j<4;j++)
            {
                delay(1);//so that options feel like they are sequencially printing
                printf("\n%d| %s\n",1+j,easy.options[E[i]][j].string);
            }
                //SOUND('S');
	 	//simulatneous start needed
	 	//not sequencial
	 	//want it to terminate sound by the enter key, that prompts scanf();
                scanf(" %d",&response);
                SOUND('L');//lock
				response--;

                if (easy.correct_ans[E[i]]==response)//if(correct input)
                {
                    i++;
                    printf("\n Correct Answer! \n ");
                    delay(1);//delay till next question
                	if(i==5)
                	{   printf("\n CONGRATULATIONS YOU HAVE WON Rs.10,000\n ");
                        SOUND('C');
                        return QUIZ(1,stdin);
                	}
                }
                else
                {   printf("\n Wrong answer \n");
                    SOUND('W');

                    printf("\npress any char to continue\n");
                    scanf(" %c",&aux);
                    return 0;
                }
    }
}
    else if(r==1)
    {   int M[5];
        U_RANDOM(M,5,45);
    	for (i=0;i<5;)
    	{   
            printf("\n%d)%s\n",i+6,medium.questions[M[i]].string);
            if(i!=0)
            {
	     //delay(0.3); required after gtk addition
	     SOUND('Q');
	    }
            for(int j=0;j<4;j++)
            {
                delay(1);
                printf("\n%d| %s\n",1+j,medium.options[M[i]][j].string);
            }
                //SOUND('S');
                scanf("%d",&response);
                SOUND('L');
				response--;

                if (medium.correct_ans[M[i]]==response)
                {
                    i++;
                    printf("\n Correct Answer! \n ");
                    delay(1);
                	if(i==5)
                	{   printf("\n CONGRATULATIONS YOU HAVE WON Rs.3,20,000\n ");
                        SOUND('C');
                        return QUIZ(2,stdin);
                	}
                }
                else
                {   printf("\n Wrong answer \n");
                    SOUND('W');

                    printf("\npress any char to continue\n");
                    scanf(" %c",&aux);
                    return 1;
                }
    }
    }

    else if(r==2)
    {   int H[5];
        U_RANDOM(H,5,30);
    	for (i=0;i<5;)
    	{   
            printf("\n%d)%s\n",i+1,hard.questions[H[i]].string);
            if(i!=0)
            {
	     //delay(0.3); required after gtk addition
	     SOUND('Q');
	    }
            for(int j=0;j<4;j++)
            {
                delay(1);
                printf("\n%d| %s\n",1+j,hard.options[H[i]][j].string);
            }
                //SOUND('S');
                scanf("%d",&response);
                SOUND('L');
				response--;

                if (hard.correct_ans[H[i]]==response)
                {
                    i++;
                    printf("\n Correct Answer! \n ");
                    delay(1);
                	if(i==5)
                	{   printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.1 Cr.\n\n\n\n\n\n\npress any char to exit\n");
                        scanf(" %c",&aux);
                        SOUND('E');
                    }
                }
                else
                {   printf("\n Wrong answer \n");
                    SOUND('W');

                    printf("\npress any char to continue\n");
                    scanf(" %c",&aux);
                    return 2;
                }
        }
    }
}


 int main()
 {

    srand(time(0));
    file_p = fopen("../Files/KBC_QBE.bin","r");

    ERROR1();

    fread(&easy,sizeof(Q_paper0),1,file_p);
    fclose(file_p);
	file_p = fopen("../Files/KBC_QBM.bin","r");

    ERROR1();

    fread(&medium,sizeof(Q_paper1),1,file_p);
    fclose(file_p);

	file_p = fopen("../Files/KBC_QBH.bin","r");

    ERROR1();

    fread(&hard,sizeof(Q_paper1),1,file_p);

	//closing file
	fclose(file_p);

    printf("Welcome to Kaun Banega Crorepati\n");
	SOUND('E');
	printf("\nPress any key to continue\n");
    	scanf(" %c",&aux);

	int a=QUIZ(0,stdin);

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


    printf("\nThank You.\n");
     return 0;
}


