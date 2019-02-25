//segmenta1tion fault happens when, scanf reads a char and tries to store it @ the location of int..
//srand() should be declared inside the main, and not universally
  
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//declaration of global filepointer
FILE *file_p;
     short int E[5];
     short int M[5];
     short int H[5];
//rand()
char q;


typedef struct question
{
    char string[450];
}Question;
//Question data type
typedef struct option
{
    char string[200];
}Option;
//Option data type.
typedef struct basic_structure0
{
    short int correct_ans[30] ;//30 correct answers.
    Question questions[30];//30 questions.
    Option options[30][4];//4 options for each question.
}Q_paper0;

typedef struct basic_structure
{   short int correct_ans[45] ;
    Question questions[45] ;
    Option options[45][4] ;
}Q_paper1;

Q_paper0 hard;
Q_paper1 medium;
Q_paper0 easy;


void ERROR1()
{
    if (file_p== NULL)
    {
        fprintf(stderr, "\nError opening file1\n");
        exit (1);
    }
}

 int QUIZ(int r,FILE*stdin)
{	int i=0;
	int response;
    if(r==0)
    {
    	for (i=0;i<5;)	
    {		printf("\n%d)%s\n",i+1,easy.questions[E[i]].string);



            for(int j=0;j<4;j++)

            {

                printf("\n%d| %s\n",1+j,easy.options[E[i]][j].string);

            }

                scanf("%d",&response);
				response--;

                if (easy.correct_ans[E[i]]==response)

                {	i++;
                	if(i==5)
                	return QUIZ(1,stdin);}

                else

                {return 0;}

    }
    }
    else if(r==1)
    { 
    for (i=0;i<5;)	
    {printf("\n%d)%s\n",i+6,medium.questions[M[i]].string);



            for(int j=0;j<4;j++)

            {

                printf("\n%d| %s\n",1+j,medium.options[M[i]][j].string);

            }

                scanf("%d",&response);response-=1;

                if (medium.correct_ans[M[i]]==response)

                {	i++;
                	if(i==5)
                	return QUIZ(2,stdin);}
                else
                {return 1;}

    }
    }
    else if(r==2)
    { 
    for (i=0;i<5;)	
    {printf("\n%d)%s\n",i+11,hard.questions[H[i]].string);

            for(int j=0;j<4;j++)
            {
                printf("\n%d| %s\n",1+j,hard.options[H[i]][j].string);
            }
                scanf("%d",&response);response-=1;
                if (hard.correct_ans[H[i]]==response)
                {	i++;
                	if(i==5)
                	return 2;}
                else
                {return 1;}
    }
    }

}

void RANDOM()
{
    for(int i=0;i<5;i++)
 	{
        E[i] = rand()%30;
 	    M[i] = rand()%45;
 	    H[i] = rand()%30;
  	}
}


 int main()
 {
    time_t t ;
srand((unsigned) time(&t));
    file_p = fopen("KBC_QBE.bin","r");
    
    ERROR1();
    
    fread(&easy,sizeof(Q_paper0),1,file_p);
    
    RANDOM();
    
	file_p = fopen("KBC_QBM.bin","r");
    
    ERROR1();
    
    fread(&medium,sizeof(Q_paper1),1,file_p);
    
	
	file_p = fopen("KBC_QBH.bin","r");
   
    ERROR1();
    
    fread(&hard,sizeof(Q_paper1),1,file_p);
    
	//closing file
	fclose(file_p);
	int a=QUIZ(0,stdin);
	
	if(a==0)
	{
		printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.0\n\n\n\n\n\n\npress any char to exit\n");scanf("%c",&q);
	}
	else if(a==1)
	{
		printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.10,000\n\n\n\n\n\n\npress any char to exit\n");scanf("%c",&q);
	}
	else if(a==2)
	{
		printf("THANK YOU FOR JOINING US TODAY\n\nYOU HAVE WON Rs.1Cr.\n\n\n\n\n\n\npress any char to exit\n");scanf("%c",&q);
	}
    
    

    printf("\nThank You.\n");
     return 0;
 }
