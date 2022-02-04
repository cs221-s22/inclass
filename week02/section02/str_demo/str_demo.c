#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

#if 0
	char *haystack = argv[1];
	char *needle = argv[2];

	char *match = strstr(haystack, needle);
	if (match != NULL) {
		printf("%s\n", match);
	} else {
		printf("not found!\n");
	}
	return 0;
#endif

	char buf[8];
	// unbounded memory copy creating a buffer overflow
	// strcpy(buf, argv[1]);

	strncpy(buf, argv[1], sizeof(buf) - 1);
	printf("buf: %s\n", buf);


	char *pc = "string"; 
	strncpy(pc, argv[1], 7 - 1);
	printf("pc: %s\n", pc);
	return 0;
}
