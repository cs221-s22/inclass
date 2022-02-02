#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("no string\n");
		return -1;
	}

	int count = 0;
	char *str = argv[1];
/*
	int count = 0;
	while (*str != '\0') {
		count++;  // count = count + 1

		// str++ is "pointer arithmetic"
		// the C compiler knows that str points to 1-byte chars
		// so ++ means add 1 to the pointer's value (mem reference)
		str++; // str = str + 1
	}
*/

/*
	for (count = 0; *str != '\0'; str++) {
		count++;
	}
*/


	for (; *str != '\0'; count++, str++) 
		;


	for (count = 0; str[count] != '\0'; count++)
		;

	printf("count: %d\n", count);
	return 0;
}
