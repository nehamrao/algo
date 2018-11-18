#include <stdio.h>

int majority_element(int *a, int n) {
    int m = n/2;
    printf("Floor of %d/2  is %d\n",n,m);

    /*
     * Find the array element > floor(n/2)
     * Hash array elements over m elements
     */
     int i;
     int hash_idx;
     int b[m];
     for (i = 0; i < n; i++) {
         hash_idx = (a[i] % m);
	 	
     }
      
      
    return m;
}

int main (void) {

    int a[9] = {1, 1, 1, 1, 1, 12, 3, 56};
    majority_element(a,9);
    return 0;
}
