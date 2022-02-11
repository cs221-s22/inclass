#include <stdio.h>
#include <stdlib.h>

int global_thing = 0;

char * make_chars(int nchars) {
	return malloc(nchars);
}

int main(int argc, char **argv) {
	int local_thing = 1;

	char arr[4] = "foo";

	printf("foo: %p (%ld)\n", arr, (long) arr);
	
	printf("code: %p\n", make_chars);

	printf("global_thing: %p\n", &global_thing);

	printf("local_thing: %p\n", &local_thing);

	char *heap_block = make_chars(32);
	printf("first byte in heap: %p\n", &heap_block[0]);
	free(heap_block);
	printf("after free: %p\n", &heap_block[0]);
	return 0;
}
