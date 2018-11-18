#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int getlen (int a) 
{
    int count = 0;
    while (a != 0) {
        a = a/10;
        count++;
    }
    return count;
}

int karatsuba (int x, int y)
{
    
    // Base case
    if (x < 10 || y < 10)
	    return x*y;

    int lenx = getlen(x);
    int leny = getlen(y);
    
    int a = x/pow(10, lenx/2);
    int b = x - (a * pow(10, lenx/2));
    int c = y/pow(10, leny/2);
    int d = y - (c * pow(10, leny/2));


    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int abcd = karatsuba(a+b, c+d) - ac - bd;

    return (pow(10, lenx)*ac + pow(10, lenx/2)*abcd + bd);
}

int main ()
{
    string x;
    string y;
    std::cout << "Enter two numbers to multiply: \n";
    getline(cin, x);
    getline(cin, y);
    
    int x_val  = stoi(x);
    int y_val  = stoi(y);
     
    // Pass to karatsuba routine
    int product = karatsuba(x_val, y_val);
    cout << "Product is: " << product << "\n";
    return 0;
}
