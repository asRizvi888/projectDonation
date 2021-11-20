#include <stdio.h>
#include <string.h>
#include "../headers/method.h"
#include "../headers/constant.h"

void update () {
	printf("Please select an option:\n");
	printf("1. Recieve donation\n");
	printf("2. Distribute donation\n> ");

	int k;
	scanf("%d",&k);

	switch (k) {
		case 1:
			clear();
			printf("\"Recieve donation\" selected!\n");
			add();
			break;
		
		case 2:
			clear();
			printf("\"Distribute donation\" selected!\n");
			sub();
			break;
		
		default:
			clear();
			printf("Invalid option!\n");
			update();
			break;
	}
}
