#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void PrintFileContent(FILE* fptr);
void copy_file(FILE* fptr1,FILE* fptr2);
int findNumberofChar(FILE* fptr);

 int main()
{

 char fileName1[100];
 char fileName2[100];
 FILE *file1;
 FILE *file2;

 printf("Enter the file name to open for reading:\n");
 gets(fileName1);

 file1 = fopen(fileName1, "r");

 printf("Enter the file name to open for writing and reading:\n");
 gets(fileName2);

 file2 = fopen(fileName2, "w+");


 copy_file(file1,file2);
 PrintFileContent(file1);

 fclose(file2);
 file2 = fopen(fileName2, "a");
 fprintf(file2,"\n\nThe file second.txt has %d characters",findNumberofChar(file2));
 fclose(file2);

 file2 = fopen(fileName2, "r");
 PrintFileContent(file2);

 fclose(file1);
 fclose(file2);

 return 0;
}

void PrintFileContent(FILE* fptr){

	char ch;

	if(fptr == NULL){
		printf("failed to open.");
	}
	else {
		while((ch=fgetc(fptr)) != EOF)
		putchar(ch);
	}

	printf("\n");

	rewind(fptr);
}

void copy_file(FILE* fptr1,FILE* fptr2)
{
	char ch;

	fptr1 = fopen("first.txt", "r");
	if(fptr1 == NULL )
   {
      printf("Copying has failed!\n");
      exit(EXIT_FAILURE);
   }

   fptr2 =fopen("second.txt", "w+");
    if(fptr2 == NULL )
   {
      fclose(fptr2);
      printf("Error!!\n");
      exit(EXIT_FAILURE);
   }

 	while((ch =fgetc(fptr1)) != EOF){

 		ch = toupper(ch);
 		fputc(ch, fptr2);
 	}

 	fclose(fptr1);
 	fclose (fptr2);
 }

int findNumberofChar(FILE* fptr)
 {
 	char ch;
 	int counter=0;

 	fptr = fopen("second.txt", "r");

	if(fptr == NULL)
   	{
      printf("Error!\n");
      exit(EXIT_FAILURE);
   	}

   	while (ch=fgetc(fptr) != EOF) {
		counter++;
	}

	return counter;

	fclose(fptr);
 }


