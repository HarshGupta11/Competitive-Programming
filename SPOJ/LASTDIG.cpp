#include <cstdlib>
#include <iostream>

using namespace std;
long long int power(long long int m,long long int n)
{
     if(n==0) return 1;
     if(n==1) return m;
     long long int ans = power(m,n/2);
     return ans*ans*power(m,n%2); 
 }
int main()
{
    long long int T,a,b;
    scanf("%lld",&T);
    while(T--){
          scanf("%lld%lld",&a,&b);
          if(b==0) { printf("1\n"); continue;}
          a = a%10;  
          b=b%4;
          if(b==0) b=4; 
          printf("%lld\n",power(a,b)%10);
    }                          
    return 0;
}
