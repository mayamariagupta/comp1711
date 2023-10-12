// write a c program using a loop to print every multiple of 11 up to 1000

#include <stdio.h>

int main(){

    int number;

    for (number = 11; number < 1001; number+=11)
    {
        printf ("%d\n", number);
    }

    return(0);
}