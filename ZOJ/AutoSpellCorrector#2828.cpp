/*#include<iostream>
#include<string>
using namespace std;
const int MAX = 100 + 10;
void sort1(string array[], int zz,int yy)
{
     int z,y;
	 string k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
           while(z<y&&array[y]>=k)y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
           while(z<y&&array[z]<=k)z++;
           if(z<y)
             array[y]=array[z];               
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1);
         sort1(array,z+1,yy);    
     }
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		string dic[MAX];
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> dic[i];
		}
		//sort1(dic,0,n-1);
		int m;
		cin >> m;
		string q;
		for(int k = 0; k < m; k++){
			cin >> q;
			int len = q.length();
			int findself = 0;
			for(int i = 0; i < n; i++){
				if(dic[i] == q){
					findself = 1;
					break;
				}
			}
			if(findself){
				cout << q << endl;
				continue;
			}
			int nans = 0, first = 1;
			string ans[MAX];
			for(int i = 0; i < n; i++){
				if(dic[i].length() != len) continue;
				int ndiff = 0, pos = 0;
				char temp;
				for(int j = 0; j < len - 1; j++){
					string str = q;
					str[j] = q[j+1];
					str[j+1] = q[j];
					if(str==dic[i]){
					    ans[nans] = dic[i];
					    nans++;
					    break;
					}
				}
			}
			if(!nans) cout << q << endl;
			else{
				sort1(ans,0,nans-1);
				for(int i = 0; i < nans; i++){
					cout << ans[i];
					if(i==nans-1) cout << endl;
					else cout << ',';
				}
			}//end for_k
		}//end for_m
		if(t) cout << endl;
	}
	return 0;
}
*/
#include <iostream>
#include <string>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

char dic[100][21];
int dicl;

bool process(char *str){
    int l = strlen(str), ansl = 0;
    char tmp;
    bool have = false;
    string ans[100];
    for(int i = 0; i < l - 1; i++){
        tmp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tmp;
        for(int j = 0; j < dicl; j++){
            if(strcmp(str, dic[j]) == 0){
                have = true;
                ans[ansl++].assign(str);
                break;
            }
        }
        tmp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tmp;
    }
    if(have){
        sort(ans, ans + ansl);
        cout << ans[0];
        for(int i = 1; i < ansl; i++)
            cout << ',' << ans[i];
        cout << endl;
    }
    return have;
}

int main(){
    int cas, q;
    char query[21];
    bool same;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d", &dicl);
        getchar();
        for(int i = 0; i < dicl; i++)
            scanf("%s", dic[i]);
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%s", query);
            same = false;
            for(int j = 0; j < dicl; j++){
                if(strcmp(query, dic[j]) == 0){
                    printf("%s\n", query);
                    same = true;
                    break;
                }
            }
            if(same) continue;
            if(!process(query)) printf("%s\n", query);
        }
        if(cas) printf("\n");
    }
    return 0;
}

