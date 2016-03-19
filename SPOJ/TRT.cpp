#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
int N;
long long int cache[2000][2000];
long long int profit(int A[],int start, int end)
{
     if(start > end) return 0;
     if(cache[start][end]!=-1) return cache[start][end];
     int year = N-end+start;
     cache[start][end] = max( profit(A,start,end-1) + (long long int)A[end]*year,
                 profit(A,start+1,end) + (long long int)A[start]*year);
     return cache[start][end];
 }
int main()
{
    scanf("%d",&N);
    int A[N];
    for(int i = 0;i<N;++i) scanf("%d",&A[i]);
    memset(cache,-1,sizeof(cache));
    printf("%lld",profit(A,0,N-1));
    return 0;
}
