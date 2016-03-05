#include <cstdio>

inline int level(char c) {
    if (c == '+' || c == '-') return 1;
    else return 2;
}

inline int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a*b;
    else if (op == '/') return a/b;
    else if (op == '%') return a % b;
    else return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a,b,c;
        char op1, op2;
        scanf("%d %c %d %c %d", &a, &op1, &b, &op2, &c);
        int res = 0;
        if (level(op1) == 1 && level(op2) == 2) {
            res = calc(a, calc(b, c, op2), op1);
        } else {
            res = calc(calc(a, b, op1), c, op2);
        }
        printf("%d\n", res);
    }
    return 0;
}
