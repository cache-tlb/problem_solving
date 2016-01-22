/*#include<iostream>
#include<map>
#include<string.h>
using namespace std;
const int MAX = 8000 + 10;
int main()
{
    int n;
    while(cin >> n){
        int c[MAX] = {};
        memset(c,-1,sizeof(c));
        int x1,x2,color;
        for(int k = 0; k < n; k++){
            cin >> x1 >> x2 >> color;
            for(int i = x1; i < x2; i++){
                c[i] = color;
            }
        }
        //cout << "------" << endl;
        //for(int i=0; i<n;i++){
        //    cout<<c[i]<< ' ' ;
        //}
        //cout << endl << "--------"<<endl;    
        map<int, int> mc;
        int cur_c = c[0], cur = 0;
        while(cur < n){
            cur_c = c[cur];
            if(c[cur]!= -1){
                mc[cur_c]++;
            }
            while((cur < n) && (c[cur] == cur_c)) cur++;
        }
        map<int, int>::iterator it;
        for(it = mc.begin(); it != mc.end(); it++){
            cout << it -> first << ' ' << it -> second << endl;
        }
        cout << endl;    
    }    
    return 0;
}
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#define MAXSIZE 32000
using namespace std;
struct segment
{
    int color;//color>=0 indicates that this segment is monochrome,while color==-1 indicates polychrome.A value -2 indicates the original state
    int start,end;//the starting and ending point of a segment
}seg[MAXSIZE];
struct Dye
{
    int left,right,chrome;
}manipulation[8000],visible[8000];
void Build(int num,int left,int right)
{
    seg[num].start=left;seg[num].end=right;seg[num].color=-2;//set the original state of the current segment
    if(left+1==right) return;//if the segment cannot be divided any more,return
    int mid=(left+right)/2;//divide it into two
    Build(num*2,left,mid);Build(num*2+1,mid,right);//Build the left and right child of the current segment,respectively
}
/*This function is used to build a segment tree,with its parameters representing the index of
the root(num),the starting point of the total segment(left),and the ending point of the total
segment(right),respectively*/
void Insert_Segment(int num,int left,int right,int chrome)
{
    if(seg[num].color!=chrome)
    {
        if(left==seg[num].start && right==seg[num].end)
        {
            seg[num].color=chrome;
            if(num==1) return;
            if(num%2==0)
            {
                if(seg[num+1].color==chrome) seg[num/2].color=chrome;
            }
            else if(seg[num-1].color==chrome) seg[num/2].color=chrome;
            return;
        }//if the color segment is exactly the current segment,then color it and return
        else if(seg[num].color>=0)
        {
            seg[2*num].color=seg[num].color;
            seg[2*num+1].color=seg[num].color;
        }//if the color segment does not match the current segment perfectly,and the current segment was monochrome
         //then paint its children its original color,and move on
        seg[num].color=-1;//two scenarios will lead us here:the segment has its original color
                          //and gets mixed by the current painting,or the segment was a polychrome
                          //one.Either way,we should mark it as polychrome here and move on
        int mid=(seg[num].start+seg[num].end)/2;//find the middle point of the segment,looking to paint it
        if(mid>=right)
        {
            Insert_Segment(2*num,left,right,chrome);
            if(seg[2*num].color==seg[2*num+1].color && seg[2*num].color>=0)
                seg[num].color=seg[2*num].color;
        }
        else if(mid<=left)
        {
            Insert_Segment(2*num+1,left,right,chrome);
            if(seg[2*num].color==seg[2*num+1].color && seg[2*num].color>=0)
                seg[num].color=seg[2*num].color;
        }
        else
        {
            Insert_Segment(2*num,left,mid,chrome);
            Insert_Segment(2*num+1,mid,right,chrome);
            if(seg[2*num].color==seg[2*num+1].color && seg[2*num].color>=0)
                seg[num].color=seg[2*num].color;//if the two child segments end up with the same
                                                //monochrome,update the father segment
        }//decide in which area should the paint be carried on
    }//all the above should only be done when the chrome to be painted is not the same as the
     //original color of the current segment
}
/*This function is used to insert paint area into the segment tree we have built,with its parameters
representing the index of the root of the tree(num),the starting and ending point of the paint
segment(left,right),as well as the color of the paint(chrome),respectively*/
void Count_Color(int num,int left,int right)
{
    if(left+1==right && seg[num].color==-2) return;
    if(seg[num].color>=0)
    {
        //printf("%d %d %d\n",seg[num].start,seg[num].end,seg[num].color);
        if(seg[num].start==visible[seg[num].color].right)
            visible[seg[num].color].right=seg[num].end;
        else if(seg[num].end==visible[seg[num].color].left)
            visible[seg[num].color].left=seg[num].start;
        else
        {
            visible[seg[num].color].chrome++;
            visible[seg[num].color].left=seg[num].start;
            visible[seg[num].color].right=seg[num].end;
        }
        return;
    }//if the current segment if monochrome,then the color of it is visible,obviously.In addition,
     //all the segments who are the children of it stays invisible.Consequencely,the counting
     //process should be ended.
    else
    {
        int mid=(left+right)/2;
        Count_Color(num*2,left,mid);
        Count_Color(num*2+1,mid,right);
    }
    //Either the current segment is polychrome,or remaining untouched,the counting should process
    //down to its children.
}
/*This function is used to decide on the visibility together with the number of segments of each
color,with its parameters representing the index of the root of the tree(num),the startpoint and
the endpoint of the total segment(left,right),respectively.*/
void Output(int left,int right)
{
    for(int i=left;i<=right;i++)
    {
        if(visible[i].chrome)
        {
            printf("%d %d\n",i,visible[i].chrome);
        }
    }
    printf("\n");
}
int main()
{
    int n,mleft,mright,lcolor,rcolor;
    while(scanf("%d",&n)==1)
    {
        mleft=lcolor=8001;mright=rcolor=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&manipulation[i].left,&manipulation[i].right,&manipulation[i].chrome);
            if(mleft>manipulation[i].left) mleft=manipulation[i].left;
            if(mright<manipulation[i].right) mright=manipulation[i].right;
            if(lcolor>manipulation[i].chrome) lcolor=manipulation[i].chrome;
            if(rcolor<manipulation[i].chrome) rcolor=manipulation[i].chrome;
        }//Input all the manipulations,and find out the leftmost and rightmost endpoint of the area
         //together with the lowest and highest index of the color used
        Build(1,mleft,mright);//Build the segment tree due to the largest segment area
        for(int i=0;i<n;i++)
        {
            Insert_Segment(1,manipulation[i].left,manipulation[i].right,manipulation[i].chrome);
        }//Implement the manipulations
        for(int i=lcolor;i<=rcolor;i++)
        {
            visible[i].chrome=0;
            visible[i].left=visible[i].right=-1;
        }
        Count_Color(1,mleft,mright);//Count the colors visible
        Output(lcolor,rcolor);//Output the results
    }
    return 0;
}
