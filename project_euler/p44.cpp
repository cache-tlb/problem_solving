// too slow, not work out yet

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

inline long long pen (long long x) { return x*(3*x-1)/2; }
inline bool isPen (long long y) { return 2*y == round ((sqrt(1.0 + 24.0*(double)y) + 1.0) / 6.0); }

bool check(long long y) {
    long long limit = (y - 2) / 3;
    for (long long idx = 1; idx <= limit; idx++) {
        long long x = pen (idx);
        if (isPen(x+y) && isPen(x+x+y)) return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    long long idx = 1;
    while (!check(pen(idx))) {
        idx++;
    }
    cout << pen(idx) << endl;
    return 0;
}

/*
k = 2167, j = 1020
The value of D is 5482660*/