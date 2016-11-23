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
#include <list>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

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
    
    V *find (K key) 
    {
      for (auto i = vectorMap.begin(); i != vectorMap.end(); i++) {
          if (i->key == key) {
              //cout << "Found Val [" << i->val << "] for Key [" << i->key << "]\n";
              return (&(i->val));
          }
      }
      cout << "Key [" << key << "] not found in map!\n";
      return NULL;
    }
    
    void remove (K key) 
    {
      for (auto i = vectorMap.begin(); i != vectorMap.end(); i++) {
          if (i->key == key) {
              vectorMap.erase(i);
              cout << "Key [" << key << "] removed from map!\n";
              printMap();
              return;
          }
      }
      cout << "Key [" << key << "] not found in map, cannot delete!\n";
    }
    
    void update (K key, V val) 
    {
      for (auto i = vectorMap.begin(); i != vectorMap.end(); i++) {
          if (i->key == key) {
              //cout << "Update of key [" << key << "] with val [" << val << "] done\n";
              i->val = val;
          }
      }    
    }
    
    void printMap ()
    {
      cout << "Printing contents of map\n";
      cout << "-------------------------\n";
      //for (int i = 0; i < vectorMap.size(); i++)
          //cout << "Key [" << vectorMap[i].key << "] <--> Val [" << vectorMap[i].val << "] \n";
    }
    
      void printMapCache()
    {
      cout << "Printing contents of map cache\n";
      cout << "-------------------------------\n";
      //for (int i = 0; i < vectorMap.size(); i++)
          //cout << "Key [" << vectorMap[i].key << "] <--> Val [" << vectorMap[i].val << "] \n";
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



/*
 * Create a server management system which
 * a) inserts a server to a map as the key 
 * and inserts the same to a vector as well 
 * and as a value inserts the index in the vector
 * b) removes a given server from the map, which involves
 * removing that index in the vector as well
 * c) getting a random server on each getServer() request by 
 * generating a random map index and looking it up 
 * in the vector instead. Each index of the vector stores one
 * map entry
 */ 

template <typename T>
class LoadBalancer {
  public:
    void insert (T server) 
    {
      // Insert the server to map & vector
      serverVector.push_back(server);
      serverMap.insert(server, serverVector.size() - 1);
    }
    
    void remove (T server)
    {
      int *idx = serverMap.find(server);

      if (idx) {
          cout << "idx is " << *idx << "\n";
          // Update and remove from vector
          serverVector[*idx] = serverVector[serverVector.size() - 1];
          serverVector.pop_back();
          
          // Update value of key serverVector[*idx] in map
          serverMap.update(serverVector[*idx], *idx);

          // Remove from map
          serverMap.remove(server);
          
          cout << "Server load " << server << " removed\n";
      } else {
          cout << "Server load " << server << " not found, cannot remove\n";
      }
    }
    
    T getRandom (void) {
        int select = rand() % serverVector.size();
        cout << "Select is " << select << "\n";
        return serverVector[select];
    }
    
    void printLoadBalancer (void) 
    {
        cout << "Printing loads in load balancer ...\n";
        cout << "-----------------------------------\n";
        int i;
        for (i = 0; i < serverVector.size() - 1; i++)
            cout << serverVector[i] << ", ";
        cout << serverVector[i] << "\n";
        
    }
    
  private:
    Map<T, int> serverMap;
    vector<T> serverVector;
    
};


/*
 * Implement LRU cache using a map and a list.
 * The map stores (data, pointer to data in list)
 * The list stores pointer to the value of the key 
 * in the map.
 * LRU cache has an get(), set() methods
 */
template <typename K, typename V>
class LRUCache  {
  public:
    
    void set (K key, V val)
    {
      // Case 1: Key already exists in cache
      typename list<V>::iterator *it = lruMap.find(key);
      if (it) {
          // Remove corresponding val from list
          lruList.erase(*it);
          lruList.push_back(val); 
          lruMap.update(key, prev(lruList.end()));
      } else {
          lruList.push_back(val);
          lruMap.insert(key, prev(lruList.end()));
      }
      
    }
    
    void printCache ()
    {
      lruMap.printMapCache();
      int i = 0;
      for (auto it = lruList.begin(); it != lruList.end(); it++) {
          cout << "Val [" << *it << "] Idx [" << i << "]\n";
          i++;
      }
          
    }
    
    V* get (K key) {
        typename list<V>::iterator *it = lruMap.find(key);
        V* ret = NULL;
        if (it) {
            // Update vector
            lruList.push_back(**it);
            ret = &(**it);
            lruList.erase(*it);
            lruMap.update(key, prev(lruList.end()));
        }
        
        return ret;
    }
    
  private:
    Map<K, typename list<V>::iterator> lruMap;
    list<V> lruList;
}; 


int main() {
    Map<int, int> m;
    
    // Test map implementation
    /*m.insert(3,4);
    m.insert(10,5);
    m.printMap();
    int *val = m.find(3);
    val = m.find(14);
    m.remove(3);
    m.printMap();*/
    
    //Test load balancer
    LoadBalancer<string> load;
    load.insert("Guddi");
    load.insert("Gudda");
    load.insert("Bana");
    load.insert("Banlu");
    load.printLoadBalancer();
    
    /*int i = 15;
    while(i > 0) {
     cout << "Testing random GET, got load --> " << load.getRandom() << "\n";
     --i;
    }*/
    
    load.remove("Gudda");
    load.printLoadBalancer();
    
    // Test LRU cache
    LRUCache<int,int> cache;
    cache.set(10, 20);
    cache.set(11, 22);
    cache.set(13, 23);
    cache.set(11, 22);
    cache.printCache();
    int *ret = cache.get(13);
    cout << *ret;

    return 0;
}
