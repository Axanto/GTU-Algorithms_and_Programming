#include <stdio.h>
#include <math.h>

struct Complex{

    float real;
    float imag;

};

typedef struct Complex Kar;

Kar add(Kar n1, Kar n2);
void Print(Kar n);
float Abs(Kar n);

Kar Multiply(Kar n1, int x);
Kar Division(Kar n2, int y);

float rreal(Kar n1, Kar n2);
float rimag(Kar n1, Kar n2);

int main()
{
    Kar n1, n2, temp, mult, divide;
    printf("For the 1st complex number \n");
    printf("Enter real and imaginary part respectively:\n");
    scanf("%f %f", &n1.real, &n1.imag);
    Print(n1);

    printf("\nFor 2nd complex number \n");
    printf("Enter real and imaginary part respectively:\n");
    scanf("%f %f",&n2.real, &n2.imag);
    Print(n2);

    temp = add(n1, n2);
    printf("Sum = ");
    Print(temp);
    printf("\nAbsolute value of the sum = %.2f\n",Abs(temp));

    int x;
    printf("\nPlease enter the number you want to multiply: ");
    scanf("%d", &x);

    mult= Multiply(n1,x);
    printf("\nMultiplication of the first complex number by %d: \n",x);
    Print(mult);

    int y;
    printf("\nPlease enter the number you want to divide: ");
    scanf("%d", &y);

    divide=Division(n2,y);
    printf("\nDivision of the second complex number by %d: \n",y);
    Print(divide);

    printf("\nReturning only real part of the sum of two Complex: %.2f", rreal(n1,n2));

    printf("\nReturning only imaginary part of the sum of two Complex: %.2f\n", rimag(n1,n2));


}

Kar add(Kar n1, Kar n2)
{
    Kar temp;

    temp.real = n1.real+n2.real; //it's sum of real parts.

    temp.imag = n1.imag+n2.imag; //it's sum of imaginary parts.

    return(temp); //by using temp, we can return real and imagianry part at the same place
}

void Print(Kar n)
{
    printf("%.1f %.1fi\n", n.real, n.imag); // it will show as complex number
}

float Abs(Kar n)
{
    return sqrt(pow(n.real,2)+pow(n.imag,2)); //adding square of real and imag part, we can find absoloute number.
}

Kar Multiply(Kar n1, int x)
{

    Kar mult;

    mult.real = x*(n1.real); // multiply by scaler
    mult.imag = x*(n1.imag); 

    return(mult); // returns the multiplied complex number 
}

Kar Division(Kar n2, int y)
{
    Kar divide;

    divide.real = (n2.real)/y; // divide by scaler
    divide.imag = (n2.imag)/y;

    return(divide); // returns the divided complex number 
}

float rreal(Kar n1, Kar n2)
{
    return (n1.real+n2.real); // Returning only real part of the sum of two Complex number
}

float rimag(Kar n1, Kar n2)
{
    return (n1.imag+n2.imag); // Returning only imaginary part of the sum of two Complex number
}
