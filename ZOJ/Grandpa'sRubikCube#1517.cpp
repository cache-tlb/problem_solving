#include<iostream>
using namespace std;
struct edge//定义结构变量edge表示棱边 
{
    char x,y,z;
};
struct vertex//定义结构变量vertex表示角块 
{
    char x,y,z;
};
edge e[13];
vertex v[13];
char f[7];
void D()
{
    e[0]=e[1];
    e[1].x=0;        e[1].y=e[3].x;   e[1].z=e[3].z;
    e[3].x=e[4].y;   e[3].y=0;        e[3].z=e[4].z;
    e[4].x=0;        e[4].y=e[2].x;   e[4].z=e[2].z;
    e[2].x=e[0].y;   e[2].y=0;        e[2].z=e[0].z;
    
    v[0]=v[1];
    v[1].x=v[3].y;   v[1].y=v[3].x;   v[1].z=v[3].z;
    v[3].x=v[4].y;   v[3].y=v[4].x;   v[3].z=v[4].z;
    v[4].x=v[2].y;   v[4].y=v[2].x;   v[4].z=v[2].z;
    v[2].x=v[0].y;   v[2].y=v[0].x;   v[2].z=v[0].z;
    
}
void  F()
{
    e[0]=e[1];
    e[1].x=0;        e[1].y=e[8].y;   e[1].z=e[8].x;
    e[8].x=e[9].z;   e[8].y=e[9].y;   e[8].z=0;
    e[9].x=0;        e[9].y=e[7].y;   e[9].z=e[7].x;
    e[7].x=e[0].z;   e[7].y=e[0].y;   e[7].z=0;
    
    v[0]=v[1];
    v[1].x=v[2].z;   v[1].y=v[2].y;   v[1].z=v[2].x;
    v[2].x=v[6].z;   v[2].y=v[6].y;   v[2].z=v[6].x;
    v[6].x=v[5].z;   v[6].y=v[5].y;   v[6].z=v[5].x;
    v[5].x=v[0].z;   v[5].y=v[0].y;   v[5].z=v[0].x;
      
}
void L()
{
    e[0]=e[3];
    e[3].x =e[7].x;  e[3].y =0;       e[3].z =e[7].y;
    e[7].x =e[11].x; e[7].y =e[11].z; e[7].z =0;
    e[11].x=e[6].x;  e[11].y=0;       e[11].z=e[6].y;
    e[6].x =e[0].x;  e[6].y =e[0].z;  e[6].z =0;
    
    v[0]=v[1];
    v[1].x=v[5].x;   v[1].y=v[5].z;   v[1].z=v[5].y;
    v[5].x=v[7].x;   v[5].y=v[7].z;   v[5].z=v[7].y;
    v[7].x=v[3].x;   v[7].y=v[3].z;   v[7].z=v[3].y;
    v[3].x=v[0].x;   v[3].y=v[0].z;   v[3].z=v[0].y;
    
}
void R()
{
    e[0]=e[2];
    e[2].x =e[5].x;  e[2].y =0;       e[2].z =e[5].y;
    e[5].x =e[10].x; e[5].y =e[10].z; e[5].z =0;
    e[10].x=e[8].x;  e[10].y=0;       e[10].z=e[8].y;
    e[8].x =e[0].x;  e[8].y =e[0].z;  e[8].z =0;
    
    v[0]=v[2];
    v[2].x=v[4].x;   v[2].y=v[4].z;   v[2].z=v[4].y;
    v[4].x=v[8].x;   v[4].y=v[8].z;   v[4].z=v[8].y;
    v[8].x=v[6].x;   v[8].y=v[6].z;   v[8].z=v[6].y;
    v[6].x=v[0].x;   v[6].y=v[0].z;   v[6].z=v[0].y;
    
}
void B()
{
    e[0]=e[4];
    e[4].x =0;       e[4].y =e[6].y;  e[4].z=e[6].x;
    e[6].x =e[12].z; e[6].y =e[12].y; e[6].z=0;
    e[12].x=0;       e[12].y=e[5].y;  e[12].z=e[5].x;
    e[5].x =e[0].z;  e[5].y =e[0].y;  e[5].z=0;
    
    v[0]=v[3];
    v[3].x=v[7].z;   v[3].y=v[7].y;   v[3].z=v[7].x;
    v[7].x=v[8].z;   v[7].y=v[8].y;   v[7].z=v[8].x;
    v[8].x=v[4].z;   v[8].y=v[4].y;   v[8].z=v[4].x;
    v[4].x=v[0].z;   v[4].y=v[0].y;   v[4].z=v[0].x;
    
}
void U()
{
    e[0]=e[9];
    e[9].x =0;       e[9].y =e[10].x; e[9].z =e[10].z;
    e[10].x=e[12].y; e[10].y=0;       e[10].z=e[12].z;
    e[12].x=0;       e[12].y=e[11].x; e[12].z=e[11].z;
    e[11].x=e[0].y;  e[11].y=0;       e[11].z=e[0].z;
    
    v[0]=v[5];
    v[5].x=v[6].y;   v[5].y=v[6].x;   v[5].z=v[6].z;
    v[6].x=v[8].y;   v[6].y=v[8].x;   v[6].z=v[8].z;
    v[8].x=v[7].y;   v[8].y=v[7].x;   v[8].z=v[7].z;
    v[7].x=v[0].y;   v[7].y=v[0].x;   v[7].z=v[0].z;
    
}
void T(int i)
{
    if(i==1) {L();}
    else if(i==2) {F();}
    else if(i==3) {R();}
    else if(i==4) {B();}
    else if(i==5) {U();}
    else if(i==6) {D();}
}
void TR(int i)
{
    if(i==1) {L();L();L();} 
    else if(i==2) {F();F();F();}
    else if(i==3) {R();R();R();}
    else if(i==4) {B();B();B();}
    else if(i==5) {U();U();U();}
    else if(i==6) {D();D();D();}
}
bool check()
{
	if(v[7].z!=f[6] || e[12].z!=f[6] || v[8].z!=f[6]) return false;
	if(e[11].z!=f[6] || e[10].z!=f[6]) return false;
	if(v[5].z!=f[6] || e[9].z!=f[6] || v[6].z!=f[6]) return false;

	if(v[7].x!=f[3] || e[11].x!=f[3] || v[5].x!=f[3]) return false;
	if(e[6].x!=f[3] || e[7].x!=f[3]) return false;
	if(v[3].x!=f[3] || e[3].x!=f[3] || v[1].x!=f[3]) return false;

	if(v[5].y!=f[2] || e[9].y!=f[2] || v[6].y!=f[2]) return false;
	if(e[7].y!=f[2] || e[8].y!=f[2]) return false;
	if(v[1].y!=f[2] || e[1].y!=f[2] || v[2].y!=f[2]) return false;

	if(v[6].x!=f[4] || e[10].x!=f[4] || v[8].x!=f[4]) return false;
	if(e[8].x!=f[4] || e[5].x!=f[4]) return false;
	if(v[2].x!=f[4] || e[2].x!=f[4] || v[4].x!=f[4]) return false;

	if(v[8].y!=f[5] || e[12].y!=f[5] || v[7].y!=f[5]) return false;
	if(e[5].y!=f[5] || e[6].y!=f[5]) return false;
	if(v[4].y!=f[5] || e[4].y!=f[5] || v[3].y!=f[5]) return false;

	if(v[1].z!=f[1] || e[1].z!=f[1] || v[2].z!=f[1]) return false;
	if(e[3].z!=f[1] || e[2].z!=f[1]) return false;
	if(v[3].z!=f[1] || e[4].z!=f[1] || v[4].z!=f[1]) return false;

	return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> v[7].z >> e[12].z >> v[8].z
			>> e[11].z >> f[6] >> e[10].z
			>> v[5].z >> e[9].z >> v[6].z
			>> v[7].x >> e[11].x >> v[5].x
			>> v[5].y >> e[9].y >> v[6].y
			>> v[6].x >> e[10].x >> v[8].x
			>> v[8].y >> e[12].y >> v[7].y
			>> e[6].x >> f[3] >> e[7].x
			>> e[7].y >> f[2] >> e[8].y
			>> e[8].x >> f[4] >> e[5].x
			>> e[5].y >> f[5] >> e[6].y
			>> v[3].x >> e[3].x >> v[1].x
			>> v[1].y >> e[1].y >> v[2].y
			>> v[2].x >> e[2].x >> v[4].x
			>> v[4].y >> e[4].y >> v[3].y
			>> v[1].z >> e[1].z >> v[2].z
			>> e[3].z >> f[1] >> e[2].z
			>> v[3].z >> e[4].z >> v[4].z;
		//cout << v[7].z << e[12].z << v[8].z << endl;
		int op;
		while(cin >> op){
			if(op==0) break;
			if(op>0) T(op);
			else TR(-op);
		}
		bool ok = check();
		if(ok)
			cout << "Yes, grandpa!" << endl;
		else 
			cout << "No, you are wrong!" << endl;
	}
	return 0;
}
