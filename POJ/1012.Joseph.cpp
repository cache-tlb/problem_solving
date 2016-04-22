#include <cstdio>
#include <vector>
/*
bool check_m(int k, int m) {
    std::vector<int> q;
    for (int i = 1; i <= k*2; i++) {
        q.push_back(i);
    }
    int index = 0;
    while (q.size() > k)  {
        index = (index + m - 1) % q.size();
        if (q[index] <= k) {
            return false;
        }
        q.erase(q.begin() + index);
    }
    return true;
}
*/
int table[] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 13482720};
int main() {
    int k;
    while (scanf("%d", &k) != EOF) {
        if (!k) break;
        printf("%d\n", table[k]);
        /*int i = k;
        while (true) {
            bool ok = check_m(k, i);
            if (ok) {
                printf("%d\n", i);
                break;
            }
            i++;
        }*/
    }
    return 0;
}
/*
Sample Input

3
4
0
Sample Output

5
30
*/