    #include <stdio.h>

int main()
{
    int c=1; //c is a variable for the counter
    float t; //t is a variable for the temperatures
    float sum=0, average;

while(c<=24) //It's a loop for asking the user the same question for 24 different times in a day
{
    printf("\nEnter the temperature as celsius degree: ");
    scanf("%f", &t);
    t=t*1.8 + 32; // to convert to fahrenheit
    sum += t;
    c++;

    if (t>=85)
        printf("\nWeather is hot\n");
    else if (84>=t && t>=60)
        printf("\nWeather is pleasant\n");
    else if (60>=t)
        printf("\nWeather is cold\n");

}

    average=sum/24; //we will find average dividing sum by 24
    printf("\n\nAverage of the temperatures is: %f", average);

    return 0;

}
