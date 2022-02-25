#include <stdio.h>
#include <limits.h>

#define NUM_ARR 4

int find_max_rec(int *arr, int len, int max) {
    if (len <= 1) {
        return arr[0];
    }
    
    int new_max = find_max_rec(arr + 1, len - 1, max);
    if (new_max > max) {
        return new_max;
    }
    return max;
}

int find_max_iter(int *arr, int len, int max) {
    for (int i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(int argc, char **argv) {
    int arr[NUM_ARR] = {1,5,3,7};
    int max = INT_MIN;
    
    int iter_result = find_max_iter(arr, NUM_ARR, max);
    printf("iterative: %d\n", iter_result);

    int rec_result = find_max_rec(arr, NUM_ARR, max);
    printf("recursive: %d\n", rec_result);

    return 0;
}
