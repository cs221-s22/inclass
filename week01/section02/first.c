#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	for (i = 0; i < argc; i++) {
		/* printf is a "variadic" function: it can take a variable
		   number of parameters
		   %s is a "format specifier" to print as a string
		   %d is a "format specifier" to print as a decimal number
		*/
		printf("argv[%d] is %s\n", i, argv[i]);
	}

	i = argc - 1;
	while (i >= 0) {
		printf("argv[%d] is %s\n", i, argv[i]);
		i--;
	}
	return 0;
}
