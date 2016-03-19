#include <iostream>
#include <cstdio>

using namespace std;
#define size 1000001
long long int fib1[size];
long long int fib2[size];
long long int sum1[size];
long long int sum2[size];

void egcd(long long int a,long long int b,long long int &x,long long int &y,long long int &g)    // a != 0 and b!= 0
{
    long long int x0 = 1, x1 = 0;
    long long int y0 = 0, y1 = 1;
    long long int x2,y2;
    long long int rem = a%b;
    long long int q = a/b;
     while(rem != 0){
           x2 = x0 - q*x1;
           y2 = y0 - q*y1;
           
           a = b;
           b = rem;
           rem = a%b;
           q = a/b;
           x0 = x1, y0 = y1;
           x1 = x2; y1 = y2;   
     }
     // ax+by = 1                  g = gcd(a,b)
     x = x2; y = y2; g = b;      
             
 }
 
int main()
{
    fib1[1] = 1; fib1[2] = 0;
    fib2[1] = 0; fib2[2] = 1;
    sum1[1] = fib1[1]; sum1[2] = sum1[1]+fib1[2];
    sum2[2] = fib2[1]; sum2[2] = sum2[1]+fib2[2]; 
    long long int i,r,k,T,x,y,g,multiple,multiple2,finalx,finaly;
    for(i = 3;i<=size;++i){
        fib1[i]=fib1[i-1]+fib1[i-2];  
        fib2[i]=fib2[i-1]+fib2[i-2];
        sum1[i] = sum1[i-1]+fib1[i];
        sum2[i] = sum2[i-1]+fib2[i];
    } 
    while(1){
          cin >> r;
          if(r==0) return 0;
          cin >> k >> T;
          for(i = 1;i<=100000;++i){
              if((T - sum1[r]*i)%sum2[r] == 0){
                  finalx = i;
                  finaly = (T - sum1[r]*i)/sum2[r];
                  break;
              }
          } 
          cout << finalx << ' ' << finaly << ' ' << (fib1[r]*finalx+fib2[r]*finaly)*k << '\n';    
    }     
    return 0;
}
