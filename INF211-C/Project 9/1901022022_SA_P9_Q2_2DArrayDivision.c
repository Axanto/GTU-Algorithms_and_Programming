#include <stdio.h>
#include "1901022022_SA_P9_Q2_2DARRAYDIVISION.H"

void ArrayDivision(float *ptr, int r, int c) /* I defined a pointer that is going to receive the address of the array */
{
	int i,j;
	
	for(i=0; i<r; ++i)  
	{
		for(j=0; j<c; ++j){
		
		printf("%6.1f", (*((ptr+i*c)+j)/2));	/* I wrote a code that is going to divide a function by 2 when array moves to the next element*/
											/* "*c" is only for finishing one row and move on another row so i is multiplied by c */
 	}
		printf("\n"); 				/* to bring array matrix view */
}
}
