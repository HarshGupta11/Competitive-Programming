#include <cstdlib>
#include <iostream>

using namespace std;
int gcd(int small, int big);
long long int ans(int a,int b);
int main()
{
    int T,A,B;
    long long int lcm;
    scanf("%d",&T);
    while(T--){
          scanf("%d%d",&A,&B);
          lcm = ans(A,B);
         // printf("%lld  A=%d    B=%d\n",lcm,A,B);
          printf("%lld %lld\n",lcm/A,lcm/B);
    }     
    return 0;
}

long long int ans(int a,int b)
{
          int gcd_temp;
          
          long long int lcm = 1;
          do{
               gcd_temp = gcd(a,b);
               b = b/ gcd_temp;
               a = a/gcd_temp;
               lcm*=gcd_temp;
          }while(gcd_temp != 1);
          lcm *= a;
          lcm *= b;
          return lcm;
}

int gcd(int small, int big)
{
    int temp = 1;
    while(temp!=0){
        temp = big%small;
        big = small;
        small = temp;
    }    
    return big;
}
