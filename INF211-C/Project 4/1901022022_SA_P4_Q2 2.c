#include <stdio.h>

int main()
{
    int a1=1,a2=2,a3=3,a4=4;
    int b1=2,b2=4,b3=11,b4=12;
    int c1=2,c2=4,c3=10,c4=14;
    int k1=0,k2=0,k3=0,k4=0; /* Components of AnBnC */
    int d1=0,d2=0,d3=0,d4=0; /* Components of AnB/C

/* This is for set AnBnC */

{ /* it checks other set's for a1 */
    if (a1==b1 && b1==c1)
    k1=c1;

    if (a1==b1 && b1==c2)
    k1=c2;

    if (a1==b1 && b1==c3)
    k1=c3;

    if (a1==b1 && b1==c4)
    k1=c4;

    if (a1==b2 && b2==c1)
    k1=c1;

    if (a1==b2 && b2==c2)
    k1=c2;

    if (a1==b2 && b2==c3)
    k1=c3;

    if (a1==b2 && b2==c4)
    k1=c4;

    if (a1==b3 && b3==c1)
    k1=c1;

    if (a1==b3 && b3==c2)
    k1=c2;

    if (a1==b3 && b3==c3)
    k1=c3;

    if (a1==b3 && b3==c4)
    k1=c4;

    if (a1==b4 && b4==c1)
    k1=c1;

    if (a1==b4 && b4==c2)
    k1=c2;

    if (a1==b4 && b4==c3)
    k1=c3;

    if (a1==b4 && b4==c4)
    k1=c4;
 }
{ /* it checks other set's for a2 */

     if (a2==b1 && b1==c1)
    k2=c1;

    if (a2==b1 && b1==c2)
    k2=c2;

    if (a2==b1 && b1==c3)
    k2=c3;

    if (a2==b1 && b1==c4)
    k2=c4;

    if (a2==b2 && b2==c1)
    k2=c1;

    if (a2==b2 && b2==c2)
    k2=c2;

    if (a2==b2 && b2==c3)
    k2=c3;

    if (a2==b2 && b2==c4)
    k2=c4;

    if (a2==b3 && b3==c1)
    k2=c1;

    if (a2==b3 && b3==c2)
    k2=c2;

    if (a2==b3 && b3==c3)
    k2=c3;

    if (a2==b3 && b3==c4)
    k2=c4;

    if (a2==b4 && b4==c1)
    k2=c1;

    if (a2==b4 && b4==c2)
    k2=c2;

    if (a2==b4 && b4==c3)
    k2=c3;

    if (a2==b4 && b4==c4)
    k2=c4;
}
{ /* it checks other set's for a3 */

     if (a3==b1 && b1==c1)
    k3=c1;

    if (a3==b1 && b1==c2)
    k3=c2;

    if (a3==b1 && b1==c3)
    k3=c3;

    if (a3==b1 && b1==c4)
    k3=c4;

    if (a3==b2 && b2==c1)
    k3=c1;

    if (a3==b2 && b2==c2)
    k3=c2;

    if (a3==b2 && b2==c3)
    k3=c3;

    if (a3==b2 && b2==c4)
    k3=c4;

    if (a3==b3 && b3==c1)
    k3=c1;

    if (a3==b3 && b3==c2)
    k3=c2;

    if (a3==b3 && b3==c3)
    k3=c3;

    if (a3==b3 && b3==c4)
    k3=c4;

    if (a3==b4 && b4==c1)
    k3=c1;

    if (a3==b4 && b4==c2)
    k3=c2;

    if (a3==b4 && b4==c3)
    k3=c3;

    if (a3==b4 && b4==c4)
    k3=c4;
}
{ /* it checks other set's for a4 */

     if (a4==b1 && b1==c1)
    k4=c1;

    if (a4==b1 && b1==c2)
    k4=c2;

    if (a4==b1 && b1==c3)
    k4=c3;

    if (a4==b1 && b1==c4)
    k4=c4;

    if (a4==b2 && b2==c1)
    k4=c1;

    if (a4==b2 && b2==c2)
    k4=c2;

    if (a4==b2 && b2==c3)
    k4=c3;

    if (a4==b2 && b2==c4)
    k4=c4;

    if (a4==b3 && b3==c1)
    k4=c1;

    if (a4==b3 && b3==c2)
    k4=c2;

    if (a4==b3 && b3==c3)
    k4=c3;

    if (a4==b3 && b3==c4)
    k4=c4;

    if (a4==b4 && b4==c1)
    k4=c1;

    if (a4==b4 && b4==c2)
    k4=c2;

    if (a4==b4 && b4==c3)
    k4=c3;

    if (a4==b4 && b4==c4)
    k4=c4;
}
printf("\nAnBnC = { %d,%d,%d,%d }", k1,k2,k3,k4);

{/* it's for set "AnB/C"  */

    if (k1==c1)
    d1= k1-c1;

    if (k1==c2)
    d1= k1-c2;

    if (k1==c3)
    d1= k1-c3;

    if (k1==c4)
    d1= k1-c4;

    if (k2==c1)
    d2= k2-c1;

    if (k2==c2)
    d2= k2-c1;

    if (k2==c3)
    d2= k2-c3;

    if (k2==c4)
    d2= k2-c4;

    if (k3==c1)
    d3= k3-c1;

    if (k3==c2)
    d3= k3-c2;

    if (k3==c3)
    d3= k3-c3;

    if (k3==c4)
    d3= k3-c4;

    if (k4==c1)
    d4= k4-c1;

    if (k4==c2)
    d4= k4-c2;

    if (k4==c3)
    d4= k4-c3;

    if (k4==c4)
    d4= k4-c4;
}
printf("\n\nAnB/C ={ %d,%d,%d,%d }\n",d1,d2,d3,d4);
return 0;

}
