#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/* simple Huffman code*/

int main(int argc, char const *argv[])
{
    string s;
    while(cin >> s) {
        if(s=="END") break;
        int cnt[128];
        memset(cnt, 0, sizeof(cnt));
        int len = s.length();
        for(int i = 0; i < len; i++) {
            cnt[s[i]]++;
        }
        priority_queue<int> pq;
        for(int i = 0; i < 128; i++){
            if(cnt[i]){
                pq.push(-cnt[i]);
            }
        }
        int sum = 0;
        if(pq.size() == 1){
            printf("%d %d %.1lf\n", len*8, len, double(len*8)/double(len));
            continue;
        }
        while(pq.size() >= 2) {
            int n1 = pq.top(); pq.pop();
            int n2 = pq.top(); pq.pop();
            int n = n1 + n2;
            pq.push(n);
            sum += n;
        }
        printf("%d %d %.1lf\n", len*8, -sum, double(len*8)/double(-sum));
    }
    return 0;
}
