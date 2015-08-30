#include <stdio.h>
#include <stdlib.h>

int floor_fn (int n) {
    if (n%2 == 0) {
        return n/2;
    } else return (n-1)/2;
        
}

int ceil_int(int x)
{
    int result;
    if (x%2 == 0)
       result = x/2;
    else
       result = x/2 + 1;
    return result;
}

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

int majorityElement (int *a, int n) {
   
    //Find the floor of n/2
    int flr = floor_fn(n);
    
    //Sort the array
    a = merge_sort(n,a);

    int i = 0;
    for (; i < n; i ++)
        printf("a[%d] = %d, ",i,a[i]);
    printf(" \n");   

    i = 0;
    int count = 0;
    int j = 1;

    //Count keeps track of the number of times an element occurs
    while (i < n) {
        while (a[i] == a[j]) {
            j++;
            count++;
            if (count >= flr)
                return a[i];
     
        }
        i++;
    }

}

int main (void) {
    int a[4] = {3,4,5,5};
    int maj = majorityElement (a,4);
    printf ("The majority element is %d\n", maj);
    return 0;
}
