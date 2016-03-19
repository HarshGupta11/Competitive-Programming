#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

int prime[10001],visited[10001], depth;
vector<int> graph[10001];
vector<int> P;

int bfs(int N1, int N2)
{
    queue<int> A;
    int index,i;
    A.push(N1); A.push(-1);
    visited[N1] = 1;
    while(!A.empty()){
         index = A.front();
         A.pop();
         if(index == -1){
              ++depth;
              A.push(-1);
              index = A.front();
              A.pop();
         }
         if(index == -1) return -1;
         if(index == N2) return depth;
         for(i = 0;i<graph[index].size();++i){
             if(visited[graph[index][i]] == 0){
                visited[graph[index][i]] = 1;
                A.push(graph[index][i]);
             }
         }
    }                                     
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,dig1, dig2, dig3,dig4, temp,T,N1,N2;
    for(i = 4;i<=10000;i+=2) prime[i]=1;
    for(i = 3;i<=10000;i+=2){
        if(prime[i] == 0){
           for(j = 2*i;j<=10000;j+=i) prime[j] = 1;
           if(i > 1000)
              P.push_back(i);
        }
    }
    for(i = 0;i<P.size();++i){
        temp = P[i];
        dig1 = temp%10;
        temp/=10;
        dig2 = (temp%10)*10;
        temp/=10;
        dig3 = (temp%10)*100;
        temp/=10;
        dig4 = (temp%10)*1000;
        for(j = P[i]-dig1; j<=P[i]-dig1+9;++j){
            if(prime[j] == 0){
                 graph[P[i]].push_back(j);
                // graph[j].insert(P[i]);
            }
        }
        for(j = P[i]-dig2;j<=P[i]-dig2+99;j+=10){
            if(prime[j] == 0){
                 graph[P[i]].push_back(j);
               //  graph[j].insert(P[i]);
            }  
        } 
        for(j = P[i]-dig3;j<=P[i]-dig3+999;j+=100){
            if(prime[j] == 0){
                 graph[P[i]].push_back(j);
               //  graph[j].insert(P[i]);
            }  
        }    
        for(j = P[i]-dig4;j<=P[i]-dig4+9999;j+=1000){
            if(prime[j] == 0 && j<=10000){
                 graph[P[i]].push_back(j);
               //  graph[j].insert(P[i]);
            }  
        }
     } 
     cin >> T;
     while(T--){
           depth = 0;     
           cin >> N1 >> N2  ;            
           memset(visited,0,sizeof(visited));
           bfs(N1,N2);
           if(depth == -1) cout << "Impossible\n";
           else            cout << depth << '\n';
     }
           
     
               
    //system("pause");
    return 0;
}
