#define DICTIONARY_SIZE 10
#define WORD_SIZE 50
#define WORDS_PER_LEVEL 5
#define TRUE 1
#define FALSE 0

void banner(){
	system("clear");	//clears the visible surface of the terminal
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

void menu(int *opt){
	printf("\n");
	printf("\t\t\t  * * * * * *  * * * * * *\n");
	printf("\t\t\t  *                      *\n");
	printf("\t\t\t  *   [1]  PLAY          *\n");
	printf("\t\t\t  *   [2]  INSTRUCTIONS  *\n");
	printf("\t\t\t  *   [0]  EXIT          *\n");
	printf("\t\t\t  *                      *\n");
	printf("\t\t\t  * * * * * *  * * * * * *\n");
	printf("\t\t\t      Enter choice: ");
	scanf("%i", opt);
}

void instructions(int *opt){
	printf("## ##    ##   #######  ######## ########   ##       ##  ######## ######## ##  #######  ##    ##   #######\n");
	printf("## ###   ##  ##           ##    ##     ##  ##       ## ##           ##    ## ##     ## ###   ##  ##    \n");
	printf("## ####  ##  ###          ##    ##     ##  ##       ## ##           ##    ## ##     ## ####  ##  ###   \n");
	printf("## ## ## ##     ###       ##    ## ####    ##       ## ##           ##    ## ##     ## ## ## ##     ###   \n");
	printf("## ##  ####        ##     ##    ##   ##    ##       ## ##           ##    ## ##     ## ##  ####        ## \n");
	printf("## ##   ###         ##    ##    ##    ##    ##     ##  ##           ##    ## ##     ## ##   ###         ##\n");
	printf("## ##    ##   #######     ##    ##     ##    #######    ########    ##    ##  #######  ##    ##   #######\n");

	/*instructions*/
	/*exit*/
}

void levels(int *opt){
	printf("\t\t* * * * * * * * * * *   * * * * * * * * * * *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t*    [1] ZUPER EAZY, YOU WON'T ZWEAT        *\n");
	printf("\t\t*    [2] NOT ZO EAZY                        *\n");
	printf("\t\t*    [3] NOZEBLEEDING                       *\n");
	printf("\t\t*    [0] EXIT                               *\n");
	printf("\t\t*                                           *\n");
	printf("\t\t* * * * * * * * * * *   * * * * * * * * * * *\n");
	printf("\t\t\t      Enter choice: ");
	scanf("%i", opt);
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
	system("clear");

	WORD dictionary[10] = {
							{"Mang Toto", "Kainan sa Elbi"},
							{"Chicken joy", "Foodz"},
							{"boot", "125 Terms"},
							{"fool", "April Fool's Day"},
							{"Physical Science", "UPLB Building"},
							{"Sulyaw", "Kainan sa Elbi"},
							{"Spaghetti", "Foodz"},
							{"memory management", "125 Terms"},
							{"mischievous", "April Fool's Day"},
							{"butterfly bush", "Flowers"}
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
			if(isalpha(dictionary[currentDictIndex].word[i])){
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
			system("clear");
			printf("%s%s\n", levelName, dictionary[currentDictIndex].category);
			printf("\t\t\t   Words Guessed for this level: %i\n\n", wordCtr);
			showHangman(lives);

			printWord(currentWordLength, currentWord);

			printf("\nLives: %i | Word Length: %i | Correct Guess(es): %i | Score: %i | [0] Exit Game\n", lives, currentWordLength-nonalpha, lettersGuessed, (*score));

			getchar(); // get/catch the extra \n from the previous printf
	    	printf("Give me a letter: ");
	    	scanf("%c", &input);
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
			printf("\tGame over\n");
		}
    }
}