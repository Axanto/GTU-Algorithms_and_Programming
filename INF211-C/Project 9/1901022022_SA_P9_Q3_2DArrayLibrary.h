#ifndef ARRAY_LIBRARY_H
#define ARRAY_LIBRARY_H
/* We are just declaring the functions in header file */

void enter_elements(int R, int C, int *ptr);
void print_elements(int R, int C, int *ptr);
void print_spesific_elements(int m, int n, int *ptr,int C);

void search_value(int x, int R, int C, int *ptr);
int find_nonrepeateds(int R, int C,int *ptr);

int find_min(int R, int C,int *ptr);
void find_max(int R, int C, int *ptr);

void bubblesorting(int R, int C, int *ptr, int *bub);

void find_transpose(int R, int C, int *ptr, int *p);
void compute_products(int R, int C, int *ptr, int *p, int *cp);

void check_identity(int R, int C, int *ptr);
void check_symmetric(int R, int C, int *ptr);



#endif // ARRAY_LIBRARY H


