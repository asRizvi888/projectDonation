#include <stdio.h>
#include <string.h>
#include "../headers/constant.h"
#include "../headers/method.h"

void search () {
	object obj;

	FILE *fp;
	fp = fopen("../db/donation.txt", "r");

	char BUFFER[1000];
	int found = 0;
	char word[100];

	getchar();
	printf("Enter Donation CODE to search: ");
	scanf("%[^\n]s",word);
	
	while(fscanf(fp, "%[^\n] ", BUFFER) != EOF) {
		if (strstr(BUFFER, word)) {
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("Not found!\n");
	} else {
		sscanf(BUFFER, "%s %s %s %d %lf",obj.name_of_supply, obj.supply_code, obj.donator, &obj.no_of_shipment, &obj.quantity);
		
		printf("Name of Supply: %s\n",obj.name_of_supply);
		printf("Supply Code: %s\n",obj.supply_code);
		printf("Donator : %s\n",obj.donator);
		printf("No of Shipment: %d\n",obj.no_of_shipment);
		printf("No of Quantity: %lf\n",obj.quantity);
	}
	
	fclose(fp);	
}
