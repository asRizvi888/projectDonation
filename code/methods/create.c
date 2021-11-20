#include <stdio.h>
#include <string.h>
#include "../headers/constant.h"
#include "../headers/method.h"

void create () {
	object obj;
	FILE *fp;
	fp = fopen("../db/donation.txt", "a");
	
	// take user input
	getchar();
	printf("Name of supply\t :");
	scanf("%[^\n]",obj.name_of_supply);
	fflush(stdin);

	getchar();
	printf("Supply Code\t :");
	scanf("%[^\n]",obj.supply_code);

	getchar();
	printf("Donator\t\t :");
	scanf("%[^\n]",obj.donator);

	getchar();
	
	printf("No of Shipment\t :");
	scanf("%d",&obj.no_of_shipment);

	printf("Quantity(million):");
	scanf("%lf",&obj.quantity);

	fprintf(fp, "%-30s %-15s %-15s %-15d %-15lf\n",cat(obj.name_of_supply), cat(obj.supply_code), cat(obj.donator), obj.no_of_shipment, obj.quantity);
	
	printf("Added to FILE successfully!!!\n");
	fclose(fp);
}
