#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long int A[100001];
long long int prime[100001];
long long int ans[100001];
vector<long long int> answer[10001];
int main()
{
  //  ios::sync_with_stdio(false);
    long long int i,j, tot,T, low, high,k,l,h;
    vector<long long int> P;
    P.push_back(2);
    for(i = 4;i<=100000;i+=2) prime[i] = 1;
    for(i = 3;i<=100000;i+=2){
        if(prime[i] == 0){
           for(j = 2*i;j<=100000;j+=i) prime[j] = 1;
           P.push_back(i);
        }           
    }
    
    for(i = 1;i<=100000;++i){
        A[i] = i;
        ans[i] = 1;
    }
    for(i = 0;i<P.size();++i){ 
        for(j = P[i];j<=100000;j+=P[i]){
              
            if(A[j] > 1){
               tot = 0;      
               while(A[j]%P[i] == 0){ ++tot; A[j]/=P[i];}
               ans[j]*= (2*tot+1);         
            }
        }  
    }
    
    for(i = 1;i<=100000;++i){
        answer[ans[i]].push_back(i*i);
    }  
   // cin >> T;
    scanf("%lld",&T);
    while(T--){
         //cin >> k >> low >> high;
         scanf("%lld%lld%lld",&k,&low,&high);
         l = (long long int)(lower_bound(answer[k].begin(),answer[k].end(),low)-answer[k].begin());
         h = (long long int)(upper_bound(answer[k].begin(),answer[k].end(),high) -answer[k].begin());
        // cout << distance(l,h) << '\n';
         printf("%lld\n",h-l);
    }     
    return 0;
}
