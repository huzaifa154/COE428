#include <stdlib.h>
#include <stdio.h>
/*this lab requires to create a statemachine that can be altereed using 6 commands
1. no commands - print out original statemachine array
2. one/zero commands - print out the corresponding value depending on input
3. change command - will modify the statemachine depending on input and will keep the current state
4. print command - this will print out current statemachine with the most recent changes
5. garbage identity command - will identify reachable and unreachable states from current states
6. delete command - will delete the unreachable states
*/

typedef struct FSM{//typedef is used to define new data type so we can define strcuture variables directly
    char stateName; // refers array state (row) to a letter (first column) 
	int var;
	int stateNum; //assigns number to the state
	int delete; // variable to delete the unreachable state
//include struct as we are implementing pointers 
	struct FSM *  nextState0;//pointer pointing to state0 (column 2) 
	struct FSM *  nextState1;//pointer pointing to state1 (column 3) 
} 
	stateMachine; 

	stateMachine state[8];//array of 8 from A-H 

void present_state(){//state[i] will correspond to the given letter (ex. state[0] = A , state[1] = B, state[2] = C , etc) and stateNum = i. When input = 0, the state will add up to the corresponding letter and same when input = 1.
     //State A
     state[0].stateName = 'A';
	 state[0].stateNum = 0;
	 state[0].nextState0 = state; //State A
	 state[0].nextState1 = state + 1; //State B
	 state[0].delete = '\0';
	 
	 //State B
	 state[1].stateName = 'B';
	 state[1].stateNum = 1;
	 state[1].nextState0 = state + 4; //State E
	 state[1].nextState1 = state + 7; //State H
     state[1].delete = '\0';
	 
	 //State C
	 state[2].stateName = 'C';
	 state[2].stateNum = 2;
	 state[2].nextState0 = state + 6; //State G
	 state[2].nextState1 = state; //State A
	 state[2].delete = '\0';
	 
	 //State D
	 state[3].stateName = 'D';
	 state[3].stateNum = 3;
	 state[3].nextState0 = state + 7; //State H
	 state[3].nextState1 = state + 6; //State G
	 state[3].delete = '\0';

	 //State E
	 state[4].stateName = 'E';
	 state[4].stateNum = 4;
	 state[4].nextState0 = state + 5; //State F
	 state[4].nextState1 = state + 3; //State D
 	 state[4].delete = '\0';

         //State F
	 state[5].stateName = 'F';
	 state[5].stateNum = 5;
	 state[5].nextState0 = state; //State A
	 state[5].nextState1 = state + 3; //State D
	 state[5].delete = '\0';
	 
	 //State G
	 state[6].stateName = 'G';
	 state[6].stateNum = 6;
	 state[6].nextState0 = state + 2; //State C
	 state[6].nextState1 = state + 5; //State F
	 state[6].delete = '\0';
	 
	 //State H
	 state[7].stateName = 'H';
	 state[7].stateNum = 7;
	 state[7].nextState0 = state + 4; //State E
	 state[7].nextState1 = state + 2; //State C
	 state[7].delete = '\0';
}

void printCommand(){//This method will print out the current state machine in an array form
       int i=0;
          for(i =0; i <8; i++){// for each state (row), it will print out the state name, next state for 0 , and next state 1 .
		    if(state[i].var!= 3){
			fprintf(stdout, "%c %c %c\n", state[i].stateName, state[i].nextState0->stateName, state[i].nextState1->stateName);
		 }
	}
}


int main (int argc, char* argv[]){
  int i, j=0;
  char command[3]; //an array created to take commands 
  present_state();
  stateMachine current_State = state[0];// starting state = A

  fprintf(stdout, "Please Input the Commands for State Machine. \n");
  fprintf(stdout, "The Starting State is: %c \n", current_State.stateName);
  
   while(j!=1){// this while loop will take inputs from what the user typed in. 
  
      for(i=0; i<=4;i++){//each input corresponds to a command[i] and stores it there
	    scanf("%c",&command[i]);//scanf is a function used to take input from user
		if (command[i] == '\n'){// if nothing is inputted, it will print out current state machine array
		   printCommand();
		   break;
		}
	  }

 //If the user enters 0 as input
	  if(command[0] == '0'){
	    fprintf(stdout, "%c\n",current_State.nextState0->stateName);// will print out nextstate0 (2nd column) of the current state
//ex. starting state= A, next state 0, will output A
		current_State = state[current_State.nextState0->stateNum];// will assign current state with the state is has been changed to
	  }
	  
	   //If the user enters 1 as input
	  if(command[0] == '1'){ //will print out nextstate1 (3rd column) of the current state
	    fprintf(stdout, "%c\n",current_State.nextState1->stateName);
//ex. starting state= A, next state 1, will output B
		current_State = state[current_State.nextState1->stateNum];// will assign current state with the state is has been changed to
	  }
	  
	  
  }
    //user inputs 'p' = print command
    if(command[0] == 'p'){// input p will print out state machine array
	    printCommand();
	  }
    //user input 'c' = change for nextstate0
	if(command[0] == 'c'){

	  if(command[2] == '0'){//for nextState0

	       if(command[4] == 'A'){
		   current_State.nextState0 = state;//the state will be equal to input 0 (column2) of the current state A
		   state[current_State.stateNum].nextState0 = state;// state will change to the corresponding statenumber of current state of nextstate0
           }	

           else if(command[4] == 'B'){
		   current_State.nextState0 = state + 1;
		   state[current_State.stateNum].nextState0 = state + 1;
           }

           else if(command[4] == 'C'){
		   current_State.nextState0 = state + 2;
		   state[current_State.stateNum].nextState0 = state + 2;
           }

           else if(command[4] == 'D'){
		   current_State.nextState0 = state + 3;
		   state[current_State.stateNum].nextState0 = state + 3;
           }

           else if(command[4] == 'E'){
		   current_State.nextState0 = state + 4;
		   state[current_State.stateNum].nextState0 = state + 4;
           }

           else if(command[4] == 'F'){
		   current_State.nextState0 = state + 5;
		   state[current_State.stateNum].nextState0 = state + 5;
           }

           else if(command[4] == 'G'){
		   current_State.nextState0 = state + 6;
		   state[current_State.stateNum].nextState0 = state + 6;
           }	

           else if(command[4] == 'H'){
		   current_State.nextState0 = state + 7;
		   state[current_State.stateNum].nextState0 = state + 7;
           }		   
	  }  
	}
	//The change for one
	if(command[0] == 'c'){

	  if(command[2] == '1'){

	       if(command[4] == 'A'){
		   current_State.nextState1 = state;//the state will be equal to input 1 (column3) of the current state A
		   state[current_State.stateNum].nextState1 = state;// state will change to the corresponding statenumber of current state of nextstate1
           }	

           else if(command[4] == 'B'){
		   current_State.nextState1 = state+1;
		   state[current_State.stateNum].nextState1 = state + 1;
           }

           else if(command[4] == 'C'){
		   current_State.nextState1 = state + 2;
		   state[current_State.stateNum].nextState1 = state + 2;
           }

           else if(command[4] == 'D'){
		   current_State.nextState1 = state + 3;
		   state[current_State.stateNum].nextState1 = state + 3;
           }

           else if(command[4] == 'E'){
		   current_State.nextState1 = state + 4;
		   state[current_State.stateNum].nextState1 = state + 4;
           }

           else if(command[4] == 'F'){
		   current_State.nextState1 = state + 5;
		   state[current_State.stateNum].nextState1 = state + 5;
           }

           else if(command[4] == 'G'){
		   current_State.nextState1 = state + 6;
		   state[current_State.stateNum].nextState1 = state + 6;
           }	

           else if(command[4] == 'H'){
		   current_State.nextState1 = state + 7;
		   state[current_State.stateNum].nextState1 = state + 7;
           }		   
	  }  
	}
	exit(0);
}
