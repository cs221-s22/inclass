#include <stdio.h>
#include <stdlib.h>

char *make_chars() {
	char chars[32] = "foobar";
	return chars;
}

int main() {
	printf("chars: %s\n", make_chars());
	return 0;
}
