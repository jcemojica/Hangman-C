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
#define pause_length 50
void banner(){
	clrscr();
	// system("clear");	//clears the visible surface of the terminal
	printf("\n");
	textcolor(BLUE);
	printf("\t\t##     ##    ###    ##    ##  ######   ##     ##    ###    ##    ##\n");
	printf("\t\t##     ##   ## ##   ###   ## ##    ##  ###   ###   ## ##   ###   ##\n");
	textcolor(LIGHTBLUE);
	printf("\t\t##     ##  ##   ##  ####  ## ##        #### ####  ##   ##  ####  ##\n");
	printf("\t\t######### ##     ## ## ## ## ##   #### ## ### ## ##     ## ## ## ##\n");
	textcolor(CYAN);
	printf("\t\t##     ## ######### ##  #### ##    ##  ##     ## ######### ##  ####\n");
	printf("\t\t##     ## ##     ## ##   ### ##    ##  ##     ## ##     ## ##   ###\n");
	textcolor(LIGHTCYAN);
	printf("\t\t##     ## ##     ## ##    ## #      #  ##     ## ##     ## ##    ##\n");
	printf("\t\t##     ## ##     ## ##    ##  ######   ##     ## ##     ## ##    ##\n");
	printf("\n");
}

void menu(){
	printf("\n");
	textcolor(YELLOW);
	printf("\t\t\t\t\t\t\t  * * * * * * * * * * * * * *  *\n");
	printf("\t\t\t\t\t\t\t  *                            *\n");
	printf("\t\t\t\t\t\t\t  *         [1]  PLAY          *\n");
	printf("\t\t\t\t\t\t\t  *         [0]  EXIT          *\n");
	printf("\t\t\t\t\t\t\t  *                            *\n");
	printf("\t\t\t\t\t\t\t  * * * * * *  * * * * * * * * *\n");
	textcolor(CYAN);
	printf("\t\t\t\t\t\t\t           Enter choice: ");
	// choice=(char)getch();
	// getchar("%i", opt);
}

void hangman_instructions(){
	delay(pause_length);
	printf("\n\n");
	textcolor(LIGHTBLUE);
	printf("\n\t\tThis Hangman game has 3 levels which are ZUPER EAZY, YOU WON'T ZWEAT (Easy),NOT ZO EAZY (Intermediate), and NOZEBLEEDING (Difficult). Each level has 3 words that you should be able to guess in order for you to win. It will be too difficult if each word has no definite category that's why this game has. The categories are very relevant especially to those who are taking and already took CMSC 125 and enthusiasts. \n");
	textcolor(YELLOW);
	printf("\n\n\n\t\t\t\t\t\t\t\t\tLIFE and SCORING\n");                                                                      

	textcolor(LIGHTBLUE);
	printf("\n\t\t The player initially has 7 lives in every instance in a level. A hangman will be created if the player guessed 7 incorrect letters from each word. If the player successfully guessed the word then then the remaining sticks will be the player's points and it will be added to the current score.\n");
	printf("\n");


}
void instructions(){
	clrscr();
	clrscr();
	delay(pause_length);
	textcolor(YELLOW);
	printf("\n\n");
	printf("\t\t\t                         ''~``\n");
	printf("\t\t\t                        ( o o )\n");
	printf("\t\t\t+------------------.oooO--(_)--Oooo.------------------+\n");
	printf("\t\t\t|                                                     |\n");
	printf("\t\t\t|                                                     |\n");
	printf("\t\t\t|                 I N S T R U C T I O N S             |\n");
	printf("\t\t\t|                                                     |\n");
	printf("\t\t\t|                    .oooO                            |\n");
	printf("\t\t\t|                    (   )   Oooo.                    |\n");
	printf("\t\t\t+---------------------\ (----(   )--------------------+\n");
	printf("\t\t\t                       \_)    ) /\n");
	printf("\t\t\t                             (_/\n");
	/*put instructions here*/
	

	hangman_instructions();
		
}


void levels(){
	instructions();
	delay(pause_length);
	delay(pause_length);
	delay(pause_length);
	delay(pause_length);
	delay(pause_length);
	printf("\n");
	textcolor(CYAN);
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t\t*    [1] ZUPER EAZY, YOU WON'T ZWEAT        *\n");
	printf("\t\t\t\t\t\t*    [2] NOT ZO EAZY                        *\n");
	printf("\t\t\t\t\t\t*    [3] NOZEBLEEDING                       *\n");
	printf("\t\t\t\t\t\t*    [0] EXIT                               *\n");
	printf("\t\t\t\t\t\t*                                           *\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * *\n");
	textcolor(LIGHTBLUE);
	printf("\t\t\t\t\t\t\t\t      Enter choice: ");
	// getchar("%i", opt);
	// levels=(char)getch();
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
		case 0: 	textcolor(RED);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||   / \\ ");
					printf("\n\t||      ");
					break;

		case 1: 	textcolor(LIGHTRED);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||   /  ");
					printf("\n\t||      ");
					break;

		case 2: 	textcolor(DARKGRAY);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /|\\");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 3: 	textcolor(CYAN);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||   /| ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 4: 	textcolor(MAGENTA);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||    | ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;
		
		case 5: 	textcolor(LIGHTMAGENTA);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||    O ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 6: 	textcolor(GREEN);
					printf("\n\t||===== ");
					printf("\n\t||    | ");
					printf("\n\t||    | ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					printf("\n\t||      ");
					break;

		case 7: 	textcolor(LIGHTGREEN);
					printf("\n\t||===== ");
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
    	case '1': 	levelName = "\t\t\t ZUPER EAZY, YOU WON'T ZWEAT: \0";
    				break;

    	case '2': 	levelName = "\t\t\t NOT ZO EAZY: \0";
    				break;

    	case '3': 	levelName = "\t\t\t NOZEBLEEDING: \0";
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
			if((dictionary[currentDictIndex].word[i] >= 'A' ||dictionary[currentDictIndex].word[i] <= 'Z') && dictionary[currentDictIndex].word[i] != ' '){
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
			textcolor(CYAN);
			printf("%s%s\n", levelName, dictionary[currentDictIndex].category);
			textcolor(YELLOW);
			printf("\t\t\t   Words Guessed for this level: %i\n\n", wordCtr);
			showHangman(lives);
			textcolor(YELLOW);
			printWord(currentWordLength, currentWord);
			textcolor(LIGHTCYAN);
			printf("\nLives: %i | Word Length: %i | Correct Guess(es): %i | Score: %i | [0] Exit Game\n", lives, currentWordLength-nonalpha, lettersGuessed, (*score));

			// getch(); // get/catch the extra \n from the previous printf
			textcolor(CYAN);
	    	printf("Give me a letter: ");
	    	input=(char)getch();
	    	// getch("%c", &input);
	    	printf("\n\n");

			switch(input){
				case quit_game:	
							textcolor(YELLOW);
							printf("Your score: %i. Goodbye! See you next time!\n", (*score)); 
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
			textcolor(YELLOW);
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
	int score = 0;
	char keypress =start;
	char level;

	banner();
	do{
		menu();
		keypress=(char)getch();
		
		if(keypress==start){
		do{
			if(keypress==start){
				levels();
				level=(char)getch();
				if (level == quit_game) exit(0);
				else play(&score,level);
			}
		} while (keypress != quit_game);
		}
		
	
	}while(keypress != quit_game);
	
	return 0;
}