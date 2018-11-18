#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct interval {
   int a;
   int b;
};

//Populating the interval struct with input values
struct interval *create_intervals(int d1, int d2) {
    struct interval *interval = (struct interval*) malloc(sizeof(struct interval));
    
    interval->a = d1;
    interval->b = d2;
    return interval;
}

/*
 * Given two intervals, find if they overlap.
 * Intervals are in the form of a struct
 */
bool is_interval (struct interval *A, struct interval *B) {
    struct interval *first, *second;

    if (A->a <= B->a) {	
	first = A; second = B; 
    } else { 
	first = B; second = A; 
    }

    return second->a <= first->b;
}

int main (void) {
    struct interval *one =  create_intervals (2,10); 
    struct interval *two =  create_intervals (-1,13); 
    
    //Can either use a pointer to the struct or the struct itself.
    //When a struct is used, pass the pointer to the struct to change its members
    struct interval three;
    three.a = 10;
    three.b = 20;    
    bool ret = is_interval(one,&three);
    printf("Input intervals %s overlap\n", ret == true ? "do":"don't");
    return 0;

}
