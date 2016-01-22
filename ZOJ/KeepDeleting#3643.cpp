#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 600000

struct node {
    int v,pre;
    node *next;
}*head[MAX],tree[MAX];

int  ptr,n,m,ans,len,next[MAX];
char s1[MAX],str[MAX];

void Initial() {
    ptr = ans = 0;
    memset(head,NULL,sizeof(head));
}

void GetNext() {
    int i = 0,j = - 1;
    next[0] = -1;
    
    while (i < n) {
        if (j == -1 || s1[i] == s1[j])
            i++,j++,next[i] = j;
        else j = next[j];
    }
}

int Solve_KMP() {
    int i,j,k;
    i = j = ans = 0;
    while (i < len) {
        if (j == -1 || str[i] == s1[j]) {
            i++,j++;
            head[i] = head[i-1];
            if (j == n) {
                ans ++;
                if (head[i] != NULL){
                	j = head[i]->v,head[i] = head[i]->next;
                }
                else {
                	j = 0;
                }
            }
           
        }
        else {
            tree[i].v = j;
            tree[i].next = head[i];
            head[i] = &tree[i];
            j = next[j];
        }
    }
    return ans;
}

int main()
{
    int i,j,k;
    char c;
    while (scanf("%s",s1) != EOF) {
        Initial();
        n = strlen(s1);
        GetNext();
        scanf("%s",str);
        len = strlen(str);
        ans = Solve_KMP();
        printf("%d\n",ans);
    }
}