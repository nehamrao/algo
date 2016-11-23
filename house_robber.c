#include <stdio.h>

int largest_sum(int a, int b, int c) {
    if ((a >= b) && (a >= c))
        return a;
    else if ((b >= a) && (b >= c))
       return b;
    else   
       return c;
}

/*
 * 1. Even Houses
 * 2. Odd Houses
 * 3. Last two houses
 * 4. Only 2 houses
 */

int rob_house(int *a, int n) {
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
 
    int i;
    /*
     * Alternate houses (even and odd)
     */
    for (i = 0; i < n; i = i+2) {
        sum1 = sum1 + a[i];
        if (i+1 < n) {
            sum2 = sum2 + a[i+1];
        }
    }
    if (n == 2) {
        if (sum1 > sum2)
            return sum1;
        else
            return sum2;
    }    

    for (i = 0; i < n ; i = i+2) {
        if ((n-1-i)-i >= 2) {
            sum3 = sum3 + a[i] + a[n-1-i];
        }
    }
    printf("sum1 is %d, sum2 is %d, sum3 is %d\n", sum1, sum2, sum3);
    int res;
    res = largest_sum(sum1,sum2,sum3);
    return res;
}


int main (void) {
    int n;
    int sum;
    int a[4] = {1,2,1,0};
    sum = rob_house(a,4);
    printf("Net sum robbed %d\n",sum);  
  
}
