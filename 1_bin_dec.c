// Test
#include <stdio.h>
#include <math.h>

int numDigits (int n)
{
    int digits = 0;

    while (n!=0) {
        n=n/10;
        digits++;
    }
    return digits;
}

int bin2dec (int b)
{
    int d = 0;
    int i = 0;
    int n = numDigits(b);
    printf ("The num digits is %d\n", n); 
    
    while (n !=0) {
        d = d + ((b%10)*pow(2,i));
        b = b/10;
        i++; n--;
    } 
    return d;
}

int main (void) {
    
    int b;
    int d;
  
    // Take in user input
    printf("Enter the binary number: ");
    scanf("%d", &b);

    // Convert to decimal
    d = bin2dec(b);
    printf("\n Decimal conversion resulted in %d\n", d);  
}
