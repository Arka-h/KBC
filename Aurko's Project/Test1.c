#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void RI(short int*p,int n)
	{
		for(int i=0;i<n; i++)
		*(p+i)=0;
	}

void U_RANDOM(int* p,int n,int L)
{ short int a[L];
    	int i=0;
	RI (a,L);
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

int main()
{
	int E[5];
	int M[5];
	int H[5];
	U_RANDOM(E,5,30);
	U_RANDOM(M,5,45);
	U_RANDOM(H,5,30);
	int i=0;
	printf("\n");
	while(i<5)
{
	printf("%d ",E[5]);
}
		printf("\n");
	while(i<10)
{
	printf("%d ",M[5]);
}
		printf("\n");
	while(i<15)
{
	printf("%d ",H[5]);
}
	return 0;
}
