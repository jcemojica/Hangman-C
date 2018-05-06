#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "hangman.h"

int main(){
	int choice, level, opt, score = 0;

	banner();
	do{
		menu(&choice);
		
		switch(choice){
			case 1:
				
				do{
					banner();
					levels(&level);
					if(level == 0) exit(0);
					else play(&score, level);
				}while(level != 0);
				
				break;
			case 2: break;
			case 0: exit(0); break;
			default: break;
		}

	}while(choice != 0);
	
	return 0;
}