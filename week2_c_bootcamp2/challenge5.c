// write a c program which uses a while loop to have users guess a number until they get it right

#include <stdio.h>

int main(){

    int number, guess;

    number = 9;

    printf ("Guess a number: ");
    scanf ("%d", &guess);

    while (number != guess)

    {
        printf ("Incorrect\n");
        printf ("Guess a number again: ");
        scanf ("%d", &guess);
    }

    printf ("Correct\n");

return (0);
}