#include <cstdlib>
#include <iostream>

using namespace std;
int mod = 1000000007;
 
void multiply(int F[2][2],int M[2][2])
{
  int x =  ((((long long int)F[0][0]*M[0][0])%mod) + (((long long int)F[0][1]*M[1][0])%mod))%mod;
  int y =  ((((long long int)F[0][0]*M[0][1])%mod) + (((long long int)F[0][1]*M[1][1])%mod))%mod;
  int z =  ((((long long int)F[1][0]*M[0][0])%mod) + (((long long int)F[1][1]*M[1][0])%mod))%mod;
  int w =  ((((long long int)F[1][0]*M[0][1])%mod) + (((long long int)F[1][1]*M[1][1])%mod))%mod; 
 /* int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod;
  int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod;
  int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod;
  int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod; */
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(int A[2][2],int n){
  if( n == 0 || n == 1)
      return;
  int M[2][2] = {{1,1},{1,0}};
 
  power(A, n/2);
  multiply(A, A);
 
  if (n%2 != 0)
     multiply(A, M);
}
int main()
{
    //cout << (1%mod)%mod << '\n';
    int T,N,M,ans;
    scanf("%d",&T); 
    while(T--){
          scanf("%d%d",&N,&M);
     
          int A[2][2] = {{1,1},{1,0}};
          int B[2][2] = {{1,1},{1,0}};
          if(N==0) A[0][0] = 0;
          else{
              power(A,N);
              --A[0][0];
          }
          if(M==0) B[0][0] = 0;
          else{
              power(B,M+1);
              --B[0][0];
          }
          ans = (B[0][0]-A[0][0]+mod)%mod;
          printf("%d\n",ans) ;
     }
    return 0;
}
