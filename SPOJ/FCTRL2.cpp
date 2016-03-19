#include <cstdlib>
#include <iostream>
 
using namespace std;
 
inline int input()
{
       int num=0;
       register char ch;
       for(ch = getchar_unlocked();ch<='9' && ch >= '0';ch = getchar_unlocked()){
             num = (num<<3)+(num<<1) + ch-'0';   
       } 
       return num;
}
 
int main()
{
    int t, n, m;
    t = input();
    
    while(t--){
        int ans[200], carry = 0;
        n = input();
        ans[0] = 1;
        m = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0;j<m;++j){
                int temp = ans[j]*i+carry;
                ans[j]  = temp%10;
                carry = temp/10;
            }   
            while(carry != 0)
            {
               ans[m++] = carry%10;
               carry = carry/10;         
            }
        }
        while(m>0)
        {
            printf("%d",ans[--m]);      
        }
        printf("\n");
    }          
    return 0;
}