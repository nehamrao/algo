#include <stdio.h>
#include <stdbool.h>

bool isPrime (int p)
{
    int i;
    for (i = 2; i < p/2; i++)
    {		
        if (p % i == 0) {
            printf("Found a divisor: %d\n", i);
            return false;
	}
    }
    return true;
}

int main (void)
{
    int a;
    bool is_prime;

    printf("Enter a number: ");
    scanf("%d", &a);
    printf("\nDetermining if it is prime or not ...\n");
    
    is_prime = isPrime(a);
    printf("The number %d is%s prime\n", a, is_prime ? "":" not");
    return 0;
}
