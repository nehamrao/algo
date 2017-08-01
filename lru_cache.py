""" LRU Cache using linked list and map p"""

import unittest

class LRU_Cache(object):
    
    def __init__(self):
        self.mapper = {}
        self.lru_list = []
    
    def cache_set(self, key, val):
        # If key is in map, already in cache
        if key in self.mapper:
            # Recently accessed, move to end of list
            self.lru_list.pop(self.mapper[key])
        # Defaults to key is not in map
        self.lru_list.append(val)
        self.mapper[key] = len(self.lru_list) - 1 # Listindex from 0
    
    def cache_get(self, key):
        # If found in map
        if key in self.mapper:
            list_idx = self.mapper[key]
            val = self.lru_list.pop(list_idx)
            self.lru_list.append(val)
            self.mapper[key] = len(self.lru_list) - 1
            return val
        else:
            return None

class UnitTestLRUCache(unittest.TestCase):
    cache =  LRU_Cache()
        
    def setUp(self):
        UnitTestLRUCache.cache.cache_set(10,20)
        UnitTestLRUCache.cache.cache_set(11,21)
        UnitTestLRUCache.cache.cache_set(12,2)
            
    def test_cache_hit(self):
        val = UnitTestLRUCache.cache.cache_get(12)
        print val
        self.assertEquals(val, 2)
        self.assertIsNotNone(val)
        pass
        
    def test_cache_miss(self):
        val = UnitTestLRUCache.cache.cache_get(16)
        self.assertIsNone(val)
        pass
    

def main():
    # Execute stuff
    unittest.main()
    
if __name__ == '__main__':
    main()

