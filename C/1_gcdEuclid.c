#include <stdio.h>

int gcd (int a, int b)
{
    while (b !=0 ) {
	printf ("a: %d, b: %d, a (mod) b: %d\n",
               a, b, a%b);
	return gcd (b, a%b);
    }
    return a;
}

int main (void) 
{
   int a, b;
   printf ("Provide the numbers for which the gcd is to be determined\n");
   scanf("%d", &a);
   scanf("%d", &b);
   printf("GCD (%d, %d) = %d\n", a, b, gcd(a,b));
}
