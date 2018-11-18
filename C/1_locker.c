#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int i, j;
    bool l[100];
    int n = 100;    

    for (i = 1; i < 100; i ++) {
        l[i] = false;
    }

    for (i = 2; i < n; i++) {
        for (j = i ; j < 100; j=j+i) {
            if (j % 2 == 0) {
              l[j] = true;
	    } else {
              l[j] = false;
	    }
        }
    }
    
    for (i = 1; i < 100; i++) {
        if (l[i] == true) {
            printf ("%d, \n", i);
        }
    }
}

