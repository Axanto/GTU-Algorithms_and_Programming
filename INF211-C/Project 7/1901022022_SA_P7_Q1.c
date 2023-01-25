#include <stdio.h>
#include <stdlib.h>

void equivalency(int grade) /* I declared the void function just because it will print letter grades
                             * It means there is no return type in this function.
                             * it will check grades and print its equivalence letter */

{
    if (grade<0 || grade>100)
        printf("An invalid number was entered, Please enter a valid number! \n");

    else if (90<=grade && grade<=100)
        printf("Your grade is equivalent to \"AA\" \n");

    else if (80<=grade && grade<=89)
        printf("Your grade is equivalent to \"BA\" \n");

    else if(75<=grade && grade<=79)
        printf("Your grade is equivalent to \"BB\" \n");

    else if(70<=grade && grade<=74)
        printf("Your grade is equivalent to \"CB\" \n");

    else if(65<=grade && grade<=69)
        printf("Your grade is equivalent to \"CC\" \n");

    else if(60<=grade && grade<=64)
        printf("Your grade is equivalent to \"DC\" \n");

    else if(50<=grade && grade<=59)
        printf("Your grade is equivalent to \"DD\" \n");

    else if(40<=grade && grade<=49)
        printf("Your grade is equivalent to \"FD\" \n");

    else
        printf("Your grade is equivalent to \"FF\" \n");


}


int main()
{
    int g;

    printf("Please Enter Your Grade in Percent: "); // I asked the user to enter a value
    scanf("%d", &g);

    printf("\n");

    equivalency(g); // We are calling the function defined above
}
