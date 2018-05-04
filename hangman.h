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


    int lives = 7, match = 0, currIndex, i;
    int visitedIndex[5], v_indicator = 0;
    char input;

    srand(time(NULL));
    while(lives != 0){
    	currIndex = rand() % 10;
    	while(visited(currIndex, visitedIndex) == 1){
    		currIndex = rand() % 10;
    	}

    	visitedIndex[v_indicator] = currIndex;
    	v_indicator++;

    	WORD currentWord = dictionary[currIndex];

    	printf("\t\t\t\t %s\n", currentWord.category);

    	for(i = 0; i < WORD_SIZE; ++i){
    		if(isalpha(currentWord.word[i])){
    			printf("_ ");
    		}else{
    			printf("%c", currentWord.word[i]); //in cases of (')
    		}
    	}
    	printf("\n");

    	printf("[0] Exit Game\n");
    	getchar();
    	printf("Give me a letter: ");
    	scanf("%c", &input);

    	switch(input){
    		case '0': printf("Your score: %i. Goodbye! See you next time!\n", (*score)); break;
    		default: /*search the letter here*/

    		break;
    	}

    	break;
    }
    


    exit(0);
}

int visited(int index, int array[]){
	int i;
	for(i = 0; i < WORDS_PER_LEVEL; ++i){
		if(index == array[i]) return 1;
	}
	return 0;
}