#include <stdio.h>
#include "1901022022_SA_P9_Q3_2DArrayLibrary.h"	

/* I used the fucntions where are defined in the header file */

void enter_elements(int R, int C, int *ptr){ 		/*The function recieve the array as pointer*/

int i,j;
    for(i=0; i<R; ++i){

        for(j=0; j<C; ++j){
        	
            printf("Enter [%d][%d] element of array: ", i+1, j+1);
            scanf("%d", ((ptr+i*C)+j));				/* ptr is the initial adress here */
            										/* I get the elements from the user by increasing the adress. */ 

        }
    }
}

void print_elements(int R, int C, int *ptr){	/*The function recieve the array as pointer*/
	
	int i,j;
    for(i=0; i<R; ++i){
            printf("\n");
        for(j=0; j<C; ++j){
                printf("%4d", *((ptr+i*C)+j));	/* By using the "*", I'm printing the values inside the adresses */
        }
    }
    printf("\n");

}

void print_spesific_elements(int a, int b, int *ptr, int C){ /* The function recieved a row, column, array (as pointer) information from the user */

    printf("\n The element in column %d of row %d is = %d\n",b,a, *((ptr+(a*C)-C)+b-1));
	
	 /* To get right result, we should consider the array starts at row 0 and column 0.
	    Thus, we have to substract one row and one column. */
}

void search_value(int x,int R,int C,int *ptr){
    int counter=0;
    int i,j;
    for(i=0; i<R; ++i){

        for(j=0; j<C; ++j){
            if(x == *((ptr+i*C)+j) ){		/* if the number which is searched by the user is equal to a number in the array's adress */
            printf("\n %d. Row %d. Column", i+1, j+1);	
            counter++;						/*it is going to increase counter */
            }
        }
    }
        if (counter==0){	/* if the counter is equal to zero there is no such value in the array same as the number entered by the user  */			
            printf("\n There is no such value that you have entered");
        }
}

int find_nonrepeateds(int R, int C,int *ptr){

    int x,y, counter1=0, counter2=0;	/* I defined two counter */
    int i,j;
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){
            counter1=0;
            for(x=0; x<R; ++x){			    /* I created a for loop inside another for loop to compare one element to all other elements */
                    for(y=0; y<C; ++y)
                    {
                        if (*((ptr+i*C)+j)==*((ptr+x*C)+y))
                            counter1++;		/* if a number is equal to another number in the array, counter1 would increase. */

                    }
            }

    counter1-=1;	/* I subtract the number itself */
    if (counter1==0){
    counter2++; 	/* If the counter1 is equal to zero there is no same number as that number
    				   so the counter2 that counts number of non-repeating numbers increments. */
    }
    }
    }
    return counter2; /* it returns the number of non-repeating numbers */
}

int find_min(int R, int C, int *ptr){

    int min=*ptr;	/* I equate the min to the number inside the initial adress of the array */
    int i,j;
    for(i=0; i<R; ++i)
    {
        for(j=0; j<C; ++j){
        if(*((ptr+i*C)+j)<min)	/* if the number is less than the minimum it becomes the new minimum */
        min=*((ptr+i*C)+j);

        }
    }
    return min;					/* it sends minimum info */
}

void find_max(int R, int C, int *ptr){

    int i,j;
    for(i=0; i<R; ++i)
    {
        int max=*(ptr+i*C); /* I equate it to the first element of each row to avoid confusion */
        for(j=0; j<C; ++j){

        if (*((ptr+i*C)+j)>max)
            max=*((ptr+i*C)+j);

        }
        printf("\n Max number of %d. row of array %d\n",i+1, max); /* it prints max numebr of each row */

    }
}

void bubblesorting(int R, int C, int *ptr, int *bub)
{	
	int i,j,l,k;
	for(i=0; i<R; ++i){
		for(j=0; j<C; ++j){
			*((bub+i*C)+j)=*((ptr+i*C)+j);
		}
	}
	
	for(l=1; l<R*C; ++l){
		for(i=0; i<C; ++i){
			for(j=0; j<C; ++j){
				
			if (*((bub+i*C)+j) < *((bub+i*C)+j+1)){
           	int swap = *((bub+i*C)+j);					/* It's sorting by descending order. If next number is bigger than itself, it will swap  */
           	*((bub+i*C)+j)= *((bub+i*C)+j+1);
           	*((bub+i*C)+j+1) = swap;
		}
	}
}
		for(k=0; k<R-1; ++k)							/* It's R-1 because it should not exceed the adress */
		{
			if (*((bub+k*C)+C) < *(bub+(k+1)*C)){
				int temp=*((bub+k*C)+C);				/* If last number of an row smaller than first number of next row, it will swap */
				*((bub+k*C)+C)=*(bub+(k+1)*C);
				*(bub+(k+1)*C)=temp;
			}
		}
}   /* Because of the top loop, sorting the rows within themselves will be done again. */
	print_elements(R,C,(int *)bub);		
}


void find_transpose(int R, int C, int *ptr, int *p){ /* I recieved one more array as pointer */
    
	int i,j;
    for(i=0; i<R; ++i){
        printf("\n");
            for(j=0; j<C; ++j){
                *((p+i*C)+j) = *((ptr+j*C)+i); /* I equate the row of original array to column of the second array */
                printf("%4d", *((p+i*C)+j));  /* I printed second array */

        }
    }

}

void compute_products(int R, int C, int *ptr, int *p, int *cp){ 	/* The function recieved the comp array as pointer */

    int i,j,k;
    if(R==C){			/* To multiply, first matrix's column and second matrix's row must be euqal */
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){
            
			*((cp+i*C)+j)=0;		/* Just in case, it make zero first element of every row */ 
            for(k=0; k<C; ++k){
            	
            *((cp+i*C)+j) += *((ptr+i*C)+k) * (*((p+k*C)+j)); /* multiply and add elements in the rows of the first matrix 
															  	 with the elements in the columns of the second matrix. */
            
            }
        }
    }

} else {printf("\n This matrix cannot be multiplied");}

    print_elements(R,C,(int *)cp); /* Initial adress of cp is sent to print elements as array to print it out*/
}

void check_identity(int R, int C, int *ptr){ 
    
	int i,j;
    int counter=0;
    
    for(i=0; i<R; i++){
        for(j=0; j<C; ++j)
        {
            if(i==j && *((ptr+i*C)+j)!=1){ /* To become identity matrix, it must be square and its diagonal must be 1 */
                counter++;
            }
            else if(i!=j && *((ptr+i*C)+j)!=0){ /* Also, its other elements must be 0 */
                counter++;
            }
        }
    }
	
    if (counter==0) /* if the above conditions are not fulfilled, counter won't increase */
        printf("\n\n Your matrix is an identity matrix");	/* So, the condition of being an identity matrix is met. */
    else
        printf("\n\n Your matrix is not an identity matrix"); /* if counter is not equal to zero, the condition of being an identity matrix is not met. */

}

void check_symmetric(int R, int C, int *ptr){  /* To be symmetric matrix, it should be equal when changing rows and columns */
    
	int i,j;
    int counter=0;
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){

            if(i!=j && *((ptr+i*C)+j)!=*((ptr+j*C)+i))
            counter++;
        }
    }
    if(counter==0)	/* if the above conditions are not fulfilled, counter won't increase */
        printf("\n\n Your matrix is a symmetric matrix\n"); /*In other words, the condition of being an symmetric matrix is met. */
    else
        printf("\n\n Your matrix is not a symmetric matrix\n"); /* if the counter is not equal to zero the condition of being an symmetrix matrix is not met. */
}








