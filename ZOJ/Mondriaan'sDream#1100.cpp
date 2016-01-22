#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX_ROW 11
#define MAX_STATUS 2048
long long DP[MAX_ROW][MAX_STATUS];
int g_Width, g_Height;

//test the first line
bool TestFirstLine(int nStatus) {
    int i = 0;
    while( i < g_Width) {
        if(nStatus & (0x1 << i)) {
            if( i == g_Width -1 || (nStatus & (0x1 << (i+1))) == 0) {
                return false;
            }
            i += 2;
        }
        else {
            i++;
        }
    }
    return true;
}

// test if status (i, nStatusA) and (i-1, nStatusB) is compatable.
bool CompatablityTest(int nStatusA, int nStatusB) {
    int i = 0;

    while( i < g_Width) {
        if( (nStatusA & (0x1 << i))  == 0) {
            if((nStatusB & (0x1 << i)) == 0) {
                return false;
            }
            i++;
        }
        else {
            if((nStatusB & (0x1 << i)) == 0 ) {
                i++;
            }
            else if( (i == g_Width - 1) || ! ( (nStatusA & (0x1 << (i+1))) && (nStatusB & (0x1 << (i + 1)))) ) {
                return false;
            }
            else {
                i += 2;
            }

        }
    }
    return true;
}

int main() {
    int i,j;
    int k;
    while(scanf("%d%d", &g_Height, &g_Width) != EOF ) {
        if(g_Width == 0 && g_Height == 0) {
            break;
        }

        if(g_Width > g_Height) {
            swap(g_Width, g_Height);
        }


        int nAllStatus = 2 << (g_Width-1);
        memset(DP, 0, sizeof(DP));
        for( j = 0; j < nAllStatus; j++) {
            if(TestFirstLine(j)) {
                DP[0][j] = 1;
            }
        }

        for( i = 1; i < g_Height; i++) {
            for( j = 0; j < nAllStatus; j++) {
                // iterate all status for line i
                for( k = 0; k < nAllStatus; k++) {
                    // iterate all status for line i-1
                    if(CompatablityTest(j, k)) {
                        DP[i][j] += DP[i-1][k];
                    }
                }
            }
        }
        printf("%lld\n", DP[g_Height-1][nAllStatus - 1]);
    }
    return 0;
}
