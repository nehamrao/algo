#include <stdio.h>

/*
 * Given an array of elements and a value, check if
 * any value matches any element of the array. If so, 
 * remove that instance of value in the array and 
 * return the new length of the array. The modified
 * array must have the digits that are not equal to value
 * starting from index 0 and continuing till new length.
 */
int removeElement(int* nums, int numsSize, int val) {
    int i, j = 0;
    
    //i keeps track of exisitng ary, j of repopulating ary 
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main (void) {
    int nums[5] = {2, 5, 2, 3, 3};
    int num = removeElement(nums, 5, 5);
    printf("Len %d\n", num);
    return 0;
}
