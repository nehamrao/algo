#include <iostream>
#include <vector>
#include <map>
using namespace std;

class PhoneNum {
  public:
    map<int, vector<char> > lmap;
    
    void createMap()
    {
        // Insert numbers 0 to 9 and their corresponding characters 
        vector<vector<char> > v;
        
        
        vector<char> zero;
        zero.push_back('+');
        v.push_back(zero);
        
        vector<char> one;
        one.push_back('1');
        v.push_back(one);
        
        vector<char> two;
        two.push_back('A');
        two.push_back('B');
        two.push_back('C');
        v.push_back(two);

        
        vector<char> three;
        three.push_back('D');
        three.push_back('E');
        three.push_back('F');
        v.push_back(three);

        vector<char> four;
        four.push_back('G');
        four.push_back('H');
        four.push_back('I');
        v.push_back(four);

        
        vector<char> five;
        five.push_back('J');
        five.push_back('K');
        five.push_back('L');
        v.push_back(five);

        vector<char> six;
        six.push_back('M');
        six.push_back('N');
        six.push_back('O');
        v.push_back(six);

        
        vector<char> svn;
        svn.push_back('P');
        svn.push_back('Q');
        svn.push_back('R');
        svn.push_back('S');
        v.push_back(svn);

        vector<char> eht;
        eht.push_back('T');
        eht.push_back('U');
        eht.push_back('V');
        v.push_back(eht);

        
        vector<char> nine;
        nine.push_back('W');
        nine.push_back('X');
        nine.push_back('Y');
        nine.push_back('Z');
        v.push_back(nine);
        
        for (int i = 0; i <= 9; i++) {
            makeMapKeyVal(i, &v);
        }
        
        printMap();
        
    }
    
    void getPhonePerm (vector<int> inp)
    {
        vector<vector<char> > result;
        vector<char> partial;
        
        getPhonePermHelper(&inp, &result, &partial, 0);
        
        printVector(&result);
        return;
    }
  
  
  private:
    
    void printSinVector(vector<char> v){
        
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i);
        }
        cout << "\n";
    }
    
    void printVector(vector<vector<char> > *v) {
        cout << "Permuations are: \n";
	int cnt = 0;

        for (int i = 0; i < v->size(); i++) {
            vector<char> c = v->at(i);
            for (int j = 0; j < c.size(); j++) {
                cout <<c[j];
            }
	    cnt++;
	    cout << "\n";
        }
	cout << "A total of " << cnt <<" permutations\n";
    }
    
    void printMap()
    {
        for (std::map<int, vector<char> >::iterator it = lmap.begin(); it != lmap.end(); it++) {
            cout << "Key : " << it->first;
            vector<char> letters = it->second;
            cout << " Val : ";
            for (int i = 0; i < letters.size(); i++) {
                cout<<letters[i];
            }
            cout << "\n";
        }
    }
    
    void makeMapKeyVal (int num, vector<vector<char> > *v) {
        lmap[num] = v->at(num); 
    }
    
    
    void getPhonePermHelper(vector<int> *inp, vector<vector<char> > *result, vector<char> *partial, int start)
    {
        if (!inp) {
            cout << "Please enter a valid input\n";
            return;
        }
        
        if (start >= inp->size()) {
            printSinVector(*partial);
            result->push_back(*partial);
            return;
        }
        
        // Iterate over input number. For each num in map, iterate over it's char recursively
        for (int i = start; i < inp->size(); i++) {
            cout << "Start is " << start << "\n"; 
            // Lookup number in map
            std::map<int, vector<char> >::iterator it = lmap.find(inp->at(i));
            vector<char> letter;            

            if (it != lmap.end()) {
                letter = it->second;
            }
                        
            for (int j = 0; j < letter.size(); j++) {
                    // Add current letter to partial
                    partial->push_back(letter[j]);
                    getPhonePermHelper(inp, result, partial, start+1);
                    partial->pop_back();
            }
        }
    }
};



int main() {
    
    PhoneNum p;
    p.createMap();
    vector<int> v;
    v.push_back(3);
    v.push_back(0);
    p.getPhonePerm(v);
    return 0;
}
