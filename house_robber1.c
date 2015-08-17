#include <stdio.h>
#include <math.h>

int max_fn (int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int rob (int *a, int n) {
    
    /*
     * If number of houses is 0
     * or 1 then return 0 or
     * money at first house since
     * that is the max you can rob. 
     */
    if (n == 0)
        return 0;
    
    if (n == 1)
        return a[0];
    /*
     * For all houses from house 2 onwards,
     * you either choose house 2, or you don't.
     * Choosing house 2 => money at house 2 + max money 
     * at alternate house before it.
     * Not choosing house 2 => max money  till house 1 
     * Assigning the max sum robbed to a[i] in each iteration 
     */ 
    for (int i = 1; i < n; i++) {
        a[i] = max_fn(a[i-1], a[i-2]+a[i]);    
    } 
    return a[n-1];
}

int main (void) {
    int a[6] = {1,1,1,1,1,1};
    int sum;
    sum = rob (a, 6);
    printf("Money robbed is %d\n", sum) ;
}

