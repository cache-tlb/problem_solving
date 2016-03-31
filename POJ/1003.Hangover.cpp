#include <cstdio>
#include <vector>

const double MAXS = 5.2;
std::vector<double> acc;
void init() {
    double s = 0.0;
    int i = 2;
    while (s < MAXS) {
        s += 1./double(i);
        acc.push_back(s);
        i++;
    }
}

int main() {
    init();
    double c;
    while (scanf("%lf", &c) != EOF) {
        if (c == 0) break;
        int ans = acc.size();
        for (int i = 0; i < acc.size(); i++) {
            if (acc[i] >= c) {
                ans = i + 1;
                break;
            }
        }
        printf("%d card(s)\n", ans);
    }
    return 0;
}
