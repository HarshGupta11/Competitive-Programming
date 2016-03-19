#include <cstdlib>
#include <iostream>

using namespace std;

int ETF(int n)
{
    int result = n;
    for(int i = 2;i*i<=n;++i){
        if(n%i==0){
           while(n%i==0) n/=i;
           result-= (result/i);
        }
    }
    if(n>1) result-= (result/n);
    return result;            
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--){
          scanf("%d",&n);
          printf("%d\n",ETF(n));
    }     
    
    return 0;
}
