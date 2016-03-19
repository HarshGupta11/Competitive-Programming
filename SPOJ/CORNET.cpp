#include <iostream>
#include <cstdlib>

using namespace std;
long long int top;


inline long long int mod(long long int x)
{
    if(x >=0) return x;
    return -1*x;
}

long long int root(long long int x, long long int nodes[],long long int distance[])
{
    if(x == nodes[x]){
       distance[x] = 0;
       top = x;   
       return 0;
    }
    if(distance[x] == 0)
    distance[x] = (mod(x-nodes[x])%1000)+root(nodes[x],nodes,distance);
    else
        distance[x] += root(nodes[x],nodes,distance);
    nodes[x] = top;
    return distance[x];
}
long long int find(long long int x, long long int y, long long int nodes[], long long int distance[])
{
    root(x,nodes,distance);
    long long int top1 = top;
    root(y,nodes,distance);
    long long int top2 = top;
    if(top1 == top2) return 1;
    return 0;
}
void merge(long long int x,long long int y,long long int nodes[],long long int distance[])
{
    nodes[x] = y;
    distance[x] = (mod(x-y)%1000);
}
int main()
{
   // ios::sync_with_stdio(false);
    long long int T,N,x,y,i;
    char choice;
   // cin >> T;
    scanf("%lld",&T);
    while(T--){
         // cin >> N;
          scanf("%lld",&N);
          long long int nodes[N+1];
          long long int distance[N+1];
          for(i = 1;i<=N;++i){
                nodes[i] = i;
                distance[i] = 0;
          }     
          while(1){
                //cin >> choice;
                scanf("%c",&choice);
                if(choice == 'O') break;
                else if(choice == 'E'){
                     //cin >> x;
                     scanf("%lld",&x);
                     root(x,nodes,distance);
                     printf("%lld\n",distance[x]);
                     //cout << distance[x] << '\n';
                }
                else if(choice == 'I'){
                   //  cin >> x >> y;
                     scanf("%lld%lld",&x,&y);
                     merge(x,y,nodes,distance) ;
                }
          }
    }  
    return 0;
    
}
