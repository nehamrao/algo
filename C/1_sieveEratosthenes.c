#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void findPrimes(int num)
{	
    int i, j;
  
    bool ary[num];
    
    // Array initialization
    for (i = 0; i < num; i++)
    {   
        ary[i] = true;
    }  
    
    for (i = 2; i <= ((int) floor(sqrt(num))); i++)
    {
       for (j = i*i; j <= num; j += i)
       {
            ary[j] = false;
       }  
    }
    int cnt = 0;
    printf("The list of primes before %d is:\n", num);
    for (i = 2; i < num-1; i++)
    {
        if (ary[i] == true) { 
            cnt++;
	    printf("%d ", i);
        }
    } printf("\n");
    printf("Count is %d\n", cnt);    
}

int main (void)
{
    int num;
   
    printf("Provide input number to determine if it is prime:\n");
    scanf("%d", &num);
    
    findPrimes(num);
    return 0;
}
