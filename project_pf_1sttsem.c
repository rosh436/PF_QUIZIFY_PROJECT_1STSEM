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

int main(){
	int num,i,subjectNo,indexDel,indexEdit,editChoice;
	int gameChoice,mathsCount=0,scienceCount=0,generalCount=0,subChoice;
	char choice;
	int mainChoice;   // changed from char to int
	struct FlashCards{
		char question[500];
		char answer[100];
		int difficultyLevel;
	};
	struct FlashCards Maths[100];
	struct FlashCards Science[100];
	struct FlashCards General[100];
	struct FlashCards *arr;   //this will point to subjects in the struct (maths/science/general)
	int *counter;   
	printf("WELCOME TO QUIZIFY\n");
	printf("Store Flashcards to start playing fun games!\n ");
	while(1){
		printf("Do you want to\n");
		printf("1 - Store flashcards\n");
		printf("2 - Delete a flashcard\n");
		printf("3 - Edit a flashcard\n");
		printf("4 - play a game\n");
		printf("5 - exit\n");
		scanf("%d", &mainChoice);
		
		switch(mainChoice){
			case 1:
				printf("Enter the number of questions you want to input right now: ");
		        scanf("%d",&num);
		        printf("What subject of flashcards do you want to access:\n ");
		        printf("(1:Maths, 2:Science, 3:GeneralKnowledge)\n");
		        scanf("%d", &subjectNo);
		
		        switch(subjectNo){
			       case 1:
			    	   for(i=0;i<num;i++){
			             printf("Enter your question: ");
			             scanf(" %[^\n]" , Maths[mathsCount].question);
			             printf("Enter the answer to the question: ");
			             scanf(" %[^\n]" ,  Maths[mathsCount].answer);
			             printf("Enter the difficulty level of this question: ");
			             scanf(" %d", &Maths[mathsCount].difficultyLevel);
			             mathsCount++;
		             }
		            break;
		           case 2:
		        	   for(i=0;i<num;i++){
		    	    	 printf("Enter your question: ");
		    	    	 scanf(" %[^\n]", Science[scienceCount].question);
		    	    	 printf("Enter the answer to the question: ");
		    	    	 scanf(" %[^\n]", Science[scienceCount].answer);
		    	    	 printf("Enter the difficulty level of this question: ");
		    	    	 scanf("%d", &Science[scienceCount].difficultyLevel);
		    	    	 scienceCount++;
			         }
			        break;
			       case 3:
			    	    printf("\t\tGeneral Knowledge\n");
				        printf("\n");
				        for(i=0;i<num;i++){
		    		     printf("Enter your question: ");
		    		     scanf(" %[^\n]", General[generalCount].question);
		    		     printf("Enter the answer to the question: ");
		    		     scanf(" %[^\n]", General[generalCount].answer);
		    		     printf("Enter the difficulty level of this question: ");
		    		     scanf("%d", &General[generalCount].difficultyLevel);
		    		     generalCount++;
			         }
			        break;       
		       }
		       break;
		    case 2:
		       	printf("Which subject do you want to delete from? ");
		       	printf("(1:Maths, 2:Science, 3:GeneralKnowledge)\n");
		       	scanf("%d", &subChoice);
		       	switch(subChoice){
		       		case 1:
		       			if(mathsCount==0){
		       				printf("There are no flashcards to delete.");
		       				break;
						}
						printf("displaying maths flahscards\n");
						for(i=0;i<mathsCount;i++){
							printf("question %d: %s\n ", i+1, Maths[i].question);
						}
						printf("What question do you want to delete: ");
						scanf("%d", &indexDel);
						indexDel--;      
						if(indexDel>=mathsCount || indexDel<0){
							break;
						}
						for(i=indexDel;i<mathsCount-1;i++){   
							Maths[i]=Maths[i+1];                       //shift the array so that the deleted value in the index must be occupied by the value in the next index
						}
						mathsCount--;          
						printf("deleted successfully");
				    break;
				    case 2:
				    	if(scienceCount==0){
				    		printf("There are no flashcards to delete from");
						}
						printf("displaying science flashcards\n");
						for(i=0;i<scienceCount;i++){
							printf("question %d\n%s\n", i+1,Science[i].question);
						}
						printf("What question do you want to delete");
						scanf("%d",&indexDel);
						indexDel--;
						if(indexDel>=scienceCount || indexDel<0){
							break;
						}
						for(i=indexDel;i<scienceCount-1;i++){
							Science[i]=Science[i+1];
						}
						scienceCount--;
						printf("deleted successfully");
					break;
					case 3:
						if(generalCount==0){
							printf("There are no flashcards to delete from");
						}
						printf("dispalying general knowledge flashcards\n");
						for(i=0;i<generalCount;i++){
							printf("question %d\n%s\n", i+1,General[i].question);
						}
						printf("What question do you want to delete: ");
						scanf("%d", &indexDel);
						indexDel--;
						if(indexDel>=generalCount || indexDel<0){
							break;
						}
						for(i=indexDel;i<generalCount-1;i++){
							General[i]=General[i+1];
						}
						generalCount--;
						printf("deleted successfully");
						break;
		       	break;
		        }
		       	break;
		    case 3:
		       	printf("What subject do you want to edit? ");
		    	printf("(1:Maths, 2:Science, 3:GeneralKnowledge)\n");
		    	scanf("%d", &subChoice);
		    	if(subChoice==1){
		    		arr = Maths;               // this will point arr to the Maths flashcard array so we can edit it using a single pointer
		    		counter = &mathsCount;
				}
				else if(subChoice==2){
					arr = Science;
					counter = &scienceCount;
				}
				else if(subChoice==3){
					arr = General;
					counter = &generalCount;
				}
				else{
					printf("Invalid choice");
					break;
				}
				if(*counter==0){
					printf("There are no flashcards stored to be edited");
					return 0;
				}
				printf("displaying the flashcard set, you choose\n");
				for(i=0;i< *counter;i++){
					printf("Question %d: \n%s\n",i+1,arr[i].question);
				}
				printf("Which flahscard do you want to edit: ");
				scanf("%d", &indexEdit);
				indexEdit--;
				if(indexEdit>*counter || indexEdit<0){
					printf("flashcard number does not exist");
					return 0;
				}
				printf("Choose what to edit\n");
				printf("1-only the question\n");
				printf("2-only the answer\n");
				printf("3-only the difficulty level\n");
				printf("4-all three variables\n");
				scanf(" %d", &editChoice);
				switch(editChoice){
					case 1:
						printf("Question you want to edit: %s\n",arr[indexEdit].question);
						printf("Enter new question: ");
						scanf(" %[^\n]", arr[indexEdit].question);
						break;
					case 2:
						printf("Answer you want to edit: %s\n", arr[indexEdit].answer);
					    printf("Enter the new answer: ");
					    scanf(" %[^\n]", arr[indexEdit].answer);
					    break;
					case 3:
						printf("Difficulty level that you want to alter: %d\n", arr[indexEdit].difficultyLevel);
						printf("Set the new difficuly level: ");
						scanf(" %[^\n]", &arr[indexEdit].difficultyLevel);
						break;
					case 4:
						printf("Question you want to edit: %s\n",arr[indexEdit].question);
						printf("Enter new question: ");
						scanf(" %[^\n]", arr[indexEdit].question);
						printf("Answer you want to edit: %s\n", arr[indexEdit].answer);
					    printf("Enter the new answer: ");
					    scanf(" %[^\n]", arr[indexEdit].answer);
					    printf("Difficulty level that you want to alter: %d\n", arr[indexEdit].difficultyLevel);
						printf("Set the new difficuly level: ");
						scanf(" %[^\n]", &arr[indexEdit].difficultyLevel);
						break;
					default:
						printf("Invalid selection");
				}
				break;	
		    case 4:
		       	printf("What subject do you want to test? ");
		    	printf("(1:Maths, 2:Science, 3:GeneralKnowledge)\n");
		    	scanf("%d",&subChoice);
		    	if(subChoice==1&&mathsCount<5){
		    		printf("You do not have enough flashcards to start the game ");
		    		return 0;
				}else if(subChoice==2&&scienceCount<5){
					printf("You do not have enough flashcards to start the game ");
					return 0;
				}else if(subChoice==3&&generalCount<5){
					printf("You do not have enough flashcards to start the game ");
					return 0;
				}else{
					printf("      GAME MENU      \n");
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
				break;
			case 5:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
}  

