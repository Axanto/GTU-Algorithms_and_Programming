#include <stdio.h>
#include <stdlib.h>
#include "1901022022_SA_P9_Q3_2DArrayLibrary.h"

int main(void)
{
    int R,C;
    printf("Please enter the Row and Column numbers of the array:\n");
    scanf("%d %d",&R,&C);	/* I get a row and column information from the user */

    int arr[20][20]; /* Max row and column number which can be taken from the user */

    enter_elements(R,C, (int *)arr);	/* I sent the initial adress of array to the funtion */



    print_elements(R,C, (int *)arr);	/* I sent the initial adress of array to the funtion */

printf("\n---------------------------------------------------");

    int m,n;
    printf("\n\n mth row: ");
    scanf("%d", &m); 					/* This one gets row information requested by the user */
    printf("\n nth column: ");
    scanf("%d", &n);					/* This one gets column information requested by the user */
    print_spesific_elements(m,n, (int *)arr,C);		/* In addition, the information of the maximum number of columns is sent. */    
printf("\n----------------------------------------------------");

    int x;
    printf("\n Please enter a value you want to search: ");
    scanf("%d",&x);
    search_value(x,R,C, (int *)arr);
    
printf("\n----------------------------------------------------");

	printf("\n\n Number of non-repeated elements= %d\n", find_nonrepeateds(R,C,(int *)arr)); /* it prints number of non-repeating numbers */
	

printf("\n----------------------------------------------------");
	
    printf("\n Minimum value of array = %d\n", find_min(R,C, (int *) arr)); /* it calls function and takes minimum info */

printf("\n----------------------------------------------------");

    find_max(R,C, (int *) arr);

printf("\n----------------------------------------------------");

int bubble[20][20];
printf("\n Descending order of yout matrix is:\n");
bubblesorting(R,C, (int *)arr, (int *) bubble);


printf("\n----------------------------------------------------");

    int A[20][20];		/* I have defined another array in order not to spoil original */
    printf("\n Transpose of your matrix is:\n");	
    find_transpose(R,C, (int *)arr, (int *)A);
    
printf("\n----------------------------------------------------");

    int comp[20][20]; 	/* I have defined another array to print out the multiplied matrices */
    printf("\n Matrix multiplied by its transpose:\n");
    compute_products(R,C,(int *)arr, (int *) A, (int *)comp);
    
printf("\n----------------------------------------------------");

    check_identity(R,C,(int *)arr);

printf("\n----------------------------------------------------");

    check_symmetric(R,C, (int *)arr);


return 0;
}
