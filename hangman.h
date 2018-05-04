#define DICTIONARY_SIZE 10
#define WORD_SIZE 50
#define WORDS_PER_LEVEL 5

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

int visited(int index, int array[]){
	int i;
	for(i = 0; i < WORDS_PER_LEVEL; ++i){
		if(index == array[i]) return 1;
	}
	return 0;
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


    int lives = 7, match = 0, currIndex, currWordLength, i;
    int visitedIndex[5], v_indicator = 0;
    char input;

    WORD currentWord;

    srand(time(NULL));
    while(lives != 0){
    	/*randomize the dictonary index 0-9*/
    	currIndex = rand() % 10;

    	/*check if the word in the corresponding index is already solved/visited
    	  to avoid duplicates*/ 
    	while(visited(currIndex, visitedIndex) == 1){
    		currIndex = rand() % 10;
    	}

    	/*add index to visited*/
    	visitedIndex[v_indicator] = currIndex;
    	v_indicator++;

    	/*print the category of the current word*/
    	printf("\t\t\t\t %s\n", dictionary[currIndex].category);
    	
    	/*store length of the word*/
    	currWordLength = strlen(dictionary[currIndex].word);

    	/*store the current game state of the word into the variable WORD currentWord*/
    	for(i = 0; i < currWordLength; ++i){
    		if(isalpha(dictionary[currIndex].word[i])){
    			currentWord.word[i] = '_';
    		}else{
    			currentWord.word[i] = dictionary[currIndex].word[i]; //in cases of (')
    		}
    	}

    	printWord(currWordLength, currentWord.word);

    	while(match != currWordLength-1 && lives != 0){
    		int pass = 0;
    		printf("\nLives: %i | [0] Exit Game\n", lives);
	    	getchar();
	    	printf("Give me a letter: ");
	    	scanf("%c", &input);

	    	switch(input){
	    		case '0':	printf("Your score: %i. Goodbye! See you next time!\n", (*score)); 
	    					exit(0); 
	    					break;

	    		default: 
			    			/*search the letter here*/
			    			for(i = 0; i < currWordLength; ++i){
			    				if(dictionary[currIndex].word[i] == input || dictionary[currIndex].word[i] == toupper(input)){
			    					currentWord.word[i] = input;
			    					match++;
			    					pass = 1;
			    				}
			    			}

			    			printWord(currWordLength, currentWord.word);

			    			if(pass == 0){
			    				lives--;
			    			}

	    		break;
	    	}
    	}

    	(*score) += lives;
    	printf("Score: %i\n", (*score));

    	break;
    }

    exit(0);
}