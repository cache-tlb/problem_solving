#include <cstdio>
#include <map>
#include <vector>

std::map<int,int> sticks;
std::vector<long long> lens;
std::vector<int> nums;

long long solve() {
    long long res = 0;
    int n = sticks.size();
    lens.clear();
    nums.clear();
    lens.reserve(n);
    nums.reserve(n);
    for (auto it = sticks.begin(); it != sticks.end(); it++) {
        lens.push_back(it->first);
        nums.push_back(it->second);
    }
    // printf("%d %d\n", lens.size(), nums.size());
    for (int i = 0; i < n; i++) {
        if (nums[i] < 2) continue;
        // int tmp = 
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = j + 1; k < n; k++) {
                if (k == i) continue;
                if (lens[i]*2 + lens[j] > lens[k]) {
                    res += ((nums[i]*(nums[i]-1))/2)*nums[j]*nums[k];
                } else  break;
            }
        }
    }
    // printf("%d\n", res);
    for (int i = 0; i < n; i++) {
        if (nums[i] < 3) continue;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (lens[i]*3 > lens[j]) {
                res += ((nums[i]*(nums[i]-1)*(nums[i]-2))/6)*nums[j];
            }
        }
    }
    // printf("%d\n", res);
    return res;
}

int main() {
    freopen ("B-large-practice.in","r",stdin);
    freopen ("B-large-practice.out","w",stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        sticks.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int l;
            scanf("%d", &l);
            if (l > 0) sticks[l]++;
        }
        long long res = solve();
        printf("Case #%d: %lld\n", t, res);
    }
    return 0;
}