#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int binary(int X[], int C, int N)
{
    //cout << "Entered\n";
    int low = 0,high= (int)X[N-1]-X[0], mid, cows, current,i;
    int ans = 0;
    while(low <= high)
    {
              mid = low + (high-low)/2;
              current = X[0];
              cows = 1;
              for(i = 1;i<N;++i){
                  if(X[i]-current >= mid){
                     current = X[i];
                     ++cows;
                  }               
              }
              if(cows == C || cows > C){
                      ans = max(ans,mid);
                      low = mid+1;
              }
              else if(cows < C) high = mid-1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int T,N,C,i;
    cin >> T;
    //cout << T << '\n';
    while(T--){
    cin >> N >> C;
    //cout << N << ' ' << C << '\n';
    int X[N];
    for(i = 0;i<N;++i) cin >> X[i];
    sort(X,X+N);
    cout << binary(X,C,N) << '\n';
    }
    return 0;
}
