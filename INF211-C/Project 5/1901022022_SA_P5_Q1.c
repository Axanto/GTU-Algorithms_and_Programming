#include <stdio.h>
#include <math.h>
#define PI 3.1415

int main()
{

int n=0,limit;
double x,a,c=0; // "a" is a variable for the result of formula and "c" is the result of the whole process. In the and we're going to ask for "c" as output
int fact=1,i; //these are the variables defined for the factorial


printf("\nEnter a x value for sin(x): ");
scanf("%lf", &x);

printf("\nEnter a limit value: ");
scanf("%d",&limit);

x= x* (PI/180);

while(n<=limit) // The process will happen from zero to the limit value which is wanted from the user.
{
        for(i=1; i<=(2*n+1); ++i){ //This is a loop to find the factorial in the formula
            fact *= i;
            }
    a= pow(-1,n)* pow(x,(2*n)+1)/(fact);

    c += a;

    n++;

}

printf("\nsinx = %f \n",c);

return 0;

}
