#include <stdio.h>
#include "passwords.h"

int main(int argc, char *arv[]) {
	for (int i = 0; i < 3; i++) {
		printf("passwords[%d]: %s\n", i, passwords[i]);

		char *pass = passwords[i];

		while (*pass != '\0') {
			printf("%c ", *pass);
			pass++;
		}
		printf("\n");
	}
	return 0;
}
