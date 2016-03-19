#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    double T,ans;
    int i;
    scanf("%lf",&T);
    while(T!=0){
          ans = 0;
          i = 1;
          while(ans<T){
                ++i;       
                ans+=(1.0/i);
          }          
          printf("%d card(s)\n",i-1);
          scanf("%lf",&T);
    }     
    return 0;
}
