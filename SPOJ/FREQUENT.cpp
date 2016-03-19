#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

struct stree
{
       int el, er, em, fl,fr,fm;
       };
       
int A[100001];
stree tree[1000000];
void construct(int start , int end, int pos)
{
     if(start > end) return;
     if(start == end){
        tree[pos].fl = tree[pos].fr = tree[pos].fm = 1;
        tree[pos].el = tree[pos].er = tree[pos].em = A[start];
        
     //   cout << start << ' ' << end << ' ' << pos << ' ' << tree[pos].em << ' ' << tree[pos].fm << ' ' << tree[pos].el << ' ' << tree[pos].fl << ' ' << tree[pos].er << ' ' << tree[pos].fr << '\n';
        return;
     }
     int left = 2*pos+1;
     int right = 2*pos+2;
     construct(start,(start+end)/2,left);
     construct((start+end)/2+1,end,right);
     
     tree[pos].el = tree[left].el;
     tree[pos].er = tree[right].er;
     if(tree[left].el == tree[right].el){
        tree[pos].fl = tree[left].fl + tree[right].fl;
     }
     else{
          tree[pos].fl = tree[left].fl;
     }   
     if(tree[left].er == tree[right].er){
        tree[pos].fr = tree[left].fr + tree[right].fr;
     }
     else{
          tree[pos].fr = tree[right].fr;
     }    
     

    // if(tree[pos].fm < tree[2*pos+1].fm){
        tree[pos].fm = tree[left].fm;
        tree[pos].em = tree[left].em;
    // } 
     if(tree[pos].fm < tree[right].fm){
        tree[pos].fm = tree[right].fm;
        tree[pos].em = tree[right].em;
     }    
     
     if(tree[left].er == tree[right].el){
        if(tree[pos].fm < tree[left].fr + tree[right].fl){                 
        tree[pos].fm = tree[left].fr + tree[right].fl;
        tree[pos].em = tree[left].er;
        }
     }    
   //  cout << start << ' ' << end << ' ' << pos << ' ' << tree[pos].em << ' ' << tree[pos].fm<< ' ' << tree[pos].el << ' ' << tree[pos].fl << ' ' << tree[pos].er << ' ' << tree[pos].fr << '\n';      
                 
                          
 }
 
stree query( int start, int end, int pos, int l, int r)
{
      if(start > end || end < l || start > r){
               stree temp;
              // temp.er = temp.el = temp.em = -1000000;
              // temp.fr = temp.fl = temp.fm = 0;
               return temp;
      }
      if( l <= start && end <= r) return tree[pos];
      
      stree left = query(start,(start+end)/2,2*pos+1, l,r);
      stree right = query((start+end)/2+1,end,2*pos+2,l,r);
      if(l > (start+end)/2) return right;
      else if(r <= (start+end)/2) return left;
      stree mix;
     
     mix.el = left.el;
     mix.er = right.er;
     if(left.el == right.el){
        mix.fl = left.fl + right.fl;
     }
     else{
          mix.fl = left.fl;
     }   
     if(left.er == right.er){
        mix.fr = left.fr + right.fr;
     }
     else{
          mix.fr = right.fr;
     }    
     

  //   if(mix.fm < left.fm){
        mix.fm = left.fm;
        mix.em = left.em;
  //   } 
     if(mix.fm < right.fm){
        mix.fm = right.fm;
        mix.em = right.em;
     }       
     
     if(left.er == right.el){
        if(mix.fm <  left.fr + right.fl) {       
        mix.fm = left.fr + right.fl;
        mix.em = left.er;
        }
     }       
     return mix;
                 
                                
      
      }
int main()
{
   // ios::sync_with_stdio(false);
    int n,q,i,l,r;
    while(1){
       //  cin >> n;
         scanf("%d",&n);
         if(n == 0) return 0; 
         //cin >> q;
         scanf("%d",&q);
        // int A[n];
        // stree tree[10*n];
         for(i = 0;i<n;++i) cin >> A[i];
         //system("pause");
         //for(i = 0;i<n;++i) cout << A[i] << ' '; 
         construct(0,n-1,0);
        // system("pause");
        // for(i = 0;i<4*n;++i) cout << i << ' ' << tree[i].em << ' ' << tree[i].fm << '\n';
        // system("pause");
        // cout << '\n';
         while(q--){
              // cin >> l >> r;
               scanf("%d%d",&l,&r);
               stree mix = query(0,n-1,0,l-1,r-1);
               //cout << mix.fm << '\n';
               printf("%d\n",mix.fm);
         }
    }     
            
}
