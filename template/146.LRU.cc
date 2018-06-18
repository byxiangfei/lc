/*
[146.LRU Cache] (https://leetcode.com/problems/lru-cache)

* algorithms
* Hard (18.85%)

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Follow up:
Could you do both operations in O(1) time complexity?
Example:
LRUCache cache = new LRUCache( 2 );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class TimeMap {
public:
     // get returns the value which is earlier than given time.
     string get(int key, int t) {
          if(!timeMap.count(key)) return ("error: not such key");
          auto tv = timeMap[key];
          auto it = tv.lower_bound(t);  // return the first larger than t
          if(it == tv.end()) return tv.rbegin()->second;  // return last value
          if(it->first == t) return it->second;   		  // if equal, return

          if(it != tv.begin()) {
          	it--;
          	return it->second;
          }
          return "no value";
     }

     void set(int key, int t, string value) {
          timeMap[key][t] = value;
     }

private:
     unordered_map<int, map<int, string>>timeMap;  // timeMap[key][time][value];
};


int main() {
	TimeMap t;
	t.set(3, 1, "value1");
	t.set(3, 4, "value");
	cout<<t.get(3,0)<<endl;
}