#include <stdio.h>

/*
 * Suppose a sorted array is rotated at some pivot 
 * unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 */
int findMin(int* nums, int numsSize) {
    int i = 1;
    for (i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i-1])
            return nums[i];
        else if (i == numsSize-1) {
            return nums[0];
        }   
    }
}

int main (void) {
    int a[7] = {4,5,6,7,0,1,2};
    int ret = findMin(a,7);

    printf("Test1: The minimum number is %d\n",ret);

    int b[3] = {1,2,3};
    printf("Test2: The minimum number is %d\n",findMin(b,3));
    return 0;
}
