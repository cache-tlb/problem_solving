#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(cin >> n){
        if(!n) break;
        string line;
        double d;
        int big = 0, small = 0;
        for(int i = 0; i < n; i++){
            cin >> line;
            string str;
            bool point = false;
            for(int j = 0; j < line.length(); j++){
                if(line[j] >= '0' && line[j] <= '9') {
                    str.push_back(line[j]);
                }
                else if(line[j]=='.'){
                    str.push_back(' ');
                    point = true;
                }
            }
            istringstream in(str);
            int a;
            in >> a;
            big += a;
            if(point){
                in >> a;
                small += a;
            }
        }
        big += small / 100;
        small = small % 100;
        ostringstream os;
        string out = "$";
        os << big;
        string tmp = os.str();
        int len = tmp.length();
        for(int i = 0; i < len; i++){
            if((len-i)%3==0 && i != 0){
                out.push_back(',');
            }
            out.push_back(tmp[i]);
        }
        out.push_back('.');
        ostringstream os2;
        os2 << small;
        if(os2.str().length()<2) out.push_back('0');
        out += os2.str();
        cout << out << endl;
    }
    return 0;
}
