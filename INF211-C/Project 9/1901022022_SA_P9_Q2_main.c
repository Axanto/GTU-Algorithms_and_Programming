#include <stdio.h>
#include <stdlib.h>
#include "1901022022_SA_P9_Q2_2DARRAYDIVISION.H"

int main()
{

float arr[][3]= {{2.6, 7.8, 8.4}, {12.2 , 4, 32}, {42, 11 , 9}}; 			/* I defined a existing 2D array (the first dimension may be omitted)*/

int m=3, n=3; 			/* to send the values to the function properly, i termed the values as m and n*/

printf("Original view of array is:\n\n");

int i,j;
float *p=&arr;
for(i=0; i<m; ++i)
{
	for(j=0; j<n; ++j){
	
	printf("%6.1f", *((p+i*n)+j));
}
printf("\n");
}

printf("\n View of the array divided by 2 is:\n\n");
ArrayDivision((float *)arr,m,n);			 /* to call a function by reference, i sent initial adress of array*/

return 0;
}

