#include <stdio.h>

int main(int argc, char *argv[]) {
	int i = 0;
	// sizeof returns the size in bytes of the given variable
	printf("size of int = %ld\n", sizeof(i));

	long l = 0;
	printf("size of long = %ld\n", sizeof(l));

	char c = 'x';
	printf("size of char = %ld\n", sizeof(c));

	return 0;
}
