#include <stdio.h>

void bubble_sort(int n, int num[n])
{
    int i,j;
    for(i = 0; i < n; i++) {
        for (j=0; j < (n-1)-i; j++) {
           if (num[j]>num[j+1]) {
               int tmp = num[j];
               num[j] = num[j+1];
               num[j+1] = tmp;
           }
        }
    }
    for (int k = 0; k < n; k++) {
        printf("%d ", num[k]);
    }
}

int main(void)
{
    int num[6] = {108, 4, 6, 23, 1, 9};
    bubble_sort(6, num);
    return 0;
}
