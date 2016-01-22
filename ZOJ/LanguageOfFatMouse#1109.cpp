#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string line;
    map<string, string> dict;
    while(getline(cin, line)) {
        if(line=="") break;
        istringstream iss(line);
        string s1, s2;
        iss >> s1 >> s2;
        dict[s2] = s1;
    }
    while(getline(cin, line)){
        if(dict.count(line) <= 0) cout << "eh" << endl;
        else cout << dict[line] << endl;
    }
    return 0;
}
