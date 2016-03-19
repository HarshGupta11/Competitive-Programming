#include <cstdlib>
#include <iostream>
 
using namespace std;
 
int main()
{
    int T;
    long long int no_of_zero;
    scanf("%d",&T);
    while(T--){
          no_of_zero = 0;     
          int n,num = 5;
          scanf("%d",&n);
          int add = n/num;
          while(add != 0){
                no_of_zero+=add;
                num*=5;
                add = n/num;
          } 
          printf("%lld\n",no_of_zero);
    }     
    return 0;
}