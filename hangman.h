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
	printf("\t\t* [1] ZUPER EAZY, YOU WON'T ZWEAT           *\n");
	printf("\t\t* [2] NOT ZO EAZY                           *\n");
	printf("\t\t* [3] NOZEBLEEDING                          *\n");
	printf("\t\t* [0] EXIT                                  *\n");
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

void printWord(int currWordLength, char *word){
	int i;
	for(i = 0; i < currWordLength; ++i){
		printf("%c ", word[i]);
	}
	printf("\n");
}

int play(int *score, int level){
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

    system("clear");           			
    switch(level){
    	case 1: printf("\t\t\t ZUPER EAZY, YOU WON'T ZWEAT\n"); break;
    	case 2: printf("\t\t\t NOT ZO EAZY\n"); break;
    	case 3: printf("\t\t\t NOZEBLEEDING\n"); break;
    	default: break;
    }


    /*
    *	lives = number of chances
	*	guessed = counter for correctly guessed letters for the current word
	*	currIndex = index of the current word from the dictionary for the current level
	*	currWordLength = length of the current word
	*	wordsGuessed = counter for the words already guessed
	*	nonalpha = counter for non-alpha character such as space and '
	*	wordCtr = counter for how many words have already been involved where solved or not
	*
	*	visitedIndex[] = stores the indices of words already used
	*	v_indicator = position indicator for visitedIndex
	*
	*	input = allotted for the user's input
	*
	*	currentWord = where the word's game state will be stored (as in _ and stuff)
    */

    int lives = 7, guessed = 0, currIndex, currWordLength, wordsGuessed = 0, i, nonalpha = 0;
    int visitedIndex[5], v_indicator = 0, wordCtr;
    char input;

    WORD currentWord;

    srand(time(NULL));
    while(lives != 0 && wordCtr != 5){

    	currIndex = rand() % 10; //randomize from 0-9

    	while(visitedWord(currIndex, visitedIndex) == TRUE){ //continuously randomize if currIndex is in visitedIndex
    		currIndex = rand() % 10;
    	}

    	visitedIndex[v_indicator] = currIndex; //add currIndex to visitedIndex
    	v_indicator++;

    	printf("\t\t\t\t %s\n", dictionary[currIndex].category);
    	
    	currWordLength = strlen(dictionary[currIndex].word);

    	/*store the current game state of the word into the variable WORD currentWord*/
    	for(i = 0; i < currWordLength; ++i){
    		if(isalpha(dictionary[currIndex].word[i])){
    			currentWord.word[i] = '_';
    		}else{
    			currentWord.word[i] = dictionary[currIndex].word[i]; //in cases of (')
    			nonalpha++;
    		}
    	}

    	printWord(currWordLength, currentWord.word);


    	/*
		*	pass = value would be 0 or 1; 1 if the current input has been matched
		*	
		*	lettersGuessed[] = array where the letters inputted by user are stored
		*						ex. word to be guessed is "food", user inputted z -> meaning -1 in life
		*							when he inputs z again in the next try, it wouldn't do anything to it
		*	guessIndicator = position indicator for lettersGuessed
		*
		*	correctLetters[] = array where the letters correctly guessed are stored
		*	correctIndicator = position indicator for correctLetters
    	*/

    	int pass = 0, guessIndicator = 0, correctIndicator = 0;
    	char lettersGuessed[50], correctLetters[50];
    	
    	while(guessed != currWordLength-nonalpha && lives != 0){
    		pass = 0;

    		printf("\nLives: %i | Word Length: %i | Guessed: %i | [0] Exit Game\n", lives, currWordLength-nonalpha, guessed);
	    	getchar(); //get/catch the extra \n from the previous printf
	    	printf("Give me a letter: ");
	    	scanf("%c", &input);

	    	switch(input){
	    		case '0':	printf("Your score: %i. Goodbye! See you next time!\n", (*score)); 
	    					exit(0); 
	    					break;

	    		default: 
			    			/*search the letter here*/
			    			for(i = 0; i < currWordLength-nonalpha+1; ++i){
			    				if(dictionary[currIndex].word[i] == input || dictionary[currIndex].word[i] == toupper(input)){
			    					currentWord.word[i] = dictionary[currIndex].word[i];
			    					pass = 1;
			    					if(visitedLetter(input, correctLetters) == FALSE) guessed++;
			    				}
			    			}

			    			if(visitedLetter(input, correctLetters) == FALSE)
			    				correctLetters[correctIndicator++] = input;
			    			
			    			if(visitedLetter(input, lettersGuessed) == FALSE && pass == 0){
			    				lettersGuessed[guessIndicator++] = input;
			    				lives --;
					    	}

			    			printWord(currWordLength, currentWord.word);
	    		break;
	    	}
    	}

    	(*score) += lives;
    	printf("Score: %i\n", (*score));

    	if(guessed == currWordLength){
    		wordsGuessed++;
    	}

    	wordCtr++;

    	//reset life
    	lives = 7;
    }
}