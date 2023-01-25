#include <stdio.h>
#include <stdlib.h>
#include "my_array_library.h"

int main(void)
{
    int R,C;
    printf("Please enter the Row and Column numbers of the array:\n");
    scanf("%d %d",&R,&C);

    int arr[100][100];

    enter_elements(R,C,arr);

/*---------------------------------------------------*/

    print_elements(R,C,arr);

/*---------------------------------------------------*/

    int m,n;
    printf("\n\n mth row: ");
    scanf("%d", &m);
    printf("\n nth column: ");
    scanf("%d", &n);
    print_spesific_elements(m,n,arr);

/*------------------------------------------------------------------------------------*/

    int x;
    printf("\n Please enter a value you want to search: ");
    scanf("%d",&x);
    search_value(x,R,C,arr);

/*-------------------------------------------------------------------------------------*/

    printf("\n\n Number of non-repeated elements= %d\n", find_nonrepeateds(R,C,arr));

/*-------------------------------------------------------------------------------------*/

    printf("\n Minimum value is = %d\n", find_min(R,C,arr));

/*-------------------------------------------------------------------------------------*/

    find_max(R,C,arr);

/*-------------------------------------------------------------------------------------*/

    int B[100][100];
    printf("\n Ascending order of your matrix is:\n");
    bubblesorting(R,C,arr,B);

/*-------------------------------------------------------------------------------------*/

    int A[100][100];
    printf("\n Transpose of your matrix is:\n");
    find_transpose(R,C,arr,A);
/*-------------------------------------------------------------------------------------*/

    int comp[100][100];
    printf("\n Matrix multiplied by its transpose:\n");
    compute_products(R,C,arr,A,comp);

/*-------------------------------------------------------------------------------------*/

    check_identity(R,C,arr);

/*-------------------------------------------------------------------------------------*/

    check_symmetric(R,C,arr);

    return 0;

}

