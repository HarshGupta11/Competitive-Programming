#include "bits/stdc++.h"

using namespace std;

int memo[101][101];
int beat[101][101];
int A[101];

int ispossible(int i, int j, int n)
{
    //cout << i << ' ' << j << '\n';
    if(i > j) return 1;
    if(i == j){
       if(beat[A[(i-1+n)%(n)]][A[i%n]] == 1) return 1;
       if(beat[A[(j+1+n)%(n)]][A[i%n]] == 1) return 1;
       return 0;
    }
    int & ret = memo[i][j];
    if(ret != -1) return ret;
    for(int k = i;k<=j;++k){
        if(beat[A[(i-1+n)%(n)]][A[k%n]] == 1 || beat[A[(j+1+n)%(n)]][A[k%n]] == 1){
           ret = ispossible(i,k-1,n)&ispossible(k+1,j,n);
           if(ret == 1) return ret;
        }
    }
    ret = 0;
    return ret;                                    
}
int main()
{
    ios::sync_with_stdio(false);
    int n,i,j,T;
    string str;
  cin >> T;
  while(T--){  
    cin >> n;
    
    vector<int> ans;
    for(i = 0;i<n;++i){
        cin >> str;  
        for(j = 0;j<=n;++j){
               
            beat[i][j] = str[j]-'0';
        }
      //  A[i]=i;
    }
    
    for(i = 0;i<n;++i){
        for(j = 0;j<n;++j){
            A[j] = (j+i)%n;
        } 
        memset(memo, -1, sizeof(memo));    
        if(ispossible(1,n-1,n)){
           ans.push_back((i+1)%(n+1));
          // cout << "Inserting " << i+1 << '\n';
        }
    }
    cout << ans.size() << '\n';
    for(i = 0;i<ans.size();++i){
        cout << ans[i] << '\n';
    }     
  } 
    return 0;
}
