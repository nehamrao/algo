/*
 * Determine if an integer is a power of 3 or not.
 */

bool isPowerOfThree(int n) {
   
   if (n == 1) {
       return true;
   }
   
   if (n == 0)
    return false;
   
   if (n%3 == 0) {
       while (n%3 == 0 || n == 1) {
           if (n == 1)
            return true;
           n = n/3;
       }
       return false;
   } else {
       return false;
   }
}
