#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *fname = argv[1];
	char *contents = argv[2];

	FILE *f = fopen(fname, "w");
	if (!f) {
		printf("failed to open %s\n", fname);
		return -1;
	}

	int nwritten = fwrite(contents, 1, strlen(contents), f);
	printf("wrote this many bytes: %d\n", nwritten);

	fclose(f);
	return 0;
}
