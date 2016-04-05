/*
 * Given a roman numeral, convert it to an integer. 
 * Input is guaranteed to be within the range from 1 to 3999.
 */

int romanLookup(char s)
{
    switch(s) {
        
        case 'I':
            return 1;
            
        case 'V':
            return 5;
            
        case 'X':
            return 10;
            
        case 'L':
            return 50;
            
        case 'C':
            return 100;
            
        case 'D':
            return 500;
            
        case 'M':
            return 1000;
            
        default:
            return 0;
    }
}


int romanToInt(char* s) {
    
    int len = strlen(s);
    int i = 0;
    
    if (len == 0)
        return 0;
 
    int curr;
    int prev = 0;
    int sum = 0;
 
    for (i = len-1 ; i>=0; i=i-1) {
        curr = romanLookup(s[i]);
        
        if (i == len-1) {
          
          sum += curr;  
          
        } else {
        
            if (curr < prev) {
                sum -= curr;
            } else {
                sum += curr;
            }
        } 
        prev = curr;
    }
    return sum;    
}
