void banner(){
	system("clear");	//clears the visible surface of the terminal
	printf("\n");
	printf("      00   00  000  0000   00  0000000         000   000  000  0000   00\n");
	printf("     00   00  00 00  00 00  00  00            00 0 0 00  00 00  00 00  00\n");
	printf("    0000000  0000000  00  00 00  00  000     00  0  00  0000000  00  00 00\n");
	printf("   00   00  00     00  00   0 00  00    0   00     00  00     00  00   0 00\n");
	printf("  00   00  00       00  00   0000  0000000 00     00  00       00  00   0000\n");
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

int play(int *score, int level){
	
}