#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
long long int sum(long long int index,long long int bit[])
{
    long long int ans = 0;
    while(index > 0){
          ans += bit[index-1];
          index-=(index&-index);
    }
    return ans;          
}

long long int update(long long int index,long long int value,long long int bit[],long long int size)
{
     while(index <= size){
           bit[index-1]+=value;
           index+=(index&-index);
     }
}      
     
int main()
{
    ios::sync_with_stdio(false);
    long long int T,n,choice,p,q,v,c;
    long long int sum_q, sum_p;
    cin >> T;
    while(T--){
          cin >> n >> c;
          long long int bit[n];
          long long int bit2[n];
          memset(bit,0,sizeof(bit));
          memset(bit2,0,sizeof(bit2));
          while(c--){
                cin >> choice;
                if(choice == 0){
                    cin >> p >> q >> v;     
                    update(p,v,bit,n);
                    update(q+1,-v,bit,n);
                    update(p,v*(p-1),bit2,n);
                    update(q+1,-v*q,bit2,n);
                }
                else if(choice == 1){
                    cin >> p >> q;
                    sum_q = sum(q,bit)*q-sum(q,bit2);
                    sum_p = sum(p-1,bit)*(p-1)-sum(p-1,bit2);
                    cout << sum_q - sum_p << '\n'; 
                }
          }
    } 
                       
    
    return 0;
}
