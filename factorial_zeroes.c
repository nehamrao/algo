/*
 * Given an integer n, return the number of trailing 
 * zeroes in n!. Note: Your solution should be in 
 * logarithmic time complexity.
 */

int trailingZeroes(int n) {
        
    int zeros = 0;
    
    while(n != 0) {
        n /= 5;
        zeros += n;
    }
    
    return zeros;
}
