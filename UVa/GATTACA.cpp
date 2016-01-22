#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <iostream>
#define MAXCHAR 1000+10 //最长处理5000个字符

char c[MAXCHAR], *a[MAXCHAR];

int comlen( char *p, char *q ){
    int i = 0;
    while( *p && (*p++ == *q++) )
        ++i;
    return i;
}

int pstrcmp( const void *p1, const void *p2 ){
    return strcmp( *(char* const *)p1, *(char* const*)p2 );
}

int main( ){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        char ch;
        int n=0;
        int i, temp;
        int maxlen=0, maxi=0;
        //printf("Please input your string:\n");
        while( (ch=getchar())!='\n' ){
            a[n]=&c[n];
            c[n++]=ch;
        }
        c[n]='\0';
        qsort( a, n, sizeof(char*), pstrcmp );
        for(i=0; i<n-1; ++i ){
            temp=comlen( a[i], a[i+1] );
            if( temp>maxlen ){
                maxlen=temp;
                maxi=i;
            }
        }
        if(!maxlen){
            printf("No repetitions found!\n");
        }else{
            printf("%.*s ",maxlen, a[maxi]);
           /* printf("\n------------\n");
            for(i=0;i<n;i++){
                printf("%s\n",a[i]);
            }
            printf("--------------\n");*/
            int cnt = 0;
            i = maxi;
            while(i<n){
                //printf("asdf\n");
                int com = comlen(a[i],a[maxi]);
                //printf("%d\n",com);
                if(com>=maxlen){
                    cnt++;
                    i++;
                }
                else break;
            }
            printf("%d\n",cnt);
        }
    }
    //system("PAUSE");
    return 0;
}
