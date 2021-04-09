#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern char *  pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch;
  char a[100];
  char b[100];
  while ((ch = getchar()) != EOF) 
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
      continue;
	}
     else if(ch == '<')
		{
			ch = getchar();
			if(isalpha(ch))
			{
				push(ch);
				char *str;
				  int i=0;
			}
			else if(ch == '/')
			{
				ch = getchar();				
				delete = pop();	
				if(ch != delete){
                      fprintf(stderr,"NOT valid \n");
				}
            }
        }
        

        if(isEmpty()==1){
            fprintf(stdout,"Valid\n");
			int j=0;
			for(j=0;j<26;j++){
				if(i[j]>0){
					fprintf(stdout,"%c\t%d\n",(char)(j+97),i[j]);
				}
			}
			exit(0);
        }

    }
	if(isEmpty() == 0){
		fprintf(stderr,"NOT valid, stack is empty\n");
		exit(1);
	}
	exit(0);
}
