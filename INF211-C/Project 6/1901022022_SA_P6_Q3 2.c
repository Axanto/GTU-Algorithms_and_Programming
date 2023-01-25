#include <stdio.h>

#define n 15        //Since it's easy to change n to lesser sizes and check the code, I used #define

int main()
{
    int i,max,min,array[n];
    printf("\n Please enter 15 numbers ");

    for(i=0; i<n; ++i){
        printf("\n Please Enter a Number: ");
        scanf("%d", &array[i]);
    }

        max=min=array[0];           /*  In order not to find minimum as zero in the conditions below, we equate the max and min values to array[0],
                                     *  which is one of the elements in all arrays*/

        for(i=0; i<n; ++i){

            if (array[i]>=max){
            max=array[i];           // if an element bigger than max, it will be the new max

            }else if (array[i]<=min){
            min=array[i];           // if an element bigger than min, it will be the new min
            }
        }

        for(i=0; i<n; ++i){

        if (array[i]%2==0){                                     // it checks whether it is divided in two
                                                                // if it is, it's an even number
            printf("\n %d is an even number", array[i]);
        }
        else {
            printf("\n %d is an odd number", array[i]);         // if it's not ,is an odd number
        }
        }

    printf("\n Max Number is: %d", max);
    printf("\n Min Number is: %d", min);


    return 0;
}
