#include <stdio.h>

int main(int argc, char *argv[]) {
/*
	command line parameters
	
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
*/
	int count;
	char *str = argv[1];

/*
	for (count = 0; *str != '\0'; count++) {
		str++;
	}
*/
/*
	for (count = 0; str[count] != '\0'; count++)
		;

	for (count = 0; str[count]; count++)

	count = 0;
	while (str[count]) {
		count++
	}
*/
	count = 0;
	while (str[count++]);
		
	printf("count: %d\n", count);
	return -1;
}
