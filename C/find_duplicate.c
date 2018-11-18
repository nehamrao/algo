#include <stdio.h>
#include <stdbool.h> 

/*
 * Args : Reference to input array, size of array
 * Return : TRUE if duplicate of an integer is found
 *          FALSE if array contains unique elements 
 */
bool find_duplicate(int num[], int n) {
    int i,j;
    bool dup = false;

    for (i=0; i<n-1 ; i++) {
        for (j=i+1; j<n ; j++) {
            if (num[i] == num[j]) {
                printf("Found a duplicate of %d in given array\n",num[i]);
                return true;
            } 
         }
    }
    return false;    
}

/*
 * Given an array of integers, find if it 
 * contains duplicates/unique elements.
 * https://leetcode.com/problems/contains-duplicate/
 */

int main(void) {
    
    bool result;
    int num[4] = {1, 2, 1, 3};
    
    result = find_duplicate(num, 4);
    
    if (result == true) {   
        printf("Array contains duplicates\n");
    } else {
        printf("Array consists of unique elements\n");
    }
    
    return 0;

}
