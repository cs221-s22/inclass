#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;

	for (i = 0; i < argc; i++) {
		// demonstrate printf variadic arguments
		// %s is a format specifier which means print the arg as a string
		// %d is a format specifier which means print the arg as a decimal number
		printf("argv[%d] is %s\n", i, argv[i]); 
	}

	i = argc - 1;
	while (i >= 0) {
		printf("argv[%d] is %s\n", i, argv[i]);
		i--;
	}
	
	return 0; // success
}
