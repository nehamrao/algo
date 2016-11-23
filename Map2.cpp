#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

template <typename K, typename V>
class OrderedMap
{
  public:
    /*OrderedMap(int size) {
        gmap.resize(size);        
    }*/
    
    void insert (K key, V val) {
        MapElem elem;
        elem.key = key;
        elem.val = val;
        gmap.push_back(elem);
    }      

    void update (K key, V val) {
        for (int i = 0; i < gmap.size(); i++) {
            if (gmap[i].key == key) {
                gmap[i].val = val;
            }
        }
    }
    
    V getValue (K key) {
        for (int i = 0 ; i < gmap.size(); i++) {
            if (gmap[i].key == key) {
                return gmap[i].val;
            }
        }
        cout << "Key " << key << " is not present in ordered map\n";
    }
    
    void printMap () {
        for (int i = 0 ; i < gmap.size(); i++) {
            cout << "Index " << i <<" Key: " << gmap[i].key << " Value: " << gmap[i].val << "\n";
        }
    }

  private:
    class MapElem {
      public:
        K key;
        V val;
    };
    vector<MapElem> gmap;
};    

int main() {
    OrderedMap<int, string> ord_map;
    
    for (int i = 0 ; i < 10; i++) {
        string s = to_string(5*i);
        ord_map.insert(i + 10, s + "NMR");
    }
    ord_map.printMap();
    cout << "Test getValue " << ord_map.getValue(17) << "\n";
    
    return 0;
}
