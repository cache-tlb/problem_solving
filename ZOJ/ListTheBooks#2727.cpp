#include<iostream>
#include<string>
using namespace std;
const int MAXN = 150;
struct book{
	int year;
	int price;
	string name;
};
int cmpByYear(book b1, book b2)
{
	if(b1.year!=b2.year)
		return b1.year - b2.year;
	else if(b1.name>b2.name)
		return 1;
	else if(b1.name<b2.name)
		return -1;
	else return b1.price - b2.price;
}
int cmpByPrice(book b1, book b2)
{
	if(b1.price!=b2.price)
		return b1.price - b2.price;
	else if(b1.name>b2.name)
		return 1;
	else if(b1.name<b2.name)
		return -1;
	else return b1.year - b2.year;
}
int cmpByName(book b1, book b2)
{
	if(b1.name>b2.name)
		return 1;
	else if(b1.name<b2.name)
		return -1;
	else if(b1.year!=b2.year)
		return b1.year - b2.year;
	else return b1.price - b2.price;
}
void sort1(book array[], int zz,int yy,int (*cmp)(book,book))
{
     int z,y;
	 book k;
     if(zz<yy)
     {
         z=zz;y=yy;k=array[z];
         do{
             while(z<y&&cmp(array[y],k)>=0)y--;
             if(z<y)
             {
                 array[z]=array[y];
                 z++;   
             }       
             while(z<y&&cmp(array[z],k)<=0)z++;
             if(z<y){
                 array[y]=array[z];
         }
         }while(z!=y);
         array[z]=k;
         sort1(array,zz,z-1,cmp);
         sort1(array,z+1,yy,cmp);
     }
}

int main()
{
	int n;
	int first = 1;
	while(cin >> n){
		if(n==0) break;
		if(first) first = 0;
		else cout << endl;
		book b[MAXN] = {};
		string type;
		for(int i = 0; i < n; i++){
			cin >> b[i].name >> b[i].year >> b[i].price;
		}
		cin >> type;
		if(type=="Year")
			sort1(b,0,n-1,cmpByYear);
		else if(type=="Price")
			sort1(b,0,n-1,cmpByPrice);
		else
			sort1(b,0,n-1,cmpByName);
		for(int i = 0; i < n; i++){
			cout << b[i].name << ' ' << b[i].year << ' ' << b[i].price << endl;
		}
	}
	return 0;
}
