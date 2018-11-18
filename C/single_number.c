#include <stdio.h>

/*
 * XOR operation is the key. It is associative
 * in nature so no matter what order the input
 * is in, we will be able to identify the single 
 * number
 */
int singleNumber (int *a, int n ) {
    int i = 0, res = 0;
    for (; i < n; i++) {
        res = res ^ a[i];
    }
    return res;
}

int main (void) {
    int a[7] = {12, 34, 12, 56, 56, 34, 7};
    int res = singleNumber(a, 7);
    printf("Single Number in the Array is %d\n", res);
    return 0;
}
