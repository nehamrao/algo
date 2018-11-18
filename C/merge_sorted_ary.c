/*
 * Given two sorted integer arrays nums1 and nums2, 
 * merge nums2 into nums1 as one sorted array.
 * You may assume that nums1 has enough space (size 
 * that is greater or equal to m + n) to hold additional 
 * elements from nums2. The number of elements initialized 
 * in nums1 and nums2 are m and n respectively.
 */
void merge(int* nums1, int m, int* nums2, int n) {
    
    int *ret = malloc((m+n)*sizeof(int));
    
    int i , j = 0, k = 0;
    for (i = 0; i < (m+n); i++){
        if (j == m) {
            ret[i] = nums2[k];
            k++;
        } else if (k == n) {
            ret[i] = nums1[j];
            j++;
        } else {
            if (nums1[j] < nums2[k]) {
                ret[i] = nums1[j];
                j++;
            } else {
                ret[i] = nums2[k];
                k++;
            }
        }
    }

    for (i = 0; i < (m+n); i++) {
        nums1[i] = ret[i];
    }
}
