#include<stdio.h>
#include<string.h>
void sort(char *name[],int n)
{
char *pt;  //空1
int i,j,k;
for(i=0;i<n-1;i++){
   k=i;
   for(j=i+1;j<n;j++)
      if(strcmp(name[k],name[j])>0) k=j;  //空2
   if(k!=i){
      pt=name[i];name[i]=name[k];name[k]=pt;
      }
   }
}
int main()
{
int i,n;
char *name[]={"China","America","Japan","France","German"};
scanf("%d",&n);
n=n>5?5:n<1?1:n;
sort(name,n);  //空3
for (i=0;i<5;i++)puts(name[i]);
return 0;
}