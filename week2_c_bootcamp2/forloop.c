#include <stdio.h>

int main() {

    // a is the loop controlled variable
    int a;

    // a is initialised to 0
    // a<5 is terminating condition test
    // a++ is the incrementor and adds 1 to the value
    for (a = 0; a < 5; a++)

    {
        printf ("a is equal to %d\n", a);

    }

    printf ("I've finished the loop and a is equal to %d\n", a);

    return (0);
}