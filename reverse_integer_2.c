/* Reverse an integer and take care of overflow condition */
int reverse(int x) {
    
    bool neg = false;
    long ret = 0;

    
    if ( x < 0) {
        neg = true;
        x = 0-x;
    }
    
    
    while (x != 0) {
        ret = ret * 10 + x % 10;
        x = x / 10;
    }
    
    if (neg) {
        ret = -1*ret;
    } 
 
    if (ret > INT_MAX || ret < INT_MIN) {
        return 0;
    }
    
    return (int) ret;
}
