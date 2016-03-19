#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

inline int mod(int a)
{
       if(a >= 0) return a;
       return -a;
}
int main()
{
    ios::sync_with_stdio(false);
    int N,i,j,l,u;
    long long int ans;
    while(1){
         cin >> N;
         if(N==0) return 0;
         int A[N];
         for(i= 0;i<N;++i) cin >> A[i];
         sort(A,A+N);
         ans = 0;
         long long int tot = ((long long int)N*(N-1)*(N-2))/6;
         for(i = 0;i<=N-3;++i){
             for(j = i+1;j<=N-2;++j){
                 l = mod(A[j]-A[i]);   
                 u = A[i]+A[j];
                 ans+= (int)(upper_bound(A+j+1,A+N,u) - lower_bound(A+j+1,A+N,l));
             }
         }
         cout << tot-ans << '\n';
    }
                      
    return 0;
}
