#include <stdio.h>

/*
 * Move all zeroes in the array to the end
 * by not chnaging the relative order of the
 * remaining elements
 */
void moveZeroes(int* nums, int numsSize) {
    int i, j = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    for (i = j; i < numsSize; i++)
        nums[i] = 0;

    //printing
    for (i = 0; i < numsSize; i++)
       printf("%d ,", nums[i]);
    printf("\n");
}


int main (void) {
    int nums[5] = {0,0,7,0,3};
    moveZeroes(nums,5);
}
