// write a c program using a loop to print 0 to 50, going up by 2s

#include <stdio.h>

int main(){

    int number;

    for (number = 0; number < 51; number+=2)
    {
        printf ("%d\n", number);
    }

    return(0);
}