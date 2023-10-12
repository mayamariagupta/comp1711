// write a c program using a loop to print 100 to 0, going down in 5s

#include <stdio.h>

int main(){

    int number;

    for (number = 100; number > -1; number-=5)
    {
        printf ("%d\n", number);
    }

    return(0);
}