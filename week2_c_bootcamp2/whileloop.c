#include <stdio.h>

int main() {
    
    // in while loop a is initialised before the loop
    int a = 0;

    while (a < 5)

    {
        printf ("a is equal to %d\n", a);

        // incrementor 
        a++;
    }
    printf ("I've finished the loop and a is equal to %d\n", a);

    return (0);
}