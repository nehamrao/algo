#include <stdio.h>

/*
 * Insertion sort involves pulling out a say kth 
 * element of the input array and inserting it 
 * S.T in the invariant section of the array
 * which is sorted in increasing order.
 */
void insertion_sort_api(int n, int inp[])
{
    //Sort the input
    int j;
    int key;
    for (j = 1; j < n; j++)
    {	//Pull out the key
        key = inp[j];
        int l;
        for (l=j-1; l>=0 ; l=l-1)
        {
            if (inp[l]>key) {
                inp[l+1]=inp[l];
                inp[l] = key;
            } 
         }
    }
    printf("\nSorted Array is\n");
    for (j = 0; j < n; j++)
    {
        if (j != (n-1))
            printf("%d ", inp[j]);   
        else if (j == (n-1)) 
            printf("%d \n", inp[j]);
    }
}

int main(void)
{
    int inp_ary[7] = {678, 0 , -1 , 23, 2, 3, 89};
    insertion_sort_api(7,inp_ary); 
    return 0;
}
