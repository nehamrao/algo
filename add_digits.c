#include <stdio.h>

/*
 * Recursion to add the digits of a positive int
 * all the way up to a single digit
 */
int addDigits (int num) {
    int sum = 0;
    while (num != 0) {
        sum = sum + num%10;
        if (sum > 9)
           sum = addDigits(sum);
        num = num/10;   
    }
    return sum;
}

int main (void) {
    int n = 897555;
    int res;
    res = addDigits(n);
    printf("The sum of digits of %d is %d\n", n, res);
}

