#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	char *haystack = argv[1];
	char *needle = argv[2];
	char *match = strstr(haystack, needle);
	if (match) {
		printf("found: %s\n", match);
	} else {
		printf("no match!\n");
	}
	return 0;
}
