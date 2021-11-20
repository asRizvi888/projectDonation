#include <stdlib.h>

void clear () {
	// 'cls' 	-> WINDOWS
	// 'clear' 	-> UNIX/LINUX 
	system("cls || clear");	// clears the screen buffer
	return;
}
