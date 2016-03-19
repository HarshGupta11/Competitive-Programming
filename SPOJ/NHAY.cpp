#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
int main()
{
	//ios::sync_with_stdio(false);
    ll N,i,j;
    string pattern;
    char ch;
    while(cin >> N){
        //cout << N << '\n';
        cin >> pattern;
		ll A[N];
		A[0] = 0;

		// My Own implimented KMP without seeing any pseudocode or any implimentation
		for(i = 1;i<N;++i){
			j = i-1;
			while(pattern[i] != pattern[A[j]] && j>0 && j!=A[j]) j = A[j];
			if(pattern[i] == pattern[A[j]]) A[i] = A[j]+1;
			else                            A[i] = 0;
			//cout << i << ' ' << A[i] << '\n';
		}
		//cout << "Entered\n";
		j = 0;
		i = 0;
		//cin >> ch;
		getchar();
		while((ch = getchar()) != '\n' && ch != EOF){
			//cout << ch << '\n';
	    	while(ch != pattern[j] && j > 0) j = A[j-1];
	    	if(ch == pattern[j]){
	    		++j;
	    	}
	    	if(j == N){
	    		cout << i-N+1 << '\n';
	    		//++size;
	    	}
	    	++i;
	    	//cin >> ch;
	    	//cout << i << ' ' << ch << ' ' << "Hello\n";
	    } 
	    cout << '\n';
    }

	return 0;
}