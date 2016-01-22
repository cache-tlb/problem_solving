#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n,a,b;
	while(cin >> n >> a >> b){
		long long cnt = 0;  
		while(1) {  
           if(n<a) {  
                if(a-n<=b) {  
                    cnt+=b;  
                    n=b-(a-n);  
                }  
                else break;  
            } else {  
                cnt+=n/a*b;  
                long long tmp=n/a*b;  
                n%=a;  
                n+=tmp;  
            }  
        }
        printf("%lld\n",cnt); 
	}
	return 0;
}
