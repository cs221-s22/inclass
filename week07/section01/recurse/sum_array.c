#include <stdio.h>
#include <stdlib.h>

int sum_array(int *arr, int start, int end) {
    if (start == end) {
        // base case: sum of one-element array is itself
        return arr[start];
    }

    // recursive case: walk start forward to decompose array
    return arr[start] + sum_array(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
    int len = atoi(argv[1]);
    int *arr = malloc(len * sizeof(int));
    for (int i = 2; i < argc; i++) {
        arr[i - 2] = atoi(argv[i]);
    }

    int sum = sum_array(arr, 0, len - 1);
    printf("sum: %d\n", sum);
    free(arr);
    return 0;
}
