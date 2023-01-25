
#ifndef MY_ARRAY_LIBRARY
#define MY_ARRAY_LIBRARY

void enter_elements(int R, int C, int arr[100][100]);
void print_elements(int R, int C, int arr[100][100]);
void print_spesific_elements(int m, int n,int arr[100][100]);

void search_value(int x, int R, int C, int arr[100][100]);
int find_nonrepeateds(int R, int C,int arr[100][100]);

int find_min(int R, int C,int arr[100][100]);
void find_max(int R, int C, int arr[100][100]);

void bubblesorting(int R, int C, int arr[100][100], int B[100][100]);

void find_transpose(int R, int C, int arr[100][100],int A[100][100]);
void compute_products(int R, int C, int arr[100][100], int A[100][100], int comp[100][100]);

void check_identity(int R, int C, int arr[100][100]);
void check_symmetric(int R, int C, int arr[100][100]);



#endif // MY_ARRAY_LIBRARY


