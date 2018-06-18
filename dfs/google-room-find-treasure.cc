/*
有很多房间，有些房间有钥匙，有一个房间有宝藏，求是否能从给定的房间出发找到宝藏
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;


class Room {
public:
	int roomId;
	int openKey;   // -1 for no need key
	vector<Room*> neighbors;  
	bool hasTreasure;
};

bool canFindTreasure(Room *room) {
	unordered_set<int> visited;  //visited rooms
	unordered_set<int> keyInHands;  

	bool found = false; 
	queue<Room*> q; // to be visited
	q.push(room);

	while(!q.empty()) {
		auto r = q.front(); q.pop();
		if(visited.count(r->roomId)) continue;
		visited.insert(r->roomId);
		if(r->hasTreasure) return true;
		if(keyInHands.count(r->openKey))




	}



}
