#include <stdio.h>  // provide a declaration for printf

int main(int argc, char *argv[]) {
	/* check to see if any arguments were provided */
	if (argc == 0) {
		printf("hello world\n");
	}
	return 0; // success
}
