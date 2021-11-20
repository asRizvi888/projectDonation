#include <stdio.h>
#include <string.h>

char* cat (char str[]) {
	for (int i=0; i<strlen(str); ++i) {
		if (str[i] == ' ') {
			str[i] = '_';
		}
	}
	return str;
}
