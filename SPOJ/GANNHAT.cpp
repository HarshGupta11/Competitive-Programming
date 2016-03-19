#include "bits/stdc++.h"

using namespace std;

struct point{
       int x,y,i;
};

int bit[(int)2e5+5];
int bit2[(int)2e5+5];
point A[(int)2e5+5];
int ans[(int)2e5+5];
int compy[(int)2e5+5];
int y[(int)2e5+5];

int func(point a, point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int func2(int a, int b)
{
    if(A[a].y < A[b].y) return true;
    if(A[a].y == A[b].y && A[a].x < A[b].x) return true;
    return false;
}


inline int minimum(int a, int b)
{
       if(a < b) return a;
       return b;
}

int insert2(int index, int value)
{
    while(index <= (int)2e5+5){
          if(value > bit[index]) bit[index] = value;
          index+=(index&-index);
    }      
}

int query2(int index)
{
    int result = -1061109568;
    while(index > 0){
          if(result < bit[index]) result = bit[index];
          index-=(index&-index);
    }
    return result;      
}

int insert3(int index, int value)
{
    while(index <= (int)2e5+5){
          if(value > bit2[index]) bit2[index] = value;
          index+=(index&-index);
    }      
}

int query3(int index)
{
    int result = -1061109568;
    while(index > 0){
          if(result < bit2[index]) result = bit2[index];
          index-=(index&-index);
    }
    return result;      
}
int main()
{
   // cout << 0 << '\n';
    memset(bit,-64,sizeof(bit));
    memset(bit2,-64,sizeof(bit));
 
    int n,i,xsumy,xdiffy;
   
    scanf("%d",&n);
   // point A[n];
   // int ans[n];
    memset(ans,64,sizeof(ans));
    for(i = 0;i<n;++i){
        scanf("%d%d",&A[i].x,&A[i].y);
        ++A[i].x;
        ++A[i].y;
        A[i].i = i;
        ans[i] = INT_MAX;
        y[i] = A[i].y;
     //   compy[i] = i+1;
    }
    if(n == 1){ 
         printf("0\n"); 
         return 0;
    }
    sort(y,y+n);
    for(i = 0;i<n;++i){
       compy[i] = (int)(lower_bound(y,y+n,((A[i]).y)) - y)+1;  
       } 
   // sort(compy,compy+n,func2);
    sort(A,A+n,func);
  //  for(i = 0;i<n;++i) cout << compy[i] << ' ';
  //  cout << '\n';
    //Case 1 + Case 2
    insert2(compy[A[0].i],A[0].x+A[0].y);
    insert3((int)2e5+5 - compy[A[0].i],A[0].x - A[0].y);
    for(i = 1;i<n;++i){
        xsumy= query2(compy[A[i].i]); 
        ans[A[i].i] = minimum(ans[A[i].i],A[i].x+A[i].y - xsumy); 
        insert2(compy[A[i].i],A[i].x+A[i].y)  ;
        
        xdiffy = query3((int)2e5+5 - compy[A[i].i]);
        ans[A[i].i] = minimum(ans[A[i].i],A[i].x - A[i].y - xdiffy);
        insert3((int)2e5+5 - compy[A[i].i], A[i].x - A[i].y);
    }
      
    
    memset(bit,-64,sizeof(bit));
    memset(bit2,-64,sizeof(bit));
    // Case 3 + Case 4 
    insert2(compy[A[n-1].i],A[n-1].y-A[n-1].x);
    insert3((int)2e5+5-compy[A[n-1].i] ,-A[n-1].x - A[n-1].y); 
    for(i = n-2;i>=0;--i){
        xdiffy = query2(compy[A[i].i]);
        ans[A[i].i] = minimum(ans[A[i].i],A[i].y - A[i].x - xdiffy);
        insert2(compy[A[i].i] , A[i].y - A[i].x);
        xsumy = query3((int)2e5+5 - compy[A[i].i]);
        ans[A[i].i] = minimum(ans[A[i].i],-A[i].x - A[i].y - xsumy);
        insert3((int)2e5+5-compy[A[i].i],-A[i].x - A[i].y);
    }
   

    
    for(i = 0;i<n;++i){
          printf("%d\n",ans[i]);
    }
          
    return 0;
}
