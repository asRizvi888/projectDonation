#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/method.h"
#include "../headers/constant.h"

void sort () {
	FILE *fp;	
	char BUFFER[10000];
	int cnt = 0;

	object obj[1000], temp;

	fp = fopen("../db/dist.txt", "r");
	
	while(fscanf(fp, "%[^\n] ", BUFFER) != EOF) {
		sscanf(BUFFER, "%s %s %lf",obj[cnt].name_of_supply, obj[cnt].supply_code, &obj[cnt].quantity);
		++cnt;
	}

	fclose(fp);

	remove("../db/dist.txt");
	
	// bubble sort
	for (int i=0; i<cnt-1; ++i) {
		for (int j=0; j<cnt-i-1; ++j) {
			if (obj[j].quantity < obj[j+1].quantity) {
				temp = obj[j];
				obj[j] = obj[j+1];
				obj[j+1] = temp;
			}
		}
	}

	// overwrite in FILE
	fp = fopen("../db/dist.txt", "a");
	
	for (int k=0; k<cnt; ++k) {
		fprintf(fp, "%-30s %-15s %-15lf\n",obj[k].name_of_supply, obj[k].supply_code, obj[k].quantity);
	}

	fclose(fp);
}
