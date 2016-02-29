#include <cstdio>
#include <algorithm>
#include <string>

const int MAXN = 102;
struct Dish {
    int price;
    std::string name;
};


bool cmp(const Dish &a, const Dish &b) {
    return (a.price < b.price) || (a.price == b.price && a.name < b.name);
}

Dish appetizer[MAXN], course[MAXN], dessert[MAXN];

int main() {
    int T;
    char buf[100];
    scanf("%d", &T);
    while (T--) {
        int S, M, D, x;
        scanf("%d%d%d", &S, &M, &D);
        for (int i = 0; i < S; i++) {
            scanf("%s %d", buf, &x);
            appetizer[i].price = x;
            appetizer[i].name = buf;
        }
        for (int i = 0; i < M; i++) {
            scanf("%s %d", buf, &x);
            course[i].price = x;
            course[i].name = buf;
        }
        for (int i = 0; i < D; i++) {
            scanf("%s %d", buf, &x);
            dessert[i].price = x;
            dessert[i].name = buf;
        }
        std::sort(appetizer, appetizer + S, cmp);
        std::sort(course, course + M, cmp);
        std::sort(dessert, dessert + D, cmp);
        int s = S/2, m = M / 2, d = D / 2;
        int sum = appetizer[s].price + course[m].price + dessert[d].price;
        printf("%d %s %s %s\n", sum, appetizer[s].name.c_str(), course[m].name.c_str(), dessert[d].name.c_str());
    }
    return 0;
}
