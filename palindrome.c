#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool validPalindrome(int n) {
    //0 is a palindrome    
    if (n==0)
        return true;
    //Filter out negative numbers outside integer range
    if (n < 0) {
        if (n <  pow(2,15)) {
            return false;
        }
        //Treat rest of negative numbers as positive
        n = -1*n;   
    }

    int temp = n;
    int count;

    //Count provides the number of digits in n
    while (n != 0) {
        n = n/10;
        count++;
    }    
    printf("Number of digits is %d\n", count);
    
    int a[count];
    int i = 0;

    //Populate array a of size count to store each digit of input
    for (; i < count; i++) {
        a[i] = temp%10;
        temp = temp/10;
        printf("a[%d] = %d\n",i,a[i]);
    }

    //Compare the [1st,last element], then [2nd, 2nd last] element etc
    for (i = 0; i < count/2; i++) {
        if (a[i] != a[(count-1)-i])
                return false;
    }
    return true;
}

int main (void)
{
    int n = -2147483648;
    bool res;
    res = validPalindrome(n);
    printf("Input %d %s a valid palindrome\n",n,
           res == true ? "is":"is not");
    return 0;
}
