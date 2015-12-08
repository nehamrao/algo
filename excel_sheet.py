""" Write a method to convert the letters in an excel sheet column index to numbers """

import string
from math import pow

class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        dict = {'A':1,'B':2, 'C':3,'D':4,'E':5, 'F':6, 'G':7, 'H':8, 'I':9,
                'J':10, 'K':11, 'L':12, 'M':13, 'N':14, 'O':15,'P':16, 'Q':17,
                'R':18, 'S':19, 'T':20, 'U':21, 'V':22, 'W':23, 'X':24, 'Y':25, 'Z':26
                };
        s1 = str(s)        
        num = 0
        i=0
        
        # Use a dictionary to store the alphabets and corresponding numbers. 
        # Use the base 26 system to determine the return value while iterating 
        # over the characters of the string in reverse order
        for letter in s1[::-1]:
            num = num + dict.get(letter)*pow(26,i)
            i = i + 1
        return int(num)    
            
            
