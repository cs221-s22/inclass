#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(char *word, int start, int end) {
    if (start >= end) {
        // a 1 char string is said to be a palindrome
        return true;
    }
    if (word[start] != word[end]) {
        return false;
    }
    return palindrome(word, start + 1, end - 1);
}

int main(int argc, char **argv) {
    char *word = argv[1];

    int is_pal = palindrome(word, 0, strlen(word) - 1);
    
    printf("palindrome: %d\n", is_pal);
    return 0;
}
