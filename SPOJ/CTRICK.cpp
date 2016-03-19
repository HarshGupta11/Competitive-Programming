/*input
1
20000
*/
#include "bits/stdc++.h"

using namespace std;

int A[20001], tree[70000];

void create(int start , int end, int pos)
{
	if(start > end) return;
	if(start == end){
		if(A[start] == 0) tree[pos] = 1;
		else              tree[pos] = 0; 
		return;
	}
	create(start, (start+end)/2,2*pos+1);
	create( (start+end)/2 + 1,end,2*pos+2);

	tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

int query( int start, int end, int pos, int n)
{
	if(start > end) return -1;
	if(start == end){
		if(tree[pos] == n) return start;
		else               return -1; 
	}
	//if(tree[pos] == n) return end;

	if(tree[2*pos+1] >= n) return query(start,(start+end)/2,2*pos+1,n);
	else                   return query((start+end)/2+1,end,2*pos+2,n-tree[2*pos+1]); 
}

void update( int start , int end, int pos, int index, int value)
{
	if(start > end) return;
	if(start == end){
		if(index == start){
		  A[index] = value;
		  tree[pos] = 0;
	    }
		return;
	} 
	if(index <= (start+end)/2) update(start,(start+end)/2,2*pos+1,index, value);
	else                       update((start+end)/2+1,end,2*pos+2,index, value);
    tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}

int main()
{
	ios::sync_with_stdio(false);
	int T,n,i, rotate,index;
	cin >> T;
	while(T--){
		cin >> n;
		
		memset(A,0,sizeof(A));
		memset(tree,0,sizeof(tree));
		create(0,n-1,0);
		//for(i = 0;i<2*n;++i) cout << tree[i] << ' ';
	   // index = query(A,tree,0,n-1,0,2);
	   // update(A,tree,0,n-1,0,index,1);
        rotate = 1;  
		for(i = 1;i<=n;++i){
          //rotate = (i*(i+1))/2;
         // ++rotate;
	      --rotate;
	      rotate+=(i+1);	
	      rotate = (rotate%tree[0]);	
	      if(rotate == 0) rotate = tree[0];
          index = query(0,n-1,0,rotate);
          update(0,n-1,0,index,i);
        /*  cout << "A: ";
          for(int j =0;j<n;++j) cout << A[j] << ' ';
          cout << "\nTree: ";
          for(int j =0;j<2*n;++j) cout << tree[j] << ' '; 
          cout << "\nIndex " << i << ' ' << index << ' ' << rotate << '\n'; */

		}
		for(i =0;i<n;++i) cout << A[i] << ' '; 
        cout << '\n';
    }


	return 0;
}