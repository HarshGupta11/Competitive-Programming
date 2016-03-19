#include <cstdlib>
#include <iostream>
//#include <cstring>
#include <algorithm>
using namespace std;
int A[1000001];
int main()
{
    ios::sync_with_stdio(false);
    int n,k,a,b;
    cin >> n >> k;
   // int A[n];
   // memset(A,0,sizeof(A));
    while(k--){
          cin >> a >> b;
        //  for(int i = a-1;i<b;++i) ++A[i];
          ++A[a-1];
          --A[b];
    }
    for(int i = 1;i<n;++i) A[i]+=A[i-1];
    sort(A,A+n);
    cout << A[n/2];
                       
    return 0;
}
