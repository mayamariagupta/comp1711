// write a c program using a loop to print 1 to 10, going up by 1s

#include <stdio.h>

int main(){

    // creating the variable number
    int number;

    // number is initialised to 1
    // incrementor ++ adds 1 each time the loop runs
    for (number = 1; number < 11; number++)
    {
        // %d is the decimal integer format specifier
        printf ("%d\n", number);
    }

    return(0);
}