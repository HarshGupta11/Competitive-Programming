#include "bits/stdc++.h"

using namespace std;

#define make_pair mp
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

ll matrix[10][10], temp[10][10];
const ll mod = 1e9;
void multiply(ll b[], ll k)
{
	ll c[k];
	for(ll i = 0;i<k;++i){
		c[i] = 0;
		for(ll j = 0;j<k;++j){
            c[i] = (c[i] + (b[j]*temp[i][j])%mod)%mod;
		}
	}
	for(ll i = 0;i<k;++i){
		b[i] = c[i];
	}
}

void matrix_square(ll k)
{ 
	 ll c[k][k];
     for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		c[i][j] = 0;
     		for(ll t = 0;t<k;++t){
                c[i][j] = (c[i][j] + (temp[i][t]*temp[t][j])%mod)%mod;
     		}
     	}
     }  
     for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		temp[i][j] = c[i][j];
     	}
     }
}

void unimultiplication(ll k)
{
	 ll c[k][k];
     for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		c[i][j] = 0;
     		for(ll t = 0;t<k;++t){
                c[i][j] = (c[i][j] + (temp[i][t]*matrix[t][j])%mod)%mod;
     		}
     	}
     }  
     for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		temp[i][j] = c[i][j];
     	}
     }

}

void power(ll n, ll k)
{
	if(n == 0 || n==1) return ;
	/*if(n == 1){
	   unimultiplication(k);
	   return;
	}*/
	power(n/2,k);
	matrix_square(k);
	if(n&1) unimultiplication(k);
	/*cout << "Inside power " << n << ' ' << k << '\n';
    for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		cout << temp[i][j] << ' ';
     	}
     	cout << '\n';
    }	
    cout << "\n\n";*/
}

int main()
{
	ll T,i,j,k,n;
	cin >> T;
	while(T--){
		memset(matrix,0,sizeof(matrix));
		memset(temp,0,sizeof(temp));
		cin >> k;
		ll b[k], c[k];
		for(i = 0;i<k;++i) cin >> b[i];
		for(i = 0;i<k;++i){
		   cin >> c[i];
		   matrix[k-1][k-i-1] = c[i];
		   temp[k-1][k-i-1] = c[i];
		}
		cin >> n;
		if(n <= k){
			cout << b[n-1]%mod << '\n';
			continue;
		}
		for(i = 0;i<k-1;++i){
		    matrix[i][i+1] = 1;
		    temp[i][i+1] = 1;
		}
     /*for(ll i = 0;i<k;++i){
     	for(ll j = 0;j<k;++j){
     		cout << matrix[i][j] << ' ';
     	}
     	cout << '\n';
     }	*/	
		power(n-1,k);

		multiply(b,k);
		cout << b[0]%mod << '\n';
	}
    return 0;
}
