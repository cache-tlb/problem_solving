#include <stdio.h>  
int main()  
{  
   int i,j,k,m;  
   int a[202];  
   for (i=1;i<201;i++)  
      a[i] = i*i*i;  
     
   for (i=1;i<201;i++)  
      for (j=2;j<201;j++)  
         for (k=j;k<201;k++)  
            for (m=k;m<201;m++)  
               if (a[i] == a[j]+a[k]+a[m])  
                  printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,m);  
   return 0;  
}
