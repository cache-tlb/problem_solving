#include <iostream>
#include <set>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string line;
    while(cin >> n){
        if(!n) break;
        cin >> line;
        set<char> s;
        int len = line.length();
        int tot = 0;
        for(int i = 0; i < len; i++){
            char id = line[i];
            if(s.count(id) > 0) {
                //cout << id << " out" << endl;
                s.erase(id);
            }
            else{
                //cout << id << " in" << endl;
                s.insert(id);
                if(s.size() > n) tot++;
            }
        }
        if(!tot){
            cout << "All customers tanned successfully." << endl;
        }
        else{
            cout << tot << " customer(s) walked away." << endl;
        }
    }
    return 0;
}
