#include <stdio.h>
int main()
{
    long long  n, s, now, cnt;
    int i, j, a;

    while(scanf("%lld", &n) != EOF)
    {
        s = cnt= now = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            now += a / 3;
            a %= 3;

            if(a == 1)
                cnt ++;
            else if(a == 2)
                s ++;

        }

        s += now;



        if(cnt < now-1)
        {
            now -= cnt;
            s += cnt;
        }
        else
        {
            s += now-1;
            now = 1;
        }

        if(now > 2)
        {
            long long t = (now - 2) / 2;
            s += t;
            now -= t*2;
        }

        if(now == 3) s++;

        printf("%lld\n", s);
    }
    return 0;
}

