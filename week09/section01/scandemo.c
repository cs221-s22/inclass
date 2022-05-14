#include <stdio.h>

int main(int argc, char **argv) {
    int row;
    int col;

    if (2 != fscanf(stdin, "%d %d", &row, &col)) {
        printf("bad input\n");
    } else {
        printf("scanned: %d %d\n", row, col);
    }
    
    return 0;
}
