#include <stdio.h>

void switch_demo(char ch) {
	switch (ch) {
		case 'x':
			printf("got an x\n");
			break;
		default:
			printf("got a %c\n", ch);
	}
}

int main(int argc, char **argv) {
	char ch = argv[1][0];
	switch_demo(ch);
	return 0;
}
