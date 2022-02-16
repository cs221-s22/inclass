#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passwords.h"


int main(int argc, char *argv[]) {

	for (int i = 0; i < 3; i++) {
		char *pass = passwords[i];
		printf("pass: %s\n", pass);

		char *leet = malloc(strlen(pass) + 1);
		int leet_index = 0;
		while (*pass != '\0') {
			switch (*pass) {
				case '3':
					leet[leet_index] = 'e';
					break;
				default:
					leet[leet_index] = *pass;
			}
			pass++;
			leet_index++;
		}
		leet[leet_index] = '\0';
		printf("leet: %s\n", leet);
		free(leet);

/*
		if (pass == "foobar") {
			printf("found it\n");
		}
*/
	}

	return 0;
}
