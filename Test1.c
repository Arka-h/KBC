#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#define STR typedef struct 

gboolean print_strings(int n)
{
	/*Each n will be string number to be displayed in sequence*/
		int i=0;
		char string1[] = "Please read the instructions carefully before proceeding...";
		printf(" %ld \n",strlen(string1));
		
	switch(n)
	{
		case 0 :
		{
			char* string = (char*) malloc(strlen(string1));
			string = string1;

			if(*(string+i)!='/0')
				{
					printf("%c",*(string+i++));
					return TRUE;
				}
			else
				{
					i=0;
					free(string);
					return FALSE;
				}
		}break;	
	}
}

STR
{
	GtkWindow* Window;
}data;

int main( int argc, char* argv[])
{
	gtk_init(&argc, &argv);
	data* user_data;
	g_timeout_add(500,(GSourceFunc)print_strings,user_data);
	return 0;
}
