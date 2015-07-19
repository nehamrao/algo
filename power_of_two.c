#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    int i;
    
    /*
     * Return flase for negative number,
     * odd numbers except 1
     */    
    if ((n%2 != 0 && n != 1) || n <= 0)
        return false;
        
    /*
     * Check if the even number input
     * is really a power of two. Return 
     * false if n is odd. When n becomes
     * 1 it is indeed a power of two.
     */
    while(n%2 == 0) {
        n/2;
        n = n/2;
        if (n%2 == 1 && n!=1)
            return false;
    }

    return true; 
}

int main(void) {
    
    int n = 690847;
    bool result;
    
    result = isPowerOfTwo(n); 
    if (result == true)
        printf("Input %d is a power of 2\n", n);
    else
        printf("Input %d is a not a power of 2\n", n);

}
