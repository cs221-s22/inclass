#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 32

enum toy {
    ball = 0,
    bone,
    kong,
    tug,
};

struct dog {
    char name[MAX_NAME];
    int age;
    enum toy fav_toy;
};

char *populate_struct(char *name, struct dog *pdog) {
#if 1
    size_t i;
    for (i = 0; i < strlen(name); i++) {
        pdog->name[i] = name[i];
    }
    pdog->name[i] = '\0';
#else 
    strncpy(pdog->name, name, MAX_NAME - 1);
#endif
    pdog->age = 3;
    pdog->fav_toy = ball;

    char *tmp = malloc(MAX_NAME * 2);
    snprintf(tmp, MAX_NAME * 2, "%s,%d\n", pdog->name, pdog->age);
    return tmp;
}

int main(int argc, char *argv[]) {
    struct dog fido;

    FILE *fp = fopen("output.txt", "w");
    if (!fp) {
        printf("failed to open output.txt\n");
        exit(-1);
    }

    char *line = populate_struct(argv[1], &fido);
    size_t nwritten;
#if 0
    nwritten = fwrite(line, 1, strlen(line), fp);
#else
    nwritten = fprintf(fp, "%s,%d\n", fido.name, fido.age);
#endif

    if (nwritten != strlen(line)) {
        printf("write error\n");
        exit(-1);
    }

    fclose(fp);
    free(line);
    
    return 0;
}
