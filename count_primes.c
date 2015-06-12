#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void print_ary(bool *inp, int size) {
    int i;
    for (i = 0; i < size; i++) {
       printf("%d ", inp[i]);
    } printf("\n");
    
}

int count_primes(int num) {
    
    num = num+1; 
    bool a[num];
    
    //Set a bool array from 0 to num as false 
    int i;
    for (i = 0; i < num; i++) {
        a[i] = false;
    }  
   
    /* 
     * Starting from prime p = 2, iterate over all
     * p <= square root of the input. In each iteration
     * set array element corresponding to multiples of p 
     * (excluding p) as 'true'. 
     */
    int j,p;
    for (p = 2; p < sqrt((double) num); p++ ) {
        for (j = p*p; j <= num; j=j+p ) {
            a[j] = true;
        }
    }    

    /* 
     * Find the number of primes and the values.
     * Look for elements set as 'false' excluding 
     * 0 and 1.
     */
    int k;
    int prime = 0;
    printf("LIST OF PRIMES (if any)\n");
    for (k = 2; k < (num-1); k++) {
        if (a[k] == false) {
            printf("%d ",k);  
            prime = prime + 1;
        } 
    } printf ("\n");

    return prime;
}

int main (void) {
    
    int num = 1;
    int prime;

    prime = count_primes(num);
    printf("INPUT: %d\t PRIMES < INPUT: %d\n", num, prime);


}
