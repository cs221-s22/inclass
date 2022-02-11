#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a_global_str[32];

char *my_func() {
	char arr[8] = "foobar1";
	return arr;
}

char *heap_alloc() {
	char *str = malloc(8);	// allocated an 8-byte buffer on the heap
	strncpy(str, "foobar1", 8);
	return str;
}

int main() {
	int i = 0;
	int j = 1;
	char arr[8] = "foobar1";

	printf("code: %p\n", my_func);
	printf("global: %p\n", a_global_str);
	printf("local i: %p\n", &i);
	printf("local j: %p\n", &j);

	printf("first byte of arr: %p\n", &arr[0]);
	printf("second byte of arr: %p\n", &arr[1]);

	printf("my_func returns: %s\n", my_func());
	char *ha = heap_alloc();
	printf("heap_alloc returns: %s addr: %p\n", ha, ha);
	free(ha);
}
