#include <stdio.h>

int main()
{
  int a=200,b=12345,w=1234567890, s=4043;
  int c=275-a;
  unsigned int pp=3776135780-w;
  double t=2.13459, y=1.1415927;

  printf("a+c = %d\n", a+c);
  printf("t+c = %f\n", t+c);
  printf("y+t = %f\n", y+t);
  printf("a+b = %d\n", a+b);
  printf("s+b = %d\n", s+b);
  printf("w+b = %d\n", w+b);
  printf("s+c = %d\n", s+c);
  printf("w+c = %d\n", w+c);
  printf("w+pp = %u\n", w+pp);

  return 0;



}
