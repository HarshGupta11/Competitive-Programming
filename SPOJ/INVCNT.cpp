#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

       void update(int index, int value,int bit[],int size){     // 1 based index
            while(index <= size){
                  bit[index-1]+=value;      
                  index = index+ (index&(-1*index));
            }
       }
       
       long long int sum(int index,int bit[]){              // 1 based index
            long long int ans = 0;
            while(index > 0){
               ans+=bit[index-1];
               index = index- (index&(-1*index));
            }
            return ans;
       }
              
int main()
{
    int T,n;
    long long int count;
    scanf("%d",&T);
    getchar();
    while(T--){
          count = 0;
          scanf("%d",&n);
          int A[n];
          int B[n];
          for(int i = 0;i<n;++i){
              scanf("%d",&A[i]);
            //  printf("Entered A[i] = %d\n",A[i]);
              B[i] = A[i];
          }
          getchar();
          sort(B,B+n);
          int C[n];
          for(int i = 0;i<n;++i){
              C[i] = int(lower_bound(B,B+n,A[i]) - B)+1;
          //    cout << C[i] << '\n';
          }
          
          int bit[n];
          memset(bit,0,sizeof(bit));
          for(int i = n-1;i>=0;--i){
             // cout << "Entered C[i] = " << C[i] << '\n';    
              count+= sum(C[i]-1,bit); 
             // cout << "Count = " << count;
              update(C[i],1,bit,n) ;
          }
          printf("%lld\n",count);
    }   
              
                   
   
    return 0;
}
