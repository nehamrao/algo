/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    
    int i, j;
    int** ret = (int **) malloc(sizeof(int *) * numRows);
    *columnSizes = (int *) malloc(numRows*sizeof(int));
    
    for (i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i+1;
        ret[i] = malloc((i+1)*sizeof(int));
    }
    
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < (i+1); j++) {
            if (j == 0 || j == i) {
                ret[i][j] = 1;
            } else {
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
    }
    
    return ret; 
}
