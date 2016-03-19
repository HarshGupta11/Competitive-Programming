#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T,n,u,l,r,val,q;
    scanf("%d",&T);
    while(T--){
          scanf("%d%d",&n,&u);
          int A[n+1];
          memset(A,0,sizeof(A));
          while(u--){
                scanf("%d%d%d",&l,&r,&val);
                A[l]+=val;
                A[r+1]-=val;
          }
          for(int i = 1;i<n;++i) A[i]+=A[i-1];
          scanf("%d",&q);
          while(q--){
                scanf("%d",&val);
                printf("%d\n",A[val]);
          }
    }               
    
    return 0;
}
