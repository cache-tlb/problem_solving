#include<iostream>
#include<vector>
#include<list>
#include<cstring>
using namespace std;
struct state{
	int reminder;
	vector<int> path;
};
state start;
int visited[210] = {};
int n = 0;
void init()
{
	start.reminder = 1%n;
	start.path.clear();
	start.path.push_back(1);
}

void clear()
{
	memset(visited,0,sizeof(visited));
}

void print_state(state& s)
{
	int len = s.path.size();
	for(int i = 0; i < len; i++){
		cout << s.path[i];
	}
	cout << endl;
}

void dfs()
{
	clear();
	init();
	vector<state> vs;
	vs.push_back(start);
	//visited[start.reminder] = 1;
	int cur = 0;
	while(cur < vs.size()){
		state& s = vs[cur];
		cur++;
		int r = s.reminder;
		if(r==0){
			print_state(s);
			break;
		}
		if(visited[r]){
			continue;
		}
		visited[r] = 1;
		state s1,s2;
		s1.path = s.path;
		s1.path.push_back(0);
		s1.reminder = (r*10)%n;
		s2.path = s.path;
		s2.path.push_back(1);
		s2.reminder = (r*10+1)%n;
		vs.push_back(s1);
		vs.push_back(s2);
	}
}
int main()
{
	while(cin >> n){
		if(n==0){
			break;
		}
		dfs();
	}
	return 0;
}
