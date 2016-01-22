#include<cstdio>
int main()
{
	char c;
	int cnt = 0;
	while((c=getchar())!=EOF){
		if(c=='\"'){
			if(!cnt){
				printf("%c",'`');
				printf("%c",'`');
				cnt = 1;
			}
			else{
				printf("%c",'\'');
				printf("%c",'\'');
				cnt = 0;
			}
		}
		else printf("%c",c);
	}
	return 0;
}
