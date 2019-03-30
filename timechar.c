#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
#include<time.h>  //Necessary to use clock_t 

void delay(int number_of_seconds) //Function which produces desired delay in the program
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
  

int main()
{ int i,length;
  int time;
  double time_spent;//Finds the time consumed by the program 
  char string[100];
  printf("Enter delay in seconds per character and your statement:\n");
  scanf("%d ",&time);
  gets(string);
  length=strlen(string);

  clock_t start=clock();//Start clock from 0 
  for(i=0;i<length;i++)
  { printf("%c\n",string[i]);
	delay(1000*time);
	printf("%d second has passed:\n",time);
   }	
   clock_t end=clock();//Stop the clock after this statement
   time_spent+=(end-start)/(CLOCKS_PER_SEC);//Convert it to sec
   //without CLOCK_PER_SEC output would be in microseconds
   printf("%lf\n",time_spent);
   return 0;
 } 
 https://www.geeksforgeeks.org/time-delay-c/