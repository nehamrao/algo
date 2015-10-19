#include <stdio.h>

/*
 * Given a sorted array and a target value, return the index 
 * if the target is found. If not, return the index where 
 * it would be if it were inserted in order.
 You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0 
 
*/
int searchInsert(int* nums, int numsSize, int target) {

    // Keep an array of one int set to -1 to start off with 
    int a[1];
    a[0] = -1;
    
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        
        // If target is found, return the index
        if (target == nums[i]) {
            return i;
        } else if (target < nums[i]) {
            if (i == 0) a[0] = i; // To keep track of number of lowest index < target
            if (nums[i] < nums[i-1] && i-1 >= 0)
                a[0] = i;
        } else if (target > nums[i]) {
            a[0] = i+1; // To handle a case when number greater than index
        }
    }
    if (a[0] == -1)
        return numsSize;
    else    
        return a[0];
}


int main (){
    int target = 6;
    int nums[] = {2,4,5,7};
    int index = searchInsert(nums, 4, target );    
    printf("Index to insert target %d is %d\n", target, index);
}
