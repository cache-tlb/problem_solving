/*#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include<memory.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)){
        map<string,int> sock;
        string temp;
        char str[10];
        for(int i=0;i<2*n-1;i++){
            memset(str,0,sizeof(str));
            scanf("%8c",str);
            temp = str+1;
            sock[temp]++;
        }//cout<<1<<endl;
        map<string,int>::iterator iter;
        for(iter = sock.begin();iter!=sock.end();iter++){
            if((iter->second)%2){
                cout<<iter->first<<endl;
                break;
            }
        }
    }
    return 0;
}
*/
#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
         getchar();                     
         int i,j;
         int a[8]={0};
         char s[10];
         for(i=0;i<n;i++)
         {
              gets(s);
              for(j=0;j<7;j++)
              a[j]=a[j]^s[j];
         }
         for(i=0;i<n-1;i++)
         {
              gets(s);
              for(j=0;j<7;j++)
              a[j]=a[j]^s[j];
         }
         for(i=0;i<7;i++)
         printf("%c",a[i]);
         printf("\n");
    }
}
