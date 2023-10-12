// write a for loop that will print out every element in an array

#include <stdio.h>

int main(){

    int my_array[4] = {3,27,51,2};

    int number;

    for (number = 0; number < 4; number++)
    {
        printf ("%d\n",my_array[number]);
    }

    return(0);
}