#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
char sour[13][13];  
int m, n;  
char getvalue(int r, int c, int dep)  
{  
    if(dep == 1)  
        return sour[r][c];  
    char t = getvalue(r / m, c / n, dep - 1);  
    if(t == ' ') return t;  
    return sour[r % m][c % n];  
}  
int main()  
{  
    int r, c, dep;  
    int con = 1;  
    //freopen("input.txt", "r", stdin);  
    while(scanf("%d %d", &m, &n) == 2){  
        getchar();  
        for(int i = 0; i < m; gets(sour[i++]));  
        scanf("%d", &dep);  
        if(con != 1) printf("\n");  
        printf("Fractal #%d:\n", con++);  
        r = c = 1;  
        for(int i = 1; i <= dep; i++){  
            r = r * m;  
            c = c * n;  
        }  
        for(int i = 0; i < r; i++){  
            int lim = -1;  
            for(int j = c - 1; j >= 0; j--)  
                if(getvalue(i, j, dep) != ' '){  
                    lim = j;  
                    break;  
                }  
            for(int j = 0; j <= lim; j++)  
                printf("%c", getvalue(i, j, dep));  
            printf("\n");  
        }  
    }  
    return 0;  
}  
