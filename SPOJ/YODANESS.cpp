#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;
long long int sum(int index,int bit[])
{
     long long int ans = 0; 
     while(index > 0){
        ans += bit[index-1];
        index = index - (index & (-1*index));
     }
     return ans;      
 }
 
void update(int index, int value, int bit[], int size)
{
     while(index <= size){
           bit[index-1]+=value;
           index = index+(index&(-1*index));
     }      
 } 
int main()
{
    int T,n;
    long long int count;
    string temp;
    scanf("%d",&T);
    while(T--){
          count = 0;     
          scanf("%d",&n);     
          string A[n];
          count = 0;
          map<string, int> B;   
          for(int i = 0;i<n;++i){
              cin >> A[i];
             // cout << A[i] << ' ';
          }
         // cout << '\n';
          for(int i = 0;i<n;++i){
              cin >> temp;
              B[temp] = i+1;
            //  cout << temp << ' ' << B[temp] << '\n';
          }
          int bit[n];
          memset(bit,0,sizeof(bit));
          for(int i = n-1;i>=0;--i){
             // cout << B[A[i]] << ' ';    
              count+= sum(B[A[i]]-1,bit);
             // cout << sum(B[A[i]]-1,bit) << ' ' << count << '\n';
              update(B[A[i]],1,bit,n);
          }    
     /*     for(int i = 0;i<n;++i){
              for(int j = 0;j<n;++j){
                  if(i < j && B[A[i]] > B[A[j]]) ++count;
              }
          } */ 
          printf("%lld\n",count);            
    }
    return 0;
}
