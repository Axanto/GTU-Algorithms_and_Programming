#include <stdio.h>
#include <math.h>

int sum(int a, int b, int c, int d) // a function to add 4 numbers entered
    int sum= a+b+c+d;

    return sum;
}

int sum_of_square(int a, int b, int c, int d) // a function to add the square of 4 numbers entered
{
    int square= pow(a,2)+pow(b,2)+pow(c,2)+pow(d,2);

    return square;
}

int sum_of_cubes(int a, int b, int c, int d) // a function to add the cubes of 4 entered numbers
{
    int cubes= pow(a,3)+pow(b,3)+pow(c,3)+pow(d,3);

    return cubes;
}
int sum_of_fourths(int a, int b, int c, int d) // a function to add the fourth power of 4 numbers entered
{
    int fourths= pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4);

    return fourths;
}

int biggest(int s1, int s2, int s3, int s4) // a function to find the biggest result of the summation
{
    int i,max,array[4]={s1,s2,s3,s4}; // I've defined all sums inside the main function and wrote them here

    max=array[0];   //I equate max to the first element of array for the following condition to be properly

    for (i=0; i<4; ++i){
        if (array[i]>max) {
            max=array[i];
        }
    }

    printf("\nBiggest sum = %d", max);

    return max; // I wrote return max to give max when I call it in main function
}

int main()
{
    int a,b,c,d;
    printf("Please Enter 4 Numbers: ");
    scanf("%d%d%d%d", &a,&b,&c,&d);


    int s1= sum(a,b,c,d);
    int s2= sum_of_square(a,b,c,d);
    int s3= sum_of_cubes(a,b,c,d);
    int s4= sum_of_fourths(a,b,c,d);



    printf("\nSum of these numbers = %d\n", sum(a,b,c,d));
    printf("\nSum of square of these numbers = %d\n", sum_of_square(a,b,c,d));
    printf("\nSum of cubes of these numbers = %d\n", sum_of_cubes(a,b,c,d));
    printf("\nSum of fourth power of these numbers = %d\n", sum_of_fourths(a,b,c,d));

    biggest(s1,s2,s3,s4);

    printf("\n\n");

}

