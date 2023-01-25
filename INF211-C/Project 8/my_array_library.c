#include <stdio.h>
#include "my_array_library.h"


void enter_elements(int R, int C, int arr[100][100]){
     int i,j;
    for(i=0; i<R; ++i){

        for(j=0; j<C; ++j){
            printf("Enter [%d][%d] element of array: ", i+1, j+1);
            scanf("%d", &arr[i][j]);

        }
    }
}

void print_elements(int R, int C, int arr[100][100]){

     int i,j;
    for(i=0; i<R; ++i){
            printf("\n");
        for(j=0; j<C; ++j){
                printf("%4d", arr[i][j]);
        }
    }
    printf("\n");

}

void print_spesific_elements(int m, int n, int arr[100][100]){

    printf("\n The element in column %d of row %d is = %d\n",m,n, arr[m-1][n-1]);
}

void search_value(int x,int R,int C,int arr[100][100]){
    int counter=0;
    int i,j;
    for(i=0; i<R; ++i){

        for(j=0; j<C; ++j){
            if(x==arr[i][j]){
            printf("\n %d. Row %d. Column", i+1, j+1);
            counter++;
            }
        }
    }
        if (counter==0){
            printf("\n There is no such value that you have entered");
        }
}

int find_nonrepeateds(int R, int C,int arr[100][100]){

    int x,y,counter1=0, counter2=0;
    int i,j;
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){
            counter1=0;
            for(x=0; x<R; ++x){
                    for(y=0; y<C; ++y)
                    {
                        if (arr[i][j]==arr[x][y])
                            counter1++;

                    }
            }

    counter1-=1;
    if (counter1==0){
    counter2++;
    }
    }
    }
    return counter2;
}

int find_min(int R, int C,int arr[100][100]){

    int min=arr[0][0];
    int i,j;
    for(i=0; i<R; ++i)
    {
        for(j=0; j<C; ++j){
        if(arr[i][j]<min)
        min=arr[i][j];

        }
    }
    return min;
}

void find_max(int R, int C, int arr[100][100]){

     int i,j;
    for(i=0; i<R; ++i)
    {
        int max=arr[i][0];
        for(j=0; j<C; ++j){

        if (arr[i][j]>max)
            max=arr[i][j];

        }
        printf("\n Max number of %d. row of array %d\n",i,max);

    }
}

void bubblesorting(int R, int C, int arr[100][100], int B[100][100]){
    
     int i,j,z,k;
    for(i=0; i<R; ++i){

        for(j=0; j<C; ++j){

            B[i][j]=arr[i][j];
        }
    }

    int temp;
    for (z=1; z<R*C; ++z){

    for(i=0; i<R; ++i)
    {
        for(j=0; j<C-1; ++j){

            if(B[i][j]>B[i][j+1])
            {
                temp = B[i][j];
                B[i][j] = B[i][j+1];
                B[i][j+1]= temp;
            }
        }
    }
    for (k=0; k<R-1; ++k)
    {
        if (B[k][C-1]>B[k+1][0]){

            temp=B[k][C-1];
            B[k][C-1]=B[k+1][0];
            B[k+1][0]= temp;
        }
    }

}
    print_elements(R,C,B);
}

void find_transpose(int R, int C, int arr[100][100], int A[100][100]){
     int i,j;
    for(i=0; i<R; ++i){
        printf("\n");
            for(j=0; j<C; ++j){
                A[i][j]=arr[j][i];
                printf("%3d", A[i][j]);

        }
    }

}

void compute_products(int R, int C, int arr[100][100], int A[100][100],int comp[100][100]){

     int i,j,k;
    if(R==C){
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){
            comp[i][j]=0;
            for(k=0; k<C; ++k){
            comp[i][j] += arr[i][k] * A[k][j];
            }
        }
    }

} else {printf("\n This matrix cannot be multiplied");}

    print_elements(R,C,comp);
}

void check_identity(int R, int C, int arr[100][100]){
     int i,j;
    int counter=0;
    for(i=0; i<R; i++){
        for(j=0; j<C; ++j)
        {
            if(i==j && arr[i][j]!=1){
                counter++;
            }
            else if(i!=j && arr[i][j]!=0){
                counter++;
            }


        }
    }

    if (counter==0)
        printf("\n\n Your matrix is an identity matrix");
    else
        printf("\n\n Your matrix is not an identity matrix");

}

void check_symmetric(int R, int C, int arr[100][100]){
     int i,j;
    int counter=0;
    for(i=0; i<R; ++i){
        for(j=0; j<C; ++j){

            if(i!=j && arr[i][j]!=arr[j][i])
            counter++;
        }
    }
    if(counter==0)
        printf("\n\n Your matrix is a symmetric matrix\n");
    else
        printf("\n\n Your matrix is not a symmetric matrix\n");
}




