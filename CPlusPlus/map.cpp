/*
 * Map
 * - Constructor
 * - Insert
 * - Remove
 * - Find
 * - getRandom
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/*
 * Template for map of any (key, val) type
 */
template <typename K, typename V>
class Map {
  public:
    
    void insert (K k, V v)
    {
      mapNode item(k,v);
      vectorMap.push_back(item);  
    };
    
    V *find (K key) {
      for (auto i = vectorMap.begin(); i != vectorMap.end(); i++) {
          if (i->key == key) {
              cout << "Found Val [" << i->val << "] for Key [" << i->key << "]\n";
              return (&(i->val));
          }
      }
      cout << "Key [" << key << "] not found in map!\n";
      return NULL;
    }
    
    void remove (K key) {
      for (auto i = vectorMap.begin(); i != vectorMap.end(); i++) {
          if (i->key == key) {
              vectorMap.erase(i);
              cout << "Key [" << key << "] removed from map!\n";
              return;
          }
      }
      cout << "Key [" << key << "] not found in map, cannot delete!\n";
    }
    
    void printMap ()
    {
      cout << "Printing contents of map\n";
      for (int i = 0; i < vectorMap.size(); i++)
          cout << "Key [" << vectorMap[i].key << "] <--> Val [" << vectorMap[i].val << "] \n";
    }
    
  private:
    class mapNode {
      public:

        K key;
        V val;

        mapNode (K key, V val)
        {
          this->key = key;
          this->val = val;
        }
    };
    vector<mapNode> vectorMap;
};



int main() {
    Map<int, int> m;
    
    // Test map implementation
    m.insert(3,4);
    m.printMap();
    int *val = m.find(3);
    val = m.find(14);
    m.remove(3);
    m.printMap();
    
    return 0;
}
