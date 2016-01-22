#include <cstdio>
#include <list>

using namespace std;

// a manificent use of stack

const int MAXN = 100005;

struct Node {
    long long val;
    int index;
    Node(){}
    Node(long long v, int i): val(v), index(i) {}
};

long long a[MAXN], s[MAXN];
int left[MAXN], right[MAXN];

inline long long min(long long x, long long y) {
    return x < y ? x : y;
}

inline long long max(long long x, long long y) {
    return x > y ? x : y;
}

list<Node> stk;
list<Node> stk_inv;

void stack_op(int i) {
    if(stk.empty()) {
        stk.push_back(Node(a[i], i));
        //left[i] = 0;
        return;
    }
    if(a[i] >= stk.back().val) {
        stk.push_back(Node(a[i], i));
        //left[i] = stk.back().index;
        return;
    }
    while(!stk.empty() && a[i] < stk.back().val) {
        Node node = stk.back();
        right[node.index] = i - 1;
        stk.pop_back();
    }
    stack_op(i);
}

void stack_op_inv(int i) {
    if(stk_inv.empty()) {
        stk_inv.push_back(Node(a[i], i));
        return;
    }
    if(a[i] >= stk_inv.back().val) {
        stk_inv.push_back(Node(a[i], i));
        return;
    }
    while(!stk_inv.empty() && a[i] < stk_inv.back().val) {
        Node node = stk_inv.back();
        left[node.index] = i + 1;
        stk_inv.pop_back();
    }
    stack_op_inv(i);
}

int n;

int main(int argc, char const *argv[])
{
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", a + i);
            left[i] = -100;
            right[i] = n + 100;
        }
        s[0] = a[0];
        for(int i = 1; i < n; i++) {
            s[i] = s[i - 1] + a[i];
        }
        stk.clear();
        stk_inv.clear();
        for(int i = 0; i < n; i++) {
            stack_op(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            stack_op_inv(i);
        }
        long long best = 0, pos = -1;
        for(int i = 0; i < n; i++) {
            int l = left[i] - 1, r = right[i];
            long long tmp;
            if(r > n - 1) r = n - 1;
            if(l >= 0) {
                tmp = a[i] * (s[r] - s[l]);
            }
            else {
                tmp = a[i] * s[r];
            }
            if(best < tmp) {
                best = tmp;
                pos = i;
            }
            //printf("%d %d\n", left[i], right[i]);
        }
        int ans_l = left[pos] + 1 >= 1 ? left[pos] + 1 : 1, ans_r = right[pos] + 1 <= n ? right[pos] + 1 : n;
        printf("%lld\n%d %d\n", best, ans_l, ans_r);
    }
    return 0;
}
