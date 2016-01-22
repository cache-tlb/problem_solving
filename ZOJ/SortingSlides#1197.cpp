/*#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 32;

struct Slide {
    int xmin, xmax, ymin, ymax, flag;
};

struct Point {
    int x, y, flag;
};

Slide slides[MAXN];
Point points[MAXN];
int nCover[MAXN];
int ans[MAXN];

bool cover(const Slide &s, const Point &p) {
    return (s.xmin < p.x && p.x < s.xmax && s.ymin < p.y && p.y < s.ymax);
}

int N;

bool process() {
    memset(nCover, 0, sizeof(nCover));
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(cover(slides[j], points[i])) nCover[i]++;
        }
    }
    int ok = 1;
    for(int k = 0; k < N; k++) {
        ok = 1;
        int mincover = MAXN, minpos = 0, cnt = 1;
        for(int i = 0; i < N; i++) {
            if(!points[i].flag) continue;
            if(nCover[i] < mincover) {
                mincover = nCover[i];
                minpos = i;
                cnt = 1;
            }
            else if(nCover[i] == mincover) {
                cnt++;
            }
        }
        if(mincover != 1) {
            ok = 0;
            break;
        }
        points[minpos].flag = 0;
        int slidenum = 0;
        for(int j = 0; j < N; j++) {
            if(slides[j].flag && cover(slides[j], points[minpos])) {
                slidenum = j;
                break;
            }
        }
        slides[slidenum].flag = 0;
        for(int i = 0; i < N; i++) {
            if(points[i].flag && cover(slides[slidenum], points[i])) {
                nCover[i]--;
            }
        }
        ans[slidenum] = minpos;
    }
    return ok;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    while(scanf("%d", &N) != EOF) {
        if(!N) break;
        for(int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &slides[i].xmin ,&slides[i].xmax, &slides[i].ymin, &slides[i].ymax);
            slides[i].flag = 1;
        }
        for(int i = 0; i < N; i++) {
            scanf("%d%d", &points[i].x, &points[i].y);
            points[i].flag = 1;
        }
        bool ok = process();
        printf("Heap %d\n", ++t);
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(ans[i] >= 0){
                if(cnt) printf(" ");
                printf("(%c,%d) ", i + 'A', ans[i] + 1);
                cnt++;
            }
        }
        if(cnt) printf("\n");
        else printf("none\n");
        printf("\n");
    }
    return 0;
}
*/

#include "stdio.h"
static long slides[27][4],s[27][27],num[27];



int main()
{int n,i,j,k,l,flag,t;
 long x,y;
 scanf("%d",&n);
 t=1;
 while(n)
     {printf("Heap %d\n",t);
      ++t;
      for(i=0;i<=n;++i)
         {num[i]=0;
          for(j=0;j<=n;++j)
            s[i][j]=0;
         }
      for(i=1;i<=n;++i)
             scanf("%ld %ld %ld %ld",slides[i],slides[i]+1,slides[i]+2,slides[i]+3);
      for(i=1;i<=n;++i)
         {scanf("%ld %ld",&x,&y);
          for(j=1;j<=n;++j)
               if(x>slides[j][0]&&x<slides[j][1]
                &&y>slides[j][2]&&y<slides[j][3])
                      {s[i][j]=1;
                       ++s[0][j];
                       ++s[i][0];
                      }
         }
      for(i=1;i<=n;++i)
           {flag=1;
            for(j=1;j<=n;++j)
                  if(s[j][0]==1)
                      {flag=0;
                       for(k=1;k<=n;++k)
                             if(s[j][k])
                                 break;
                       num[k]=j;
                       s[j][k]=s[j][0]=s[0][k]=0;
                       for(l=1;l<=n;++l)
                             if(s[l][k])
                                {--s[l][0];
                                 s[l][k]=0;
                                }
                      }
            for(j=1;j<=n;++j)
                  if(s[0][j]==1)
                      {flag=0;
                       for(k=1;k<=n;++k)
                                if(s[k][j])
                                   break;
                       num[j]=k;
                       s[k][0]=s[k][j]=s[0][j]=0;
                       for(l=1;l<=n;++l)
                             if(s[k][l])
                                 {s[0][l]--;
                                  s[k][l]=0;
                                 }


                      }
            if(flag)
                break;
           }
      for(flag=1,i=1;i<=n;++i)
             if(num[i])
               if(flag)
                  {flag=0;
                   printf("(%c,%ld)",i+'A'-1,num[i]);
                  }
               else printf(" (%c,%ld)",i+'A'-1,num[i]);

      if(flag)
        printf("none");
      printf("\n\n");
      scanf("%d",&n);
     }
 return 0;
}