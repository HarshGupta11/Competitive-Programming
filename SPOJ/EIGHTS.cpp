#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int T;
    long long int k;
    long long int ans;
    scanf("%d",&T);
    while(T--){
          scanf("%lld",&k);
          if(k&1){
              ans = 5* (k/2) + 1;
              printf("%lld92\n",ans);
          }
          else{
              ans = 5* (k/2) - 1;
              printf("%lld42\n",ans); 
          }
    }
    return 0;
}
