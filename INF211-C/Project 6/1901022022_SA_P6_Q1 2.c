#include <stdio.h>

int main()
{

    int i, x, divisor, counter;

    printf("Please Enter size of Array: ");
    scanf("%d", &x);                          //Taking array size from user

    int array[x];                             //after taking the size, we define the array

    for (i=0; i<x; ++i)                       //it takes inputs from 0 to size of array
    {
        printf("\n Please Enter a Number: ");
        scanf("%d", &array[i]);

        counter=0;          /*  to work code properly for every value inside of array,
                             * I added a counter which is going to be zero before every value's "prime number" check */

        if (array[i]>=2)    /*  If the value we entered is 2 or bigger than 2,
                             *  it will check the prime number, otherwise it will print "it is not a prime number". */
        {
            for(divisor=2; divisor<array[i]; ++divisor)     /*  It's continue the loop until divisor equal to array[i]
                                                             *  This loop checks every value from 2 to array[i]
                                                             *  if the mode is zero for a number less than array[i], It will increase counter*/
            {
                if (array[i]%divisor==0) /* if the array divisible by divisor without remainder,
                                          * it will increase counter. */
                {
                    counter++;
                }

            }

            if (counter==0){   /* if the counter is equal to zero,
                                * it has not a multiplier except one and itself so it's a prime number. */

            printf("\n %d is a prime number\n",array[i]);
            }
            else {             /* if the counter not equal to zero anymore,
                                * it has multiplier except one and itself so it's not a prime number. */

            printf("\n %d is not a prime number\n",array[i]);
            }

        }else printf("\n %d is not a prime number\n",array[i]); // Numbers under the zero are not a prime number

    }

    return 0;
}
