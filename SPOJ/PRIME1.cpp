#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T,m,n,i,j;
    scanf("%d",&T);
    while(T--){
          scanf("%d%d",&m,&n);
          int len = n-m+1;
          int A[len];
          memset(A,0,sizeof(A));
          j = 0;
          if(m==1) A[0] = 1;
          for(i = 2;i*i<=n;++i){
              for(j=0;j<len;++j){
                  if((j+m)%i==0 && j+m != i){
                    while(j<len){
                          A[j]=1;
                          j+=i;
                    }
                  }
              }
          }
          for(j=0;j<len;++j){
              if(A[j] == 0) printf("%d\n",m+j);
          }
          printf("\n");
    }                                                      
    return 0;
}
