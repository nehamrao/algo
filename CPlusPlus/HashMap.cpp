#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

/*
 * Hash Map implementation (get(), put())
 */
template<typename K, typename V>
class HashMap
{
  public:
    HashMap (int size) {
        hashBuckets = size;
        gvec.resize(size);
    }
    
    void put (K key, V val) {
        int idx = hashKey(key);
        HashElem elem;
        elem.key = key;
        elem.val = val;
        gvec[idx].push_back(elem);
    }
    
    int hashKey (K key) {
        size_t key_hash = std::hash<K>()(key);
        return key_hash%hashBuckets;
    }
    
    void printHashMap ()
    {
        for (int i = 0; i < gvec.size(); i++) {
            for (auto it = gvec[i].begin(); it != gvec[i].end(); it++) {
                HashElem elem = *it;
                cout << "Idx: " << i << " Key: " << elem.key << " Val: " << elem.val << "\n";
            }
        }     
    }
    
    V get (K key) {
        int idx = hashKey(key);
        for (auto it = gvec[idx].begin(); it != gvec[idx].end(); it++) {
            if ((*it).key == key) {
                return (*it).val;
            }
        }
        cout << "Key " << key << " is not stored in the hashmap\n";
    }
    
  private:
    class HashElem {
      public:
        K key;
        V val;
    };
    
    vector<list<HashElem>> gvec;
    
    int hashBuckets;
};



int main() {
    HashMap<string, string> hmap(5);
    
    for (int i = 1; i <= 10; i++) {
        hmap.put("10" + to_string(i), "20" + to_string(2*i));
    }
    hmap.printHashMap();
    cout << " HashMap get : " << hmap.get("106") << "\n";
    return 0;
}



