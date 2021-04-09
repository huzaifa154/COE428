#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();


int main(int argc, char * argv[])
{
  int ch,delete;
  while ((ch = getchar()) != EOF) 
	{
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
	
	else if(ch == '<')//once it checks "<", it will check to see if a character is displayed or "/" is displayed
		{
			ch = getchar();
			if(isalpha(ch))// if it is a character, will push the character
			{
				push(ch); 
			}
			else if(ch == '/')//if it is a "/", means pop
			{
				ch = getchar();				
				delete = pop();				
				
				 

				if(delete != ch)// if character doesnt equal character being popped, output error
				{
					fprintf(stderr,"NOT valid \n"); 
					exit(1); 
				}
				else 
				{
					fprintf(stdout,"Valid \n"); 
					exit(0); 
				}
			}
		}
	}
	
	if(isEmpty()== 0)// checks to see if stack is empty or not
	{
		fprintf(stdout,"Valid\n");
		exit(0); 
		
	}
	else 
	{
		fprintf(stderr,"NOT valid, stack is empty\n");
		exit(1);  
    
    }

 
  exit(0);
}
