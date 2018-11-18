/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * Given an array of n integers where n > 1, nums, 
 * return an array output such that output[i] is equal 
 * to the product of all the elements of nums except nums[i].
 */

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int* ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int i, j, mult = 1, temp = 1;
    
    for (i = 0; i < numsSize; i++) {
        mult = mult*nums[i];
    }
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            ret[i] = mult/nums[i];
        } else {
            nums[i] = 1;
            for (j = 0; j < numsSize; j++) {
                temp = temp*nums[j];
            }
            ret[i] = temp;
        }
    }
    
    return ret;
    
}

/* Method 2 O(n^2) complexity */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    
    int* ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    int i, j;
    for (i = 0; i < numsSize; i++) {
        ret[i] = 1;
    }
    
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (j != i) {
                ret[j] = ret[j]*nums[i];
            }
        }
    }
    
    return ret;
    
}
