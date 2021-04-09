#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
int main(int argc, char * argv[]){ 
    int delete, ch, i[26]= {0};
  while ((ch = getchar()) != EOF) 
	{
        if     (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){
        	continue;
        }

        else if(ch == '<')
		{
			ch = getchar();
			if(isalpha(ch))
			{
				push(ch);
				i[(int)ch-97]++;
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
