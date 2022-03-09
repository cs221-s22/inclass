#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(char *word, int start, int end) {
    if (start >= end) {
        // a single letter is said to be a palindrome of itself
        return true;
    }
    if (word[start] != word[end]) {
        // no match
        return false;
    }

    // recursive case decomposes word for next match
    return palindrome(word, start + 1, end - 1);
}

int main(int argc, char *argv[]) {
    char *word = argv[1];

    bool is_pal = palindrome(word, 0, strlen(word) - 1);
    printf("palindrome: %d\n", is_pal);
    return 0;
}
