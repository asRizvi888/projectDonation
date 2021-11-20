#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/constant.h"
#include "../headers/method.h"

void add () {
	FILE *fp;
	object obj[1000];
	
	char BUFFER[SIZE];
	double qt; 
	int cnt = 0, found = 0;
	char word[100];
	char path[] = "../db/donation.txt";

	getchar();
	printf("Enter Donation CODE: ");
	scanf("%[^\n]s",word);
	
	fp = fopen(path, "r");
	
	while(fscanf(fp, "%[^\n] ", BUFFER) != EOF) {
		sscanf(BUFFER, "%s %s %s %d %lf",obj[cnt].name_of_supply, obj[cnt].supply_code, obj[cnt].donator, &obj[cnt].no_of_shipment, &obj[cnt].quantity);
		if (strstr(BUFFER, word) && !found) {
			printf("Enter New Quantity: ");
			scanf("%lf",&qt);
	
			obj[cnt].quantity+=qt;
			obj[cnt].no_of_shipment++;

			found = 1;
		}
		cnt++;
	}

	(!found) ? printf("Not found!\n") : printf("Quantity Updated!\n");

	fclose(fp);	
	remove(path);

	fp = fopen(path, "a");

	for (int i=0; i<cnt; ++i) {
		fprintf(fp, "%-30s %-15s %-15s %-15d %-15lf\n",obj[i].name_of_supply, obj[i].supply_code, obj[i].donator, obj[i].no_of_shipment, obj[i].quantity);
	}

	fclose(fp);
}

