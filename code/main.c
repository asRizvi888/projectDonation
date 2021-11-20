#include <stdio.h>
#include "./headers/method.h"
#include "./headers/constant.h"

int main (int argc, char argv[]) 
{
	char option, key;

	do {
		menu();
		scanf("%c",&key);

		switch (key) {
			case '1':				// creates new inventory
				clear();
				create();
			break;

			case '2':				// update donation quantities
				clear();
				update();
			break;
			
			case '3':
				clear();			// search for queries
				search();
			break;
			
			case '4':
				clear();
				sort();
				printf("Check \"dist.txt\" FILE for sorted List view.\n");
			break;
			
			case '0':
				clear();
				printf("Exiting...\n");
			break;

			default:
				printf("Invalid entry!!!\n");
				break;
		} getchar();	
		
		printf("Do you want to continue?(Y/N)\n> ");
		scanf("%c",& option);
		getchar();
		clear();
	} while (option != 'n' && option != 'N');
	
	return 0;
}
