/*
 Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]. 
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int mult(int a, int b, int c) {
    long res = ((long) a) * ((long) b);
    res /= ((long) c);
    return (int) res;
} 
 
int* getRow(int rowIndex, int* returnSize) {
    
    int* ret = malloc(sizeof(int)*(rowIndex+1));
    *returnSize = rowIndex+1;
    
    ret[0] = 1;
    
    for (int i = 1; i <= rowIndex; i++) {
        ret[i] = mult((rowIndex - i + 1), ret[i-1], i);
    }
    
    return ret;
}

