#include <cstdio>
#include <stack>

using namespace std;

int n, m;

const int MAXN = 16;
const int MAXM = 12005;
int a[MAXM], b[MAXM];

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        stack<int> p[4];
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a[i], &b[i]);
        }
        for(int i = n; i >= 1; i--){
            p[1].push(i);
        }
        int output = 0;
        for(int k = 0; k < m; k++) {
            int op1 = a[k], op2 = b[k];
            if(p[op1].empty()) {
                output = -(k + 1);
                break;
            }
            int disk = p[op1].top();
            if(!p[op2].empty() && disk > p[op2].top()) {
                output = -(k + 1);
                break;
            }
            p[op1].pop();
            p[op2].push(disk);
            if(p[3].size() == n){
                output = k + 1;
                break;
            }
        }
        printf("%d\n", output);
    }
    return 0;
}
