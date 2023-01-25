#include <stdio.h>

void swap(int x, int y) // A function to swap values of 2 numbers
{
    int temp = x; // I have defined a temporary element to x

    x=y;           // Because when i defined y to x

    y=temp;        // So again, I can define the value of x to y

    printf("\n After swapping process;\n First number is: %d\n Second Number is: %d\n",x,y);

}


int main()
{
    int x,y;
    printf("\n Please enter a number: "); // I've asked the first value from the user
    scanf("%d", &x);

    printf("\n Please enter a second number: "); // I've asked the second value from the user
    scanf("%d", &y);

    swap(x,y); // I've called swap function
}
