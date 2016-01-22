#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

const int MAX = 1000 + 10;
struct state{
    int a;
    int b;
    string step;
};
int ca, cb, n;

state fillA(state s)
{
    s.a = ca;
    s.step += "fill A\n";
    return s;
}
state fillB(state s)
{
    s.b = cb;
    s.step += "fill B\n";
    return s;
}
state emptyA(state s)
{
    s.a = 0;
    s.step += "empty A\n";
    return s;
}
state emptyB(state s)
{
    s.b = 0;
    s.step += "empty B\n";
    return s;
}
state pourAB(state s)
{
    state ans = s;
    int d = cb - s.b;
    if(d >= s.a){
        ans.a = 0;
        ans.b += s.a;
    }
    else{
        ans.a -= d;
        ans.b = cb;
    }
    ans.step += "pour A B\n";
    return ans;
}
state pourBA(state s)
{
    state ans = s;
    int d = ca - s.a;
    if(d >= s.b){
        ans.b = 0;
        ans.a += s.b;
    }
    else{
        ans.b -= d;
        ans.a = ca;
    }
    ans.step += "pour B A\n";
    return ans;
}
void bfs(){
    map<int,int> m;
    vector<state> v;
    state starter;
    starter.a = 0;
    starter.b = 0;
    starter.step = "";
    m[0] = 1;
    v.push_back(starter);
    int i = 0,flag = 0;
    while(i < v.size()){
        if(v[i].b == n){
            flag = 1;
            break;
        }
        state temp[6];
        temp[0] = fillA(v[i]);
        temp[1] = fillB(v[i]);
        temp[2] = emptyA(v[i]);
        temp[3] = emptyB(v[i]);
        temp[4] = pourAB(v[i]);
        temp[5] = pourBA(v[i]);
        for(int k = 0; k < 6; k++){
            int num = temp[k].a*MAX + temp[k].b;
            if(!m[num]){
                m[num] = 1;
                v.push_back(temp[k]);
            }
        }
        i++;
    }
    if(flag) cout << v[i].step << "success" <<endl;
}
int main()
{
    
    while(cin >> ca >> cb >> n){
        bfs();
    }    
    return 0;
}
