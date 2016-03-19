#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> A;
    multiset<int>::iterator it;
    int n,q,a;
    long long int ans = 0;
    scanf("%d",&n);
    while(n--){
          scanf("%d",&q);
          while(q--){
                scanf("%d",&a);
                A.insert(a);
          } 
          it = A.begin();
          ans-=(*it);
          A.erase(it);
          it = A.end(); 
          --it;
          ans+=(*it);
          A.erase(it);
    }
    printf("%lld",ans);         
 
    return 0;
}
