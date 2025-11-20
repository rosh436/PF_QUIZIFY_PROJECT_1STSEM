#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
struct FlashCards{
	char question[500];
	char answer[100];
	int difficultyLevel;
};
struct FlashCards Maths[100];
struct FlashCards Science[100];
struct FlashCards General[100];
struct FlashCards difficultyArr[100];  //to filter out questions of similar difficulty levels
struct FlashCards *arr;
void battleMode(struct FlashCards difficultyArr[], int difficultyCount, int goalTime);
void lightningMode(struct FlashCards difficultyArr[], int difficultyCount);
void towerMode(struct FlashCards difficultyArr[], int difficultyCount, int goalTime);
int main(){
	int num,i,subjectNo,indexDel,indexEdit,editChoice,count;
	int gameChoice,mathsCount=0,scienceCount=0,generalCount=0,subChoice;
	char choice;
	int mainChoice, goalTime;   
	int *counter;   
	int difficultyChoice;
	int difficultyCount=0;
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
		       				printf("There are no flashcards to delete from");
		       				break;
						}
						printf("displaying maths flahscards\n");
						for(i=0;i<mathsCount;i++){
							printf("question %d %s\n ", i+1, Maths[i].question);
						}
						printf("What question do you want to delete: ");
						scanf("%d", &indexDel);
						indexDel--;      
						if(indexDel>=mathsCount || indexDel<0){
							break;
						}
						for(i=indexDel;i<mathsCount-1;i++){   
							Maths[i]=Maths[i+1];
						}
						mathsCount--;   
						printf("deleted successfully\n");
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
		    		arr = Maths;
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
				}
				printf("displaying the flashcard set you choose\n");
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
		    	if(subChoice==1){
		    		arr = Maths;
		    		count = mathsCount;	
				}else if(subChoice==2){
					arr = Science;
					count = scienceCount;
				}else if(subChoice==3){
					arr = General;
					count = generalCount;
				}else{
					printf("Invalid option\n");
					break;
				}
		    	printf("Choose the difficulty level: ");
		    	scanf("%d", &difficultyChoice);
		    	for(i=0;i<count;i++){
		    		if(arr[i].difficultyLevel==difficultyChoice){
		    			difficultyArr[difficultyCount]=arr[i];
		    			difficultyCount++;
					}
				}
				if(difficultyCount<5){
					printf("You do not have enough flashcards to start the game\n");
					break;
				}
				printf("      GAME MENU      \n");
	            printf("1. Lightning mode\n");
	            printf("2. Battle mode\n");
	            printf("3. Tower mode\n");
	            printf("Enter the game you want to play with these questions: ");
	            scanf("%d", &gameChoice);
	                switch(gameChoice){
			            case 1:
			            	printf("The game begins: ");
			    	        lightningMode(difficultyArr, difficultyCount);
			    	     break;
			            case 2:
							printf("Enter your goal time in seconds, if you do not want to set any, type in 0");
							scanf("%d", &goalTime);
							battleMode(difficultyArr, difficultyCount, goalTime);
				         break;
			            case 3:
				            printf("Enter your goal time in seconds, or 0 for no limit: ");
				            scanf("%d", &goalTime);
				            towerMode(difficultyArr, difficultyCount, goalTime);
				         break;
			           default:
				         printf("Please enter a valid game option.\n");	
		            }	
				break;
			case 5:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
}  
void battleMode(struct FlashCards difficultyArr[], int difficultyCount, int goalTime){
	int enemyHP , playerHP, damage=15;
	int correct,wrong,wrongCount=0,askedQues=0;
	struct FlashCards wrongQ[100];
    char notes[100][300];
    memset(notes, 0, sizeof(notes));   // initialize notes
	int index,i;
	char answer[100], noteChoice;
	enemyHP = 60;
	playerHP = 60;
	printf("You get a fifteen point hit at your enemy per question if answered right\n");
	printf("Similarily your enemey gets a fifteen point hit at you per question if answered incorrectly\n");
	printf("Stats\n");
    printf("Initial HP of enemy : %d\n", enemyHP);
    
    printf("Initial HP of player: &d\n", playerHP);

	printf("\t\t-----BATTLE MODE START-----\n");
	printf("Alloted time to complete 5 questions is %d seconds\n",goalTime);
	
	time_t start= time(NULL);
	srand(time(NULL));
	
	while(askedQues<5 && enemyHP > 0 && playerHP >0){
		index = rand() % difficultyCount;
		printf("\nQuestion%d) %s\n" , askedQues+1,difficultyArr[index].question);
		printf("Your answer: ");
		scanf(" %[^\n]", answer);
		if(strcmp(answer,difficultyArr[index].answer)==0){
			printf("Correct! , the enemy is down 15hp\n");
			enemyHP = enemyHP-damage;
		}else{
			printf("Wrong! , you are down 15hp\n");
			playerHP=playerHP-damage;
		    wrongQ[wrongCount] = difficultyArr[index];
            printf("Do you want to save a note? (y/n): ");
            scanf(" %c", &noteChoice);
            if(noteChoice == 'y'){
               printf("Enter your note: ");
               scanf(" %[^\n]", notes[wrongCount]);
            }
            wrongCount++;
		}
		printf("HP of enemy : %d\n", enemyHP);
        printf("HP of player : %d\n", playerHP);
        askedQues++;
	}
	time_t end = time(NULL);
	int timeTaken = end - start;
	printf("\nBATTLE RESULTS\n");
	if (playerHP <= 0 && enemyHP <= 0) {
        printf("Both you and the enemy have fallen! It's a tie!\n");
    } else if (playerHP <= 0) {
        printf("You died! The enemy won :/\n");
    } else if (enemyHP <= 0) {
        printf("You won!! The enemy is defeated.\n");
        if (timeTaken <= goalTime) {
            printf("And you completed it within the goal time of %d seconds!\n", goalTime);
        } else {
            printf("But you took longer than your goal time (%d seconds).\n", goalTime);
        }
    } else {
        printf("Battle ended without a clear winner.\n");
    }
    if(wrongCount > 0){
       printf("\nReview Incorrect Questions:\n");
        for(i = 0; i<wrongCount; i++){
            printf("%d) %s\n",i + 1, wrongQ[i].question);           //revision mode(displaing previous wrong questions
            if(strlen(notes[i])>0){
                printf("   Note: %s\n",notes[i]);          //displaying the saved notes for each question, if saved
            }
        }
    }
}

void lightningMode(struct FlashCards difficultyArr[], int difficultyCount){

    int score = 0,asked = 0,wrongCount = 0,streak = 0, i;
    struct FlashCards wrongQ[100];
    char notes[100][300];
    memset(notes, 0, sizeof(notes));   // initialize notes
    double timeTaken;
    time_t start, end;
    int index, maxStreak = 0;
    char answer[200], noteChoice;

    printf("        LIGHTNING ROUND        \n");
    printf("You have only 10 seconds per question.\n");
    printf("The number of questions will be 5\n");
    printf("Correct answers will give you +10 points, wrong or slow answers would result in points hehehe.\n");
    srand(time(NULL));
    while(asked < 5){
        index= rand() % difficultyCount;         //picking random questions, the same question could appear more than once 
        printf("Question %d: %s\n", asked+1, difficultyArr[index].question);
        printf("Type your answer: ");
        start = time(NULL);
        scanf(" %[^\n]", answer);
        end= time(NULL);
        timeTaken=end - start;

        if(timeTaken > 10){    //we are taking the time in seconds

            printf("Too slow! You took %.0f seconds.No points\n", timeTaken);
            streak=0;
            wrongQ[wrongCount]= difficultyArr[index];
            printf("Correct answer: %s\n", difficultyArr[index].answer);
            printf("Do you want to save a note?(y/n): ");         
            scanf(" %c", &noteChoice);

            if(noteChoice == 'y'){
                printf("Enter your note: ");
                scanf(" %[^\n]", notes[wrongCount]);
            }
            wrongCount++;
        }
        else if(strcmp(answer, difficultyArr[index].answer) == 0){
            printf("Correct!+10 points\n");
            score+=10;
            streak++;
            if(streak > maxStreak)
                maxStreak = streak;      //streak feature
        }
        else {
            printf("Wrong! Correct answer: %s\n", difficultyArr[index].answer);

            streak = 0;
            wrongQ[wrongCount] = difficultyArr[index];
            printf("Do you want to save a note? (y/n): ");
            scanf(" %c", &noteChoice);
            if(noteChoice == 'y'){
                printf("Enter your note: ");
                scanf(" %[^\n]", notes[wrongCount]);
            }
            wrongCount++;
        }
        asked++;
    }
    printf("        LIGHTNING MODE RESULTS        ");
    printf("\n     FINAL SCORE     \n");
    printf("Total Score: %d\n", score);
    printf("Max Streak: %d\n", maxStreak);

    if(wrongCount > 0){
        printf("\nReview Incorrect Questions:\n");
        for(i = 0; i<wrongCount; i++){
            printf("%d) %s\n",i + 1, wrongQ[i].question);           //revision mode(displaing previous wrong questions
            if(strlen(notes[i])>0){
                printf("   Note: %s\n",notes[i]);          //displaying the saved notes for each question, if saved
            }
        }
    }
}
void towerMode(struct FlashCards difficultyArr[], int difficultyCount, int goalTime){
	int towerHeight = 0, index, i, wrongCount = 0, asked = 0, timeTaken;
	struct FlashCards wrongQ[100];
    char notes[100][300], noteChoice;
    memset(notes, 0, sizeof(notes));   // initialize notes
	char answer[200];
	time_t start;
	time_t end;
	printf("             TOWER MODE           ");
	printf("Goal: Build a tower of height 4!\n");
	printf("Coorect answer = +1 floor\n");
	printf("Wrong answer = tower height is CUT IN HALF\n");
	if(goalTime > 0)
	   printf("You must finish within %d seconds!\n",goalTime);
	srand(time(NULL));
	start= time(NULL);
	while(towerHeight<4 && asked<3){
		index= rand() % difficultyCount;
		printf("Question %d: %s\n", asked+1, difficultyArr[index].question);
		printf("Type your answer: ");
		scanf(" %[^\n]", answer);
		if(strcmp(answer, difficultyArr[index].answer)==0){
			towerHeight++;
			printf("Correct answer, The tower grows by %d floors.\n", towerHeight);
		}
		else{
			towerHeight /= 2;
			printf("Wrong! Tower Collapes to %d floors.\n", towerHeight);
			printf("Correct answer: %s\n", difficultyArr[index].answer);
			wrongQ[wrongCount] = difficultyArr[index];
            printf("Do you want to save a note? (y/n): ");
            scanf(" %c", &noteChoice);
            if(noteChoice == 'y'){
               printf("Enter your note: ");
               scanf(" %[^\n]", notes[wrongCount]);
            }
            wrongCount++;
		}
		asked++;
	}
	end = time(NULL);
	timeTaken = end-start;
	printf("      RESULT     ");
	if(towerHeight >= 4){
		printf("You built a full tower of 4 floors!");
		if(goalTime>0){
			if(timeTaken<=goalTime){
				printf("And you did it in %d seconds!\n", goalTime);
			}
			else{
				printf("but the time taken exceeded your given time limit. Time taken: %d seconds.\n", timeTaken);
			}
		}
	}else printf("You couldnt reach 4 floors. Final height: %d\n", towerHeight);
	if(wrongCount > 0){
        printf("\nReview Incorrect Questions:\n");
        for(i = 0; i<wrongCount; i++){
            printf("%d) %s\n",i + 1, wrongQ[i].question);           //revision mode(displaing previous wrong questions
            if(strlen(notes[i])>0){
                printf("   Note: %s\n",notes[i]);          //displaying the saved notes for each question, if saved
            }
        }
    }
	
}

		    
		
		

