#include <stdio.h>
#include <stdlib.h>

int sum_array(int *arr, int start, int end) {
    if (start == end) {
        // sum of a one element array is the value of that array elem
        return arr[start];
    }
    // sum of a seq is first elem + sum of seq
    return arr[start] + sum_array(arr, start + 1, end);
}

int main(int argc, char **argv) {
    int len = atoi(argv[1]);
    int *arr = malloc(sizeof(int) * len);
    
    for (int i = 2; i < argc; i++) {
        arr[i - 2] = atoi(argv[i]);
    }

    int sum = sum_array(arr, 0, len - 1);
    free(arr);
}
