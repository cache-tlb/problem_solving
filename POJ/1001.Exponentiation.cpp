#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <list>

void num2digits(int x, std::list<int> &l) {
    if (x == 0) {
        l.push_back(x);
    }
    while (x) {
        l.push_front(x % 10);
        x /= 10;
    }
}

class HPV {
public:
    HPV(int i, int e) {
        while (i > 0 && i % 10 == 0 && e > 0) {
            i /= 10;
            e--;
        }
        if (i == 0) e = 0;
        this->i = i;
        this->e = e;
        num2digits(i, digits);
        frac_digits = e;
    }

    void muntiply() {
        int rem = 0;
        for (std::list<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it ++) {
            int cur = rem + (*it) * i;
            (*it) = cur % 10;
            rem = cur / 10;
        }
        if (rem) {
            std::list<int> l;
            num2digits(rem, l);
            digits.insert(digits.begin(), l.begin(), l.end());
        }
        frac_digits += e;
    }

    void print() {
        if (frac_digits > digits.size()) {
            printf(".");
            int nz = frac_digits - digits.size();
            while (nz > 0) {
                nz--;
                printf("0");
            }
        }
        int k = 0;
        for (std::list<int>::iterator it = digits.begin(); it != digits.end(); it++) {
            if (k == digits.size() - frac_digits) printf(".");
            printf("%d", *it);
            k++;
        }
        printf("\n");
    }

protected:
    int i, e;
    std::list<int> digits;
    int frac_digits;
};

int main() {
    char buf[100], buf2[100];
    int e;
    while (scanf("%s %d", buf, &e) != EOF) {
        int len = strlen(buf);
        int pos = 0;
        int point_pos = -1;
        for (int i = 0; i < len; i++) {
            if (buf[i] == '.') point_pos = i;
            else buf2[pos++] = buf[i];
        }
        buf2[pos] = 0;;
        int v = atoi(buf2);
        int k = len - point_pos - 1;
        HPV hpv(v, k);
        for (int i = 1; i < e; i++) {
            hpv.muntiply();
        }
        if (e == 0) {
            printf("1\n");
        }
        else hpv.print();
    }
    return 0;
}
