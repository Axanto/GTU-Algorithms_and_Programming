#include <stdio.h>

int main()
{
float x,emp,sum=0,pay,rate,hours,total,average;

printf("\nPlease Enter the Number of Employee: ");
scanf("%f", &emp);

for(x=1; x<=emp; x++) //a loop from one to the number of employees entered
{
    printf("\n\nPlease enter the rate: ");
    scanf("%f", &rate);

    printf("\nPlease enter the working hours: ");
    scanf("%f", &hours);

    pay = rate * hours; //to find daily salary, multiplies hourly wage by hours that worked to find daily salary
    printf("\nDaily salary of this employee: $%.2f", pay);

    sum = pay + sum; //it's adding daily salary to sum for every single employee

}

average= sum / emp; //dividing sum by employee number, it finds average
printf("\nAvarage of the daily cost: $%.2f", average);


total = pay*7; // i got the total payroll weekly. So it multiplies daily salary to seven to find total payroll.
printf("\nWeekly total payroll for company is: $%.2f", total);

return 0;
}
