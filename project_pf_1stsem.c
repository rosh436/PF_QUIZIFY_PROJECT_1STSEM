/* edit delete create set of flashcards of different subjects 
	shuffling sets of arrays so u get diff questions each time
	user gets to choose difficulty level
	review questions answered incorectly
	user promptes to enter goal time 
	streak count of how many answers answered correctly in a row
	saving notes on question that the user will be allowed to view later */
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <ctype.h>
	
main(){
		int num,i,subjectNo;
		int gameChoice;
		char choice;
		struct FlashCards{
			char question[500];
			char answer[100];
			int difficultyLevel;
		};
		struct FlashCards Maths[100];
		struct FlashCards Science[100];
		struct FlashCards General[100];
		printf("WELCOME TO QUIZIFY\n");
		printf("Store Flashcards to start playing fun games!\n ");
		while(1){
		    printf("Do you want to store flashcards?(y/n)");
		    scanf(" %c", &choice);
		    if(choice=='y'){
			    printf("Enter the number of questions you want to input right now: ");
		        scanf("%d",&num);
		        printf("What subject of flashcards do you want to access:\n ");
		        printf("(1:Maths, 2:Science, 3:GeneralKnowledge)\n");
		        scanf("%d", &subjectNo);
		
		       switch(subjectNo){
			       case 1:
			    	   for(i=0;i<num;i++){
			             printf("Enter your question: ");
			             scanf(" %[^\n]" , Maths[i].question);
			             printf("Enter the answer to the question: ");
			             scanf(" %[^\n]" ,  Maths[i].answer);
			             printf("Enter the difficulty level of this question: ");
			             scanf(" %d", &Maths[i].difficultyLevel);
		                 }
		                break;
		           case 2:
		        	   for(i=0;i<num;i++){
		    	    	 printf("Enter your question: ");
		    	    	 scanf(" %[^\n]", Science[i].question);
		    	    	 printf("Enter the answer to the question: ");
		    	    	 scanf(" %[^\n]", Science[i].answer);
		    	    	 printf("Enter the difficulty level of this question: ");
		    	    	 scanf("%d", &Science[i].difficultyLevel);
				         }
				        break;
			       case 3:
			    	    printf("\t\tGeneral Knowledge\n");
				        printf("\n");
				        for(i=0;i<num;i++){
		    		     printf("Enter your question: ");
		    		     scanf(" %[^\n]", General[i].question);
		    		     printf("Enter the answer to the question: ");
		    		     scanf(" %[^\n]", General[i].answer);
		    		     printf("Enter the difficulty level of this question: ");
		    		     scanf("%d", &General[i].difficultyLevel);
				         }
				        break;
		       }
		       printf("      GAME MENU      \n");    //Choose a game to play with the questions you have entered for the earlier chosen subject
		       printf("1. Sudden death\n");
		       printf("2.      \n");
		       printf("3.      \n");
		       printf("Enter the game you want to play with these questions: ");
		       scanf("%d", &gameChoice);
		       switch(gameChoice){
				    case 1:
				    	//function name
				    	break;
				    case 2:
					    //function name
					    break;
				    case 3:
					    //function name
					    break;
				    default:
					    printf("Please enter a valid game option.\n");	
			   }
		    }
		    else if(choice=='n'){
		    	printf("Exiting the game/program. THANKS FOR PLAYING.");
			    return 0;      //end the game/program
		    }
	
		}
		
		
   
		
	
}

