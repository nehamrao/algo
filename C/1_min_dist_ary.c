#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ceilfn (int n)
{
    if (n%2 == 0) {
        return n/2;
    } else {
        return (n/2 + 1);
    }
}

void merge (int *a, int sizea, int *b, int sizeb, int *c, int sizec)
{
    int k = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < sizec; i++) {
        if (sizea == 0) {
            c[i] = b[i];
        } else if (sizeb == 0) {
            c[i] = a[i];
        } else {
            if (a[j] < b[k]) {
                c[i] = a[j];
                j++;
            } else {
                c[i] = b[k];
                k++;
            }
        }
    }
}

int *merge_sort(int n, int *a)
{
    if (n == 1)
        return a;   
 
    int sizea = ceilfn(n);
    int sizeb = n - sizea;

    int *m = malloc(sizea*sizeof(int));
    int *l = malloc(sizeb*sizeof(int));

    int i, j;
    for (i = 0; i < sizea; i++) {
        m[i] = a[i];
    }
    m = merge_sort(sizea, m);
    
   for ( j = sizea; j < n; j++) {
        l[j - sizea] = a[j];
    }
    l = merge_sort(sizeb, l);
    
    int *res = malloc(n*sizeof(int));
    merge(m, sizea, l, sizeb, res, n);

    return res; 
}

int main (void)
{
    int n = 6;
    
    int a[6] = {4, 6, 22, 56, 78, 3};
    int *b = merge_sort(n, a);
    
    int i = 0;
    for (i = 0 ; i < n; i++) {
        printf("%d, ", b[i]);
    } printf ("\n");

    // Find the min distance between any two elements
    int min = abs(b[0] - b[1]);
    for (i = 1 ; i < (n-1); i++) {
        if (abs(b[i]-b[i+1]) < min) {
            min  = abs (b[i]-b[i+1]);
        }
    }
    printf ("The min is %d\n", min);
    free(b);
}
