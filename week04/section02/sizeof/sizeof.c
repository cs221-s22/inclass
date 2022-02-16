#include <stdio.h>
#include <string.h>

// This is a test program to answer Anshaj's question
/* a C style comment */
int main(int argc, char *argv[]) {
    char *foo = "foo";
    printf("sizeof foo: %ld\n", sizeof(foo));
    
    char bar[4];
    strncpy(bar, "b", sizeof(bar));
    printf("sizeof bar: %ld\n", sizeof(bar));

    for (int i = 0; i < 10; i++) {
        int someValue = 0;
        int some_value = 0;
    }
    return 0;

/*

    a whole bunch of code that I dtried but it didn't work

    no dead code
    
*/
}
