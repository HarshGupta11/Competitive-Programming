#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int n,x,y,ans;
    scanf("%d",&n);
    while(n--){
          scanf("%d%d",&x,&y);
          if(y==x){
             if(y&1) ans = y+x-1;
             else    ans = 2*x;
          }
          else if(y==x-2){
             if(y&1) ans = y+x-1;
             else    ans = 2*y+2;
          }
          else{
             printf("No Number\n");
             continue;
          }
          printf("%d\n",ans);
    }              
    
    return 0;
}
