#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

map<string,set<string> > dict;
char buf[64];

string hash_value(const string &str) {
    int len = str.length();
    strcpy(buf, str.c_str());
    buf[len] = '\0';
    sort(buf, buf + len);
    string newstr = string(buf);
    return newstr;
}

int main(int argc, char const *argv[])
{
    string line;
    while(cin >> line) {
        if(line=="XXXXXX") break;
        dict[hash_value(line)].insert(line);
    }
    while(cin >> line) {
        if(line=="XXXXXX") break;
        string hash = hash_value(line);
        if(dict.count(hash)==0) cout << "NOT A VALID WORD" << endl;
        else{
            set<string> &sset = dict[hash];
            for(set<string>::iterator it = sset.begin(); it != sset.end(); it++){
                cout << *it << endl;
            }
        }
        cout << "******" << endl;
    }
    return 0;
}
