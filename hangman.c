// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <time.h>
#include "../../sdk/dexsdk.h"
// #include "hangman.h"
#define DICTIONARY_SIZE 10
#define WORD_SIZE 50
#define WORDS_PER_LEVEL 5
#define TRUE 1
#define FALSE 0
#define start '1'
#define inst '2'
#define quit_game '0'
void banner(){
	clrscr();
	// system("clear");	//clears the visible surface of the terminal
	printf("\n");
	printf("\t##     ##    ###    ##    ##  ######   ##     ##    ###    ##    ##\n");
	printf("\t##     ##   ## ##   ###   ## ##    ##  ###   ###   ## ##   ###   ##\n");
	printf("\t##     ##  ##   ##  ####  ## ##        #### ####  ##   ##  ####  ##\n");
	printf("\t######### ##     ## ## ## ## ##   #### ## ### ## ##     ## ## ## ##\n");
	printf("\t##     ## ######### ##  #### ##    ##  ##     ## ######### ##  ####\n");
	printf("\t##     ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##   ###\n");
	printf("\t##     ## ##     ## ##    ##  ######   ##     ## ##     ## ##    ##\n");
	printf("\n");
}

void menu(char *opt){
	printf("\n");
	printf("\t\t\t  * * * * * *  * * * * * *\n");
	printf("\t\t\t  *                      *\n");
	printf("\t\t\t  *   [1]  PLAY          *\n");
	printf("\t\t\t  *   [2]  INSTRUCTIONS  *\n");
	printf("\t\t\t  *   [0]  EXIT          *\n");
	printf("\t\t\t  *                      *\n");
	printf("\t\t\t  * * * * * *  * * * * * *\n");
	printf("\t\t\t      Enter choice: ");
	opt=(char)getch();
	// getchar("%i", opt);
}

void hangman_instructions(){
	printf("\n\n");
	printf("\n\t\tThis Hangman game has 3 levels which are ZUPER EAZY, YOU WON'T ZWEAT (Easy),\n");
	printf ("\tNOT ZO EAZY (Intermediate), and NOZEBLEEDING (Difficult). Each level has 3 words that\n");
	printf("\tyou should be able to guess in order for you to win. It will be too difficult if each word\n");
	printf("\thas no definite category that's why this game has. The categories are very relevant especially\n");
	printf("\tto those who are taking and already took CMSC 125 and enthusiasts. \n");

	printf("\n\n\n\t\t\t\t\t\tLIFE and SCORING\n");
	printf("\n\t\t The player initially has 7 lives in every instance in a level. A hangman will be \n");
	printf("\tcreated if the player guessed 7 incorrect letters from each word. If the player successfully \n");
	printf("\tguessed the word then then the remaining sticks will be the player's points and it will be \n");
	printf("\tadded to the current score.\n");
	printf("\n");


}
void instructions(){
	clrscr();
	// system("clear");
	printf("\n\n");
	printf("## ##    ##   #######  ######## ########   ##       ##  ######## ######## ##  #######  ##    ##   #######\n");
	printf("## ###   ##  ##           ##    ##     ##  ##       ## ##           ##    ## ##     ## ###   ##  ##    \n");
	printf("## ####  ##  ###          ##    ##     ##  ##       ## ##           ##    ## ##     ## ####  ##  ###   \n");
	printf("## ## ## ##     ###       ##    ## ####    ##       ## ##           ##    ## ##     ## ## ## ##     ###   \n");
	printf("## ##  ####        ##     ##    ##   ##    ##       ## ##           ##    ## ##     ## ##  ####        ## \n");
	printf("## ##   ###         ##    ##    ##    ##    ##     ##  ##           ##    ## ##     ## ##   ###         ##\n");
	printf("## ##    ##   #######     ##    ##     ##    #######    ########    ##    ##  #######  ##    ##   #######\n");

	/*put instructions here*/
	hangman_instructions();


	char choice;
	printf("[1] Back to main menu | [0] Exit: ");
	choice=(char)getch();
	// getchar("%i", &choice);

	if(choice == quit_game) exit(0);
	else banner();
}


void levels(char *opt){
	printf("\t\t* * * * * * * * * * *   * * * * * * * * * * *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*    [1] ZUPER EAZY, YOU WON'T ZWEAT        *\n");
	printf("\t\t*    [2] NOT ZO EAZY                        *\n");
	printf("\t\t*    [3] NOZEBLEEDING                       *\n");
	printf("\t\t*    [0] EXIT                               *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t* * * * * * * * * * *   * * * * * * * * * * *\n");
	printf("\t\t\t      Enter choice: ");
	// getchar("%i", opt);
	opt=(char)getch();
}

typedef struct wordtag{
	char word[50];
	char category[100];
}WORD;

int visitedWord(int index, int array[]){
	int i;
	for(i = 0; i < WORDS_PER_LEVEL; ++i){
		if(index == array[i]) return TRUE;
	}
	return FALSE;
}

int visitedLetter(char input, char *pool){
	int i;
	for(i = 0; i < strlen(pool); ++i){
		if(input == pool[i] || toupper(input) == pool[i]) return TRUE;
	}
	return FALSE;
}

void printWord(int length, char *word){
	int i;
	for(i = 0; i < length; ++i){
		printf("%c ", word[i]);
	}
	printf("\n");
}

void showHangman(int lives){ //switch by remaining lives
	switch(lives){
		case 0: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||   / \\ ");
					printf("\n\t||      ");
					break;

		case 1: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||   /  ");
					printf("\n\t||      ");
					break;

		case 2: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 3: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /| ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 4: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||    | ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;
		case 5: 	
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 6: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 7: 	printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");

					break;
		default: break;
	}
}

int play(int *score, int level){
	// system("clear");
	clrscr();

	WORD dictionary[10] = {
							{"MANG TOTO", "Kainan sa Elbi"},
							{"CHICKEN JOY", "Foodz"},
							{"BOOT", "125 Terms"},
							{"FOOL", "April Fool's Day"},
							{"PHYSICAL SCIENCE", "UPLB Building"},
							{"SULYAW", "Kainan sa Elbi"},
							{"SPAGHETTI", "Foodz"},
							{"MEMORY MANAGEMENT", "125 Terms"},
							{"MISCHIEVOUS", "April Fool's Day"},
							{"BUTTERFLY BUSH", "Flowers"}
               			};

    char *levelName;
    switch(level){
    	case 1: 	levelName = "\t\t\t ZUPER EAZY, YOU WON'T ZWEAT: \0";
    				break;

    	case 2: 	levelName = "\t\t\t NOT ZO EAZY: \0";
    				break;

    	case 3: 	levelName = "\t\t\t NOZEBLEEDING: \0";
    				break;

    	default: break;
    }

    int dictVisited[5], dictIndicator = 0, i, nonalpha;
    int lives = 7, correctWordGuess = 0, wordCtr = 0, lettersGuessed = 0;
    int currentDictIndex = 0, currentWordLength = 0;

    int doesLetterPass = FALSE, inputLtrIndicator = 0, correctLtrIndicator = 0;
	char currentWord[50], input;

    srand(time(NULL));
    while(lives != 0 && wordCtr != WORDS_PER_LEVEL){
		do{
			currentDictIndex = rand() % 10;
		}while(visitedWord(currentDictIndex, dictVisited) == TRUE);

		dictVisited[dictIndicator++] = currentDictIndex;

		nonalpha = 0;
		currentWordLength = strlen(dictionary[currentDictIndex].word);
		for(i = 0; i < currentWordLength; ++i){
			if(dictionary[currentDictIndex].word[i] >= 'A' ||dictionary[currentDictIndex].word[i] <= 'Z'){
    			currentWord[i] = '_';
    		}else{
    			currentWord[i] = dictionary[currentDictIndex].word[i]; //in cases of special chars
    			nonalpha++;
    		}
		}

	    //initialize/reinitialize
	    inputLtrIndicator = 0;
	    correctLtrIndicator = 0;
	    lettersGuessed = 0;
	    lives = 7;

	   	char inputLetters[50], correctLetters[50];
	   	for(i = 0; i < 50; ++i){
	   		inputLetters[i] = '0';
	   		correctLetters[i] = '0';
	   	}

		do{
			clrscr();
			// system("clear");
			printf("%s%s\n", levelName, dictionary[currentDictIndex].category);
			printf("\t\t\t   Words Guessed for this level: %i\n\n", wordCtr);
			showHangman(lives);

			printWord(currentWordLength, currentWord);

			printf("\nLives: %i | Word Length: %i | Correct Guess(es): %i | Score: %i | [0] Exit Game\n", lives, currentWordLength-nonalpha, lettersGuessed, (*score));

			getchar(); // get/catch the extra \n from the previous printf
	    	printf("Give me a letter: ");
	    	input=(char)getch();
	    	// getch("%c", &input);
	    	printf("\n\n");

			switch(input){
				case '0':	printf("Your score: %i. Goodbye! See you next time!\n", (*score)); 
	    					exit(0); 
	    					break;

				default: 	doesLetterPass = FALSE;

							if(visitedLetter(input, correctLetters) == FALSE){
								for(i = 0; i < currentWordLength; ++i){
									if(dictionary[currentDictIndex].word[i] == input || dictionary[currentDictIndex].word[i] == toupper(input)){
										currentWord[i] = dictionary[currentDictIndex].word[i];
										doesLetterPass = TRUE;
										lettersGuessed++;
									}
								}

								if(doesLetterPass == TRUE) correctLetters[correctLtrIndicator++] = input;
							}

							if(visitedLetter(input, inputLetters) == FALSE && doesLetterPass == FALSE) {
								inputLetters[inputLtrIndicator++] = input;
								lives--;
							}
							
				break;
			}
		}while(lettersGuessed != currentWordLength-nonalpha && lives != 0);

		if(lettersGuessed == currentWordLength-nonalpha){
			(*score)+= lives;
			printWord(currentWordLength, currentWord);
			printf("\nLives: %i | Word Length: %i | Correct Guess(es): %i | Score: %i\n\n\n", lives, currentWordLength, lettersGuessed, (*score));

			wordCtr++;
		}else{
			showHangman(lives);
			printf("\nGame over. Your score is %i. Do you want to play another game? [1] Yes [0] No? ", (*score));
			getchar();
			input=(char)getch();
			// getch("%c", &input);

			switch(input){
				case start:	(*score) = 0;
							break;
				case quit_game:	printf("Bye.");
							exit(0);
							break;
				default:	(*score) = 0;
							break;
			}
		}
    }
}
int main(){
	int level, score = 0;
	char keypress =start;

	banner();
	do{
		menu(&keypress);
		
		switch(keypress){
			case start:		do{
							banner();
							levels(&level);
							if(level == 0) exit(0);
							else play(&score, level);
						}while(level != 0);
						break;
						
			case inst:		instructions();
						break;

			case quit_game:		exit(0);
						break;

			default: break;
		}

	}while(keypress != quit_game);
	
	return 0;
}