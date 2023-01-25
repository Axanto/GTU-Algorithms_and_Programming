#include <stdio.h>

int main()
{
    double height, water, work, mass;

    float gravity=9.80, efficiency;

    puts("Hydroelectric Dam Energy Calculator");

    printf("\nEnter the height of dam in meters: ");
    scanf("%lf", &height);

    printf("\nEnter the number of cubic meters: ");
    scanf("%lf", &water);

    mass= water*1000;
    efficiency = 0.9;
    work= mass*gravity*height*efficiency;
    work = work/1e6;

    printf("\nThe net energy obtained is %f MW\n", work);

    return 0;



}
