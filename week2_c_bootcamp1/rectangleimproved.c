#include <stdio.h>
int main() {
    //Shorthand way of defining many variables at once
    float shortside, longside, area;

    printf("Please enter short side of rectangle length: ");
    scanf("%f", &shortside);

    printf("Please enter long side of rectangle length: ");
    scanf("%f", &longside);

    area = shortside * longside;

    //.2f gives answer to 2dp
    printf("The area of the rectangle is %.2f\n", area);

return 0;
}