#include <stdio.h>


int main()
{
    int matrix[5][5]; // I defined 5 x 5 matirx
    int i,j;          //i for row, j for column

    printf("Enter elements of matrix \n");

        for (i=0; i<5; ++i) //it increases row count and continue after all the column values are entered
        {
            for (j=0; j<5; ++j){ // while the row count is steady, it increases the number of columns one by one

            printf("\n[%d][%d] element of matrix: ", i,j);
            scanf("%d", &matrix[i][j]); // it wants values inside the matrix from the user
            }

        }

        printf("\n Your matrix is:\n");

        for(i=0;i<5;i++)        // The same process as above but this one prints it as matrix shape
        {
            for(j=0;j<5 ;j++)
                                // I did not use curly braces because then it prints every value one under the other

            printf("% 4d",matrix[i][j]);
            printf("\n");

        }

        printf("\n Lower Triangular matrix is: \n");

        for (i=0; i<5; ++i)
        {
            printf("\n");                           // it switches to the bottom line to show each row

            for(j=0; j<5; ++j){

                if(j<=i){
                printf("%4d", matrix[i][j]);       /*  In cases where the number of columns is greater than the number of rows,
                                                    *  by printing zero, a triangle shape is obtained on the bottom side of the matrix with the inputs.*/
                }else{
                printf("%4d",0);
                }
            }
        }

        printf("\n\n");

        printf("\n Upper Triangular matrix is: \n");

        for (i=0; i<5; ++i)
        {
            printf("\n");

            for(j=0; j<5; ++j){

                if(i<=j){
                printf("%4d", matrix[i][j]);        /*  In cases where the number of rows is greater than the number of columns,
                                                     *  by printing zero, a triangle shape is obtained on the top side of the matrix with the inputs.*/

                }else{
                printf("%4d",0);
                }

            }
        }

     printf("\n\n");

return 0;
}
