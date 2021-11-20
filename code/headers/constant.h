#ifndef COMPONENT_H
#define COMPONENT_H

#define SIZE 100000

typedef struct {
	char name_of_supply[1000];
	char supply_code[256];
	char donator[256];
	int no_of_shipment;
	double quantity;
} object;

#endif
