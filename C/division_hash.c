#include <stdio.h>
#include <math.h>

void hash(int key[], int n, int m) {
    
    /*
     * 'count' is a local array of integers. Tracks
     * the number of keys allcoated (hashed) to each 
     * of the 'm' slots available. 'hash_idx' can
     * be thought of as an array index in case
     * we had an array of size 'm' representing
     * the 'm+1'th slot.
     */
    int i;
    int hash_idx;
    int count[m];
    count[0]= count[1] = count[2] =0;
    
    for (i = 0; i < n; i++) {
        hash_idx = (key[i] % m);
        printf("key[%d] which is %d <---> slot %d\n",
            i, key[i], hash_idx);
        count[hash_idx] = count[hash_idx] + 1;
    }
    
    /*
     * To see the distribution of how the hashing
     * algorithm has distributed the keys into
     * various slots, the 'count' array can be used 
     */
    int j;
    for (j = 0 ; j < m ; j++)
        printf("Slot %d has %d keys\n",j+1,count[j]);
}

int main (void) {

    /*
     * Basic division hash on n keys and m slots to hash.
     * Has load factor of n/m. Assume 'keys' is an array of
     * integers (size n).    
     */
    int n = 20;
    int keys[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 40, 55, 46, 78, 123,
                  36, 75, 31, 49};
    int m = 3;
    hash(keys,20,3);
 
    return 0;
}

