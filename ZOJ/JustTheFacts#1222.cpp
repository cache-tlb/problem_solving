#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

typedef struct {
    int size, a[110];
} LInt;

char ch[110];
int t[10] = { 1, 1, 2, 6, 4, 4, 4, 8, 4, 6 };
int f[10] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8 };

void div5 ( const LInt &l, LInt &r ) {
    int c = 0, i, t;
    memset ( r.a, 0, sizeof ( r.a ) );
    for ( i = 0; i < l.size; i ++ ) {
        r.a[i] = ( c + l.a[i] * 2 ) % 10;
        c = ( c + l.a[i] * 2 ) / 10;
    }
    if ( c ) {
        r.a[i] = c;
        i ++;
    }
    r.size = i;
    for ( i = 0; i < r.size - 1; i ++ ) {
        r.a[i] = r.a[i + 1];
    }
    r.a[i] = 0;
    r.size --;
}

int mod4 ( const LInt &l ) {
    int s = l.a[0] + l.a[1] * 10;
    return s % 4;
}

int ld ( const LInt &l ) {
    if ( l.size == 1 ) {
        return f[l.a[0]];
    }
    else {
        LInt ll;
        div5 ( l, ll );
        int mod = mod4 ( ll );
        int tx = ld ( ll );
        int dx = tx * 6 * t[l.a[0]] % 10;
        for ( int i = 0; i < mod; i ++ ) {
            if ( dx == 2 ) {
                dx = 6;
            }
            else if ( dx == 6 ) {
                dx = 8;
            }
            else {
                dx /= 2;
            }
        }
        return dx;
    }
}

void proc () {
    LInt n;
    memset ( n.a, 0, sizeof ( n.a ) );
    n.size = strlen ( ch );
    for ( int i = 0; i < n.size; i ++ ) {
        n.a[i] = ch[strlen ( ch ) - i - 1] - '0';
    }
    printf ( "%d\n", ld ( n ) );
}

int main () {
    //freopen ( "in.txt", "r", stdin );
    //freopen ( "out.txt", "w", stdout );
    while ( scanf ( "%s", ch ) != EOF ) {
        proc ();
    }
    return 0;
}
