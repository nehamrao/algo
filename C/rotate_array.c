#include <stdio.h>

void print_array(int *a, int n) {
    int i;
    for (i = 0 ; i < n; i++) {
        printf("%d ",a[i]);
    }printf("\n");
}

/*
 * roate_array(a,n,k) right shifts an input
 * array of size 'n' by 'k' elements. If k
 * is > n, then use mod to obtain the new
 * k. Shifting n by n results in original inp. 
 * https://leetcode.com/problems/rotate-array/
 */
void rotate_array(int *a, int n, int k) {
 
    int b[n];
    
    if (k > n)  {
        k = k%n;
    }
    int i;
    int j = 0;
    for (i = k; i < n; i++) {
        b[i] = a[j];
        j++;
    }
    
    int m = n-1;
    int l;
    for (l = k-1; l >= 0; l--) {
         b[l] = a[m];
         m = m - 1; 
    }
    print_array(a,n);
    print_array(b,n);


}


/*
 * Right shift an input array
 * of size n by k elements.
 */
int main (void) {
    int n = 2;
    int a[2] = {1,2};
    int k = 1;
    
    rotate_array(a,n,k);
    return 0;
}
