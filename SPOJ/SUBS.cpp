#include "bits/stdc++.h"

using namespace std;

int binary(string &X, string &Y)
{
    int low = 1, high = 500010, mid, ans = 0, K, i ,j;
    //cout << low << ' ' << high << '\n';
    while(low<=high)
    {             
       mid = low+(high-low)/2;
       K = mid;
       j = 0;
       for(i = 0;i<Y.size();++i){
           if(K == 0){
              K = mid;
              ++j;
              if(j == X.size()) break;
           }      
           if(X[j] == Y[i] && K > 0){
              --K;
           }  
       }
       if(K == 0) ++j;
       if(j == X.size()){
           ans = max(ans,mid);
           low = mid+1;
       }
       else high = mid-1;
    }
    return ans;
}    

int main()
{
    int T;
    cin >> T;
    string X,Y;
    while(T--){
          cin >> X >> Y;
          cout << binary(X,Y) << '\n';
    }     
    return 0;
}
