#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_MAKE 32

enum color {
    white = 0,
    gray,
    black,
    red,
    green,
};

struct car {
    char make[MAX_MAKE];
    int seats;
    enum color car_color;
};

void populate_car(char *make, struct car *pcar) {
    size_t i; 
    for (i = 0; i <= strlen(make); i++) {
        pcar->make[i] = make[i];
    }
    pcar->seats = 2;
    pcar->car_color = red;
}

bool write_struct(char *fname, struct car *pcar) {
    FILE *fp = fopen(fname, "w");
    if (!fp) {
        return false;
    }

    char *tmp = malloc(MAX_MAKE * 2);
    if (!tmp) {
        return false;
    }

    snprintf(tmp, MAX_MAKE * 2, "%s,%d\n", pcar->make, pcar->seats);

    size_t len = strlen(tmp);
    size_t nwritten = fwrite(tmp, 1, len, fp);
    if (nwritten != len) {
        return false;
    }

    fclose(fp);
    free(tmp);

    return true;
}

int main(int argc, char *argv[]) {
    struct car my_car;

    populate_car(argv[1], &my_car);

    if (!write_struct("car.txt", &my_car))
        return -1;

    return 0;
}
