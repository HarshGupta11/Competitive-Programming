#include<iostream>
using namespace std;
int main()
{
     int n,m;
     scanf("%d%d",&n,&m);
     while(n!=-1 || m!=-1){
          if(n<=0) printf("%d\n",m);
          else if(m<=0) printf("%d\n",n);
          else if(n<m)  {
                   if(m%(n+1) == 0)      printf("%d\n",m/(n+1));
                   else                  printf("%d\n",m/(n+1)+1); 
          }   
          else {
                   if(n%(m+1) == 0)      printf("%d\n",n/(m+1));
                   else                  printf("%d\n",n/(m+1)+1); 
          }  
          scanf("%d%d",&n,&m);
     } 
     return 0;  
}