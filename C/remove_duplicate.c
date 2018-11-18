#include <stdio.h>

/*
 * Remove the duplicates from a sorted array and place 
 * it in the same array from the beginning. Return the
 * new length of the array.
 */
int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 0;
    int cnt = 0;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != nums[i+1] || (i+1 >= numsSize)) {
            nums[j] = nums[i];
            j++;
        } 
    }

    return j;
}

int main (void) {
    int a[8] = {1,1,2,2,6,6,9,9};
    int ret = removeDuplicates(a,8);
    printf("The new length w/o duplicates is %d\n",ret);
    return 0;
}
