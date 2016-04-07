/*
 * Given a non-negative number represented as an array of digits, 
 * plus one to the number.The digits are stored such that the most 
 * significant digit is at the head of the list.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int i;
    int new_size = 0;
    int carry = 0;
    
    for (i = (digitsSize-1); i >= 0 ; i = i - 1) {
        if (digits[i] < 9) {
            digits[i]  = digits[i] + 1;
            new_size = digitsSize;
            break;
        } else {
            digits[i] = 0;
            new_size++;
            
            if (i == 0)
                new_size++;
        }
    }
    
    int* ret = malloc(new_size*sizeof(int));
    *returnSize = new_size;
    
    if (new_size > digitsSize) {
        ret[0] = 1;
    } else {
        ret[0] = digits[0];
    }
    for (i = 1; i < new_size; i++) {
        ret[i] = digits[i];
    }
    return ret;
    
}


