#include <stdio.h>

int find_area (int A, int B, int C, int D, int E, int F, int G, int H) {
    int res, area1, area2, sub;
    if (A > 0 && B > 0 && C > 0 && D > 0 && E > 0 && F > 0 && G > 0 && H > 0) {
        area1 = (A+C)*(B+D);
        area2 = (E+G)*(F+H);
        sub = (C+E)*(B+H);
    }
   
    if (A < 0 && B < 0 && C < 0 && D < 0 && E < 0 && F < 0 && G < 0 && H < 0) {
        area1 = (-A-C)*(-B-D);
        area2 = (-E-G)*(-F-H);
        sub = (-C-E)*(-B-H);
    } 
    
    if (A < 0 && B < 0 && E < 0 && F < 0) {
        area1 = (-A+C)*(-B+D);
        area2 = (-E+G)*(-F+H);  
        sub = (C-E)*(H-B);
    }

    res = area1 + area2 - sub; 
    return res;
}

int main (void) {
    int res;
    res = find_area(-1,-1,0,0,-1,-1,1,1);
    printf("Area covered by two rectangles is %d\n", res);
    return 0;
}
