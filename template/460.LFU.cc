/*
[460] LFU Cache

https://leetcode.com/problems/lfu-cache

* algorithms
* Hard (24.46%)

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

*/

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Node{
public:
	int val;
	int freq;
	list<int>::iterator it;
	Node(int v): val(v), freq(1) {};
	Node(): val(-1), freq(-1) {};
};


class LFU{
private:
	unordered_map<int, Node> m;
	unordered_map<int, list<int>> freq;
	int cap;
	int minFreq;

public:
	LFU(int c): cap(c) {};
	int get(int key) {
		if(m.count(key) == 0) return -1;
		freq[m[key].freq].erase(m[key].it);
		m[key].freq++;
		freq[m[key].freq].push_front(key);
		m[key].it = freq[m[key].freq].begin();
		if(freq[minFreq].size() == 0) minFreq++;
		return m[key].val;
	}

	void put(int key, int val) {
		if(cap <= 0) return ;
		if(get(key) != -1) {
			m[key].val = val;
			return;
		}
		if(cap == m.size()) {
			m.erase(freq[minFreq].back());
			freq[minFreq].pop_back();
		}
		m[key] = {Node(val)};  //这里也要注意
		minFreq = 1;
		freq[1].push_front(key);
		m[key].it = freq[1].begin();
	}
};



int main() {
	LFU l(2);
	l.put(1,1);
	l.put(2,2);
	cout<<l.get(2)<<endl;
	cout<<l.get(1)<<endl;
	l.put(3,3);
	cout<<l.get(3)<<endl;
	cout<<l.get(2)<<endl;
	cout<<l.get(1)<<endl;

	return 0;
}
