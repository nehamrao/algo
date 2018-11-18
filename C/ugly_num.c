#include <stdio.h>
#include <stdbool.h>

/*
 * A number is considered ugly if it is 1 or if it
 * has 2,3,5 being the only prime factors of it.
 * All other numbers and -ve numbers are considered
 * not ugly.
 */
bool isUgly (int num) {
    
    //Negative numbers are not ugly
    if (num <= 0)
        return false;
    //1 is an ugly num
    if (num == 1)
        return true;
    /*
     * If num has either 2,3 or 5 as a prime factor,
     * eliminate the num which has any other integer other
     * than 2,3, or 5 as prime factor by dividing.
     */    
    while (num != 1) {
        if (num%2 == 0)
            num = num/2;
        else if (num%3 == 0)
           num = num/3;
        else if (num%5 == 0)
           num = num/5;
        else return false;
    }
    //Here, num == 1 indicates the number is completely divisibe by
    // only 2, 3 or 5 and has no other prime factors.
    return true;
}


int main (void) {
    int x =4;
    bool res = isUgly(x);
    printf("Input %d %s ugly\n", x, res == true? "is" : "is not");
    return 0;
}

