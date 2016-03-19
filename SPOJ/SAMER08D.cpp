#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
 
inline int maximum(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
   ios::sync_with_stdio(false);
   string A, B;
   int T,max;
   cin >> T;
   while(T!=0){
    cin >> A;
    cin >> B;
    int temp[A.size()+1][B.size()+1];
    int ans;
    for(int i = 0;i<=A.size();++i){
        temp[i][0] = 0;
        } 
    for(int i = 0;i<=B.size();++i){
        temp[0][i] = 0;
        }  
    for(int i = 1;i<=A.size();++i){
        for(int j = 1;j<=B.size();++j){
            ans = 0;
            temp[i][j] = maximum(temp[i-1][j],temp[i][j-1]);
            while(0 <= i-1-ans && 0 <= j-1-ans && A[i-1-ans] == B[j-1-ans]){
                  ++ans;    
                  if(ans >= T)   temp[i][j] = maximum(temp[i][j],temp[i-ans][j-ans]+ans);
            }
             
            //cout << temp[i][j] << ' ';
        }
       // cout << endl;
    }
    cout << temp[A.size()][B.size()] << '\n';
    cin >> T;
   }          
    return 0;
}