#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <string>

using namespace std;

struct MSG
{
	string name;
	int time_stamp;
	int priority;
	int parameter;
};

bool operator < (const MSG &a, const MSG &b){
	return (a.priority < b.priority) || (a.priority == b.priority && a.time_stamp < b.time_stamp);
}

int main(int argc, char const *argv[])
{
	string cmd;
	int time_stamp = 0;
	priority_queue<MSG> pq;
	while(cin >> cmd){
		if(cmd == "GET"){
			if(pq.empty()){
				cout << "EMPTY QUEUE!" << endl;
			}
			else{
				MSG m = pq.top();
				pq.pop();
				cout << m.name << ' ' << m.parameter << endl;
			}
		}
		else if(cmd == "PUT"){
			MSG m;
			cin >> m.name >> m.parameter >> m.priority;
			//cout << m.name << ' ' << m.parameter << endl;
			m.time_stamp = time_stamp++;
			m.time_stamp = -m.time_stamp;
			m.priority = -m.priority;
			pq.push(m);
		}
	}
	return 0;
}
