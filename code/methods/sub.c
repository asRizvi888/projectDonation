#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/constant.h"
#include "../headers/method.h"

void sub () {
	FILE *fp1, *fp2;
	object obj[1000];
	
	char BUFFER[SIZE];
	double qt; 
	int cnt = 0, found = 0;
	char word[100];
	char path1[] = "../db/donation.txt";
	char path2[] = "../db/dist.txt";

	getchar();
	printf("Enter Donation CODE: ");
	scanf("%[^\n]s",word);
	
	fp1 = fopen(path1, "r");
	
	while(fscanf(fp1, "%[^\n] ", BUFFER) != EOF) {
		sscanf(BUFFER, "%s %s %s %d %lf",obj[cnt].name_of_supply, obj[cnt].supply_code, obj[cnt].donator, &obj[cnt].no_of_shipment, &obj[cnt].quantity);
		if (strstr(BUFFER, word) && !found) {
			printf("Enter New Quantity: ");
			scanf("%lf",&qt);
	
			if (obj[cnt].quantity < qt) {
				qt-=obj[cnt].quantity;
				printf("OOOPs! only %lf quantity available\n",qt);
				obj[cnt].quantity = 0;
			} else {
				obj[cnt].quantity-=qt;
			}
			
			fp2 = fopen(path2, "a");
			fprintf(fp2, "%-30s %-15s %-15lf\n",obj[cnt].name_of_supply, obj[cnt].supply_code, qt);
			fclose(fp2);
			found = 1;
		}
		cnt++;
	}

	(!found) ? printf("Not found!\n") : printf("Quantity Updated!\n");

	fclose(fp1);	
	remove(path1);

	fp1 = fopen(path1, "a");

	for (int i=0; i<cnt; ++i) {
		fprintf(fp1, "%-30s %-15s %-15s %-15d %-15lf\n",obj[i].name_of_supply, obj[i].supply_code, obj[i].donator, obj[i].no_of_shipment, obj[i].quantity);
	}

	fclose(fp1);
}

