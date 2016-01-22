#include<iostream>
#include<string>
using namespace std;
const int MAX = 10000 + 10;

void sort1(string array[], int zz,int yy)
{
     int z,y;
     string k = "";
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
	string s[MAX];
	string temp;
	int round = 1;
	while(cin >> temp){
		int n = 1;
		s[0] = temp;
		while(cin >> temp){
			if(temp == "9")  break;
			else{
				s[n] = temp;
				n++;
			}
		}
		sort1(s, 0, n - 1);
		int flag = 1;
		for(int i = 0; i < n - 1; i++){
			int la = s[i].length(), lb = s[i + 1].length();
			int p = 0, q = 0;
			while(p < la && q < lb){
				if(s[i][p] != s[i + 1][q]) break;
				p++;
				q++;
			}
			if(p == la){
				flag = 0;
				break;
			}
		}
		if(flag) cout << "Set " << round << " is immediately decodable" << endl;
		else cout << "Set " << round << " is not immediately decodable" << endl;
		round++;
	}
	return 0;
}
