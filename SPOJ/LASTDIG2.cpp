#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
long long int power(long long int m,long long int n)
{
     if(n==0) return 1;
     if(n==1) return m;
     long long int c = power(m,n/2);
     return c*c*power(m,n%2); 
 }
int main()
{
    long long int T,a,b,c;
    string s;
    scanf("%lld",&T);
    while(T--){
          cin >> s >> b;
          if(b==0){ printf("1\n"); continue;}  
          a = (int)(s[s.length()-1] - '0');  
          b=b%4;
          if(b==0) b=4; 
          printf("%lld\n",power(a,b)%10);
    }                          
    return 0;
}
