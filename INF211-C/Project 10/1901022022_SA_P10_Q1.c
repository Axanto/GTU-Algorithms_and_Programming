#include <stdio.h>
#include <stdlib.h>

struct Student {

    char name[20]; //max character size is 20
    int number;
    float marks;

};

void printStudent(struct Student s); //prototype of the function


struct Student recordStudent() //struct function to take Student records
{
    struct Student s;
    printf("\nPlease enter the student's name: ");
    scanf("%s", &s.name);

    printf("\nPlease enter the student's number: ");
    scanf("%d", &s.number);

    printf("\nPlease enter the student's mark: ");
    scanf("%f", &s.marks);

    return s; 	// it returns s

}

void printStudent(struct Student s) //function that print the records out.
{
    printf("\nStudent's Name: %s", s.name);

    printf("\nStudent's Number: %d", s.number);

    printf("\nStudent's Marks: %.1f", s.marks);
}

int main(){

    struct Student student1 = recordStudent(); //to print it out below, we assign the function to "student1"

    printStudent(student1);

    return 0;
}
