#include <stdio.h>

int main()
{

double beginning,ending;
float miles,reimbursement,price=0.35;

puts("MILEAGE REIMBURSEMENT CALCULATOR\n");
printf("Enter beginning odometer reading: ");
scanf("%lf",&beginning);

printf("\nEnter ending odometer reading: ");
scanf("%lf",&ending);


miles= ending- beginning;

if (ending>=beginning){

printf("\nYou have traveled %.2f miles.At $0.35 per mile", miles);

reimbursement= miles*price;

printf("\nYour reimbursement is: %.2f \n", reimbursement);
}
else{
    printf("\nI think you should check your odometer");
}

return 0;
}

