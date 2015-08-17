#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    
    int count = 0;
    
    while (n != 0) {
        if (n%2 == 1) {
            count++;
            n = (n-1)/2;
        } else {
            n = n/2;
        } 
        
    } 
    return count;
    
}


int main (void) {

    uint32_t n = 0;
    int count;
    count = hammingWeight(n);
    printf("Count %d\n", count);
    return 0;

}
