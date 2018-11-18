#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
 * Function to find length of string
 */
int str_len (char *a) {

    int count =  0;
    int i;
    for (i = 0; a[i] != '\0'; i++) {
       count++;
    }
    return count;
}

/*
 * Function to determin if string a
 * is an anagram of string b.
 */
bool 
is_anagram(char *a,char *b) {
    int i = 0, j = 0;
    bool ret = true;
    int l1, l2; 
    
    //STEP 0 : Find length of input strings
    l1 = str_len (a);
    l2 = str_len (b);
    
    //STEP 1: If input strings are of different lengths, return false
    if (l1 != l2) 
        return false;

    //STEP 3: Cast the input char arrays to int ary   
    int x[l1];
    int y[l2]; 
    
    for (i = 0 ;i < l1; i++) {
        x[i] = (int) a[i];
    }
 
    for (j = 0 ;j < l2; j++) {
        y[j] = (int)b[j];
    }
    
    //STEP 4: Declare 2 arrays of size 128 and increment
    //        the ascii index of the char in the array
    int rx[128] = {0};
    int ry[128] = {0};   
 
    for (i = 0; i < l1; i++) {
        rx[x[i]] = rx[x[i]] + 1;
    }

    for (i = 0; i < l2; i++) {
        ry[y[i]] = ry[y[i]] + 1;
    }
     
    //STEP 5: Compare the two ascii index incremented arrays
    for (i = 0; i < 128; i++ ) {
        if (rx[i]!=ry[i])
            return false;
    }

    return true;
}

int main (void) {
    bool valid;
    char *a = "qwerty";
    char *b = "y23rwq";
    valid = is_anagram(a,b);
    printf("String a %s an anagram of string b\n", 
           valid == true ? "is" : "is not");
    return 0;
}
