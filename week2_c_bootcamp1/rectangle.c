#include <stdio.h>
int main() {
    int shortside;
    int longside;
    int area;

    printf("Please enter short side of rectangle length: ");
    scanf("%d", &shortside);

    printf("Please enter long side of rectangle length: ");
    scanf("%d", &longside);

    area = shortside * longside;

    printf("The area of the rectangle is %d\n", area);

return 0;
}