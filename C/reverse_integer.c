#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int get_digits(int n) {
    
    int i = 10;
    int count = 1;
    while((n%i) < n) {
        count++;
        i = i*10;
    }
    printf("Number of digits in the input is %d\n", count);
    return count;
}

int int_pwr(int n, int p) {
    int i;
    int res = n;
    for (i = 1; i < p; i++) {
       res = res*n;
    }
    return res;
}

int reverse_integer( int n) {
     
    /*
     * Determine if -ve integer
     */
    bool neg = false;
    if (n < 0) {
        neg = true;
        n = -1*n;
    }
    int m = 0;
    while (n%10 != n) {
      m = m*10 + n%10;
      n = n/10; 
    }
    m = m*10 + n%10;    
    return m; 
}

int main(void) {
    int num = 1534;
    printf("Original number is %d\n",num);
    num = reverse_integer(num);
    printf("Reversed number is %d\n",num);
    return 0;
}
