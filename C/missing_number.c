#include <stdio.h>
#include <stdlib.h>

/*
 * Given an array containing n distinct numbers 
 * taken from 0, 1, 2, ..., n, find the one that 
 * is missing from the array.For example,
 * Given nums = [0, 1, 3] return 2. 
 */
int missingNumber(int* nums, int numsSize) {
    
    //Calculate expected sum
    int i, e_sum = 0, a_sum = 0;
    for (i = 0; i < numsSize+1; i++)
        e_sum = e_sum + i;

    //Calculate actual sum
    for (i = 0; i < numsSize; i++) {
         a_sum = a_sum + nums[i];
    }
  
    return abs(a_sum - e_sum);
}

int main (void) {
    int a[6] = {1,2,3,4,5,6};
    int ret = missingNumber(a,6);
    printf("Missing number is %d\n",ret);

    return 0;
}
