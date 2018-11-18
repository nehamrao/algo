struct hash_elem {
    int  val;  
    int  cnt;  
    bool neg;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    
    int i = 0;
    int * copy;
    if (numsSize == 2 && nums[0]!=nums[1]) {
        copy = (int *) malloc(2*sizeof(int));
        memset(copy,nums,2*sizeof(int));
        return copy;
    } 
    
    /*
     * Store the count, value in a has map comprising of
     * an array of struct pointers.
     */
     int n = numsSize; /* The number of keys to hash */
     int m = n/2 + 1; /* The number of slots */
   
     // Create the hash table of m slots
     struct hash_elem *hash_ary[m];
     
     
     for (i = 0 ; i < m; i++) {
         hash_ary[i] = (struct hash_elem *) malloc(sizeof(struct hash_elem *));
         hash_ary[i]->cnt = 0;
     }
     
     for (i = 0; i < n; i++) {
         if (nums[i] < 0) {
             nums[i] = -1*nums[i];
             hash_ary[nums[i]%m]->neg = true;
         } else {
             hash_ary[nums[i]%m]->neg = false;
         }
         hash_ary[nums[i]%m]->val = nums[i];
         hash_ary[nums[i]%m]->cnt++;
         printf("hash_ary [%d], val: %d, cnt: %d\n",nums[i]%m, hash_ary[nums[i]%m]->val,hash_ary[nums[i]%m]->cnt);
     }
     int j = 0;
     static int r[2];
     for (i = 0; i < m; i++) {
         printf("Index %d; val = %d, cnt = %d\n",i,hash_ary[i]->val,hash_ary[i]->cnt);
         if (hash_ary[i]->cnt == 1) {
             if (hash_ary[i]->neg)
                 r[j] = -1*(hash_ary[i]->val);
             else r[j] = hash_ary[i]->val;     
             printf("Return Array is %d\n",r[i]); 
         }
         j++; 
         if (j >= 2) break;
     }
     
     for (i = 0; i < 2; i++)
         printf("r [%d] = %d\n",i,r[i]);
     copy = (int *) malloc(2*sizeof(int));     
     memcpy(copy,r,2*sizeof(int));
     for (i = 0; i < 2; i ++) 
         printf("Copy [%d] = %d\n",i,copy[i]);
         
     return copy;
}
