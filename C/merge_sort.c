#include <stdio.h>
#include <stdlib.h>

int ceil_int(int x)
{   
    int result;
    if (x%2 == 0)
       result = x/2;
    else
       result = x/2 + 1;
    return result;
}

/*
 * To merge the two sorted arrays, compare the
 * elements of the two arrays and place the
 * larger/smaller in the resultant array (based
 * on whether it is to be sorted inc or dec order).
 * Keep track of when the split array is completely 
 * traveresed as well
 */
void merge(int size_a, int* a, int size_b, int* b, int n, int* res)
{
    int i;
    int j = 0;
    int k = 0;
    
    for (i = 0; i < n; i++) {
        if (j == size_a) {
	    res[i] = b[k];
	    k++;
	} else if (k == size_b) {
	    res[i] = a[j];
	    j++;
	} else {
        	if (a[j] < b[k]) {
        	    res[i] = a[j];
        	    j=j+1;
        	} else {
        	    res[i] = b[k];
        	    k=k+1;
        	}
	}
    }
}

/*
 * Recursive algorithm
 * Arguments: Reference to input array, size of array
 * 1. If array is of size 1, return
 * 2. Else, split array in two using ceiling fn
 * 3. Malloc memory for the two split arrays &
      populate with input array elements
 * 4. Invoke merge_sort on each split array
 * 5. Merge the two sorted arrays. Pass reference
 *    to the array to store the mergerd, sorted input
 */
int* merge_sort(int n, int inp[])
{
    //If input ary is of size 1, we are done
    if (n == 1) {
        return inp;
    } else {
        int size_a = ceil_int(n);
        int size_b = n - size_a;

        int* a = malloc(size_a*sizeof(int));
        int* b = malloc(size_b*sizeof(int));
        int* res = malloc(n*sizeof(int));
        
        for (int i = 0; i < size_a; i++) {
            a[i] = inp[i];
        }
        a = merge_sort(size_a, a);
        for (int j = size_a; j < n ; j++) {
            b[j-size_a] = inp[j];
        }
        b = merge_sort(size_b, b);

        merge(size_a, a, size_b, b, n, res);
	return res;
    }
}

int main(void)
{
    int inp[9] = {22, 3, 23, 1, 2, 2, 1, 2, 1};
    int* sort = merge_sort(9, inp);

    for (int i = 0; i < 9; i++) {
	printf("%d ", sort[i]);
    } printf("\n");
    return 0;
}
