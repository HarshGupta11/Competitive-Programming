#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

struct stop
{
       int dist, fuel;
};

int func(stop A, stop B)
{
    if(A.dist < B.dist) return true;
    return false;
}
int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    ll T,N,L,P,i,ans,check,current;
    cin >> T;
    while(T--){
          cin >> N;
          stop A[N+2];
          ans = 0;
          check = 1;
          for(i = 1;i<=N;++i) cin >> A[i].dist >> A[i].fuel;
          cin >> L >> P;
          A[0].dist = 0;
          A[0].fuel = P;
          A[N+1].dist = L;
          A[N+1].fuel = 0;
          priority_queue<int> B;
          for(i = 1;i<=N;++i) A[i].dist = L - A[i].dist;
          current = P;
          sort(A,A+N+2,func);
          for(i = 1;i<=N+1;++i){
                if(current >= A[i].dist) B.push(A[i].fuel);
                else{
                     while(current < A[i].dist && !B.empty()){
                           current+= B.top();
                          // cout << "Adding " << ' ' << B.top() << ' ' << current << '\n'; 
                           B.pop();
                           ++ans;
                     }
                     if(current < A[i].dist){
                                //cout << i << ' ' << current << ' ' << A[i].dist << ' ' << A[i].fuel << '\n';
                                check = 0;
                                break;
                     }
                     B.push(A[i].fuel);
                }  
                //cout << i << ' ' << B.top() << ' ' << current << ' ' << A[i].dist << ' ' << A[i].fuel << '\n'; 
          }
          if(check == 1) cout << ans << '\n';
          else           cout << -1 << '\n';
    }
                
               
    return 0;
}
