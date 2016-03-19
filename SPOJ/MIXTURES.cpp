#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,k;
    //cin >> T;
    while(cin >> n){
          int A[n+1];
          long long int cum[n+1];
          A[0] = 0;
          cum[0] = 0;
          for(i = 1;i<=n;++i){
              cin >> A[i];
              cum[i] = cum[i-1]+A[i];
          }
          long long int smoke[n+1][n+1];
          for(i = n;i>0;--i){
              for(j = i;j<=n;++j){
                  if(i!=j) smoke[i][j] = INT_MAX;
                  else     smoke[i][j] = 0;
                  for(k=i;k<j;++k){
                      smoke[i][j] = min(smoke[i][j], smoke[i][k]+smoke[k+1][j]+(((cum[k]-cum[i-1])%100)*((cum[j]-cum[k])%100)));
                  }
              }
          }
          cout << smoke[1][n] << '\n';
    }                        
    return 0;
}
