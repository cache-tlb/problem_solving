/*
#include<iostream>
using namespace std;

int gcd(int x,int y)
{
    if(x%y==0)return y;
    else return gcd(y,x%y);
}
int main()
{
    int n;
    while(cin >> n){
        if(n == 0) break;
        int cnt = 0;
        int i;
        for(i = 1; i*i <=n ; i++){
            if(gcd(n,i) == 1) cnt++;
        }
        cout << cnt << endl;
    }    
    return 0;
}
*/
#include<iostream>
using namespace std;
const int N=31624;//994897763
int many(int a[],int n,int m,int num)
{
    int *c=new int[m],count=0,result;
    int i=0,j;
    c[i]=0;
    while(i>=0&&i<m&&m!=1)
    {
        if(c[i]>n-m+i){//»ØËÝ
            i--;
            if(i>=0) c[i]++;
            continue;
        }
        i++;
        if(i==m-1){
            for(c[i]=c[i-1]+1;c[i]<=n-m+i;c[i]++){
                int tmp=a[c[0]];
                for(j=1;j<m;j++) tmp=tmp*a[c[j]];
                result = num/tmp;
                count +=result;
            }
        }
        else{
            c[i]=c[i-1]+1;
        }
    }
    if(m==1){
        for(i=0;i<n;i++){
            result = num/a[i];
            count += result;
        }
    }
    delete []c;
    return count;
}
int main()
{
    bool b[N]={false},positive;
    int i,j,n,count;
    b[0]=true;
    b[1]=true;
    for(i=2;i<N;i++){
        if(b[i]==false){
            j=i+i;
            while(j<N){
                b[j]=true;
                j=j+i;
            }
        }
    }
    while(cin>>n,n!=0){
        int a[10]={0};
        int m=n,p=0;
        i=2;
        while(i<N&&i<n&&i<=m){
            if(m%i==0){
                a[p]=i;
                p++;
                do{
                    m=m/i;
                }while(m%i==0);
            }
            do{
                i++;
            }while(i<N&&b[i]);
        }
        if(i>=N){
            a[p]=m;
            p++;
        }
        //   for(i=0;i<p;i++)//
        //    cout<<a[i]<<" ";//
        //   cout<<endl;//
        positive=false;
        count=0;
        for(j=1;j<=p;j++){
            if(positive) count -= many(a,p,j,n);
            else count += many(a,p,j,n);
            positive = !positive;
        }
        if(p==0) cout<<n-1<<endl;
        else cout<<n-count<<endl;
    }
    return 0;
}
