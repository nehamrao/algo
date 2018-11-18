/*
 * Given a non negative integer number num. For every number 
 * i in the range 0 ≤ i ≤ num calculate the number of 1's in 
 * their binary representation and return them as an array. 
 * For num = 5 you should return [0,1,1,2,1,2].  
 */

int findOneDigits(int num)
{
    int cnt = 0;
    
    if (num == 0)
        return 0;
    
    if (num == 1)
        return 1;
        
    while (num != 0) {
        if (num%2 == 1) {
            cnt++;
            num =(num-1)/2;
        } else {
         num = num/2;   
        }
    }
    return cnt;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    
    int* ret = malloc(sizeof(int)*(num+1));
    *returnSize = num + 1;
    
    if (!returnSize)
        return NULL;
        
    int i;
    
    for (i = 0; i <= num; i++) {
        
        // Even Number
        if (i%2 == 0) {
            ret[i] = findOneDigits(i);
        } else {
            ret[i] = ret[i-1]+1;
        }
    }
    
    return ret;
}
