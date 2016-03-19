/*input
2
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SET 1 2 5
SET 0 2 7
SET 2 1 -8
SET 3 1 -3
SET 3 2 4
SET 3 3 5
SET 2 3 -2
SET 0 3 4
SET 1 3 -10
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
SET 2 2 -12
SUM 0 0 2 2
SET 0 0 6
SUM 0 0 2 2
SUM 1 1 2 3
SUM 0 0 2 3
SUM 1 2 3 2 
END
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END
*/


#include "bits/stdc++.h"

using namespace std;

long long int bit[1025][1025];

long long int sum(long long int x, long long int y)
{
	long long int result = 0,i,j;
	for(i = x;i>0;i-=(i&-i)){
		for(j = y;j>0;j-=(j&-j)){
			result+=bit[i][j];
		}
	}
	return result;
}

void update(long long int x, long long int y, long long int value, long long int size)
{
	long long int i,j;
	for(i = x;i<=size;i+=(i&-i)){
		for(j = y;j<=size;j+=(j&-j)){
			bit[i][j]+=value;
		}
	}
}

void print(long long int size)
{
	for(long long int i = 1;i<=size;++i){
		for(long long int j = 1;j<=size;++j){
			cout << sum(i,j)-sum(i-1,j)-sum(i,j-1)+sum(i-1,j-1) << ' '; 
		}
		cout << '\n';
	} 
	cout << "\n";
}
int main()
{
	//ios::sync_with_stdio(false);
	long long int T,x1,y1,x2,y2,num,n,i,j;
	//string s;
	char s[4];
	//cin >> T;
	scanf("%lld",&T);
	while(T--){
		cin >> n;
		//memset(bit,0,sizeof(bit));
		for(i = 1;i<=n;++i){
			for(j = 1;j<=n;++j){
				bit[i][j] = 0;
			}
		}
		while(1){
            //cin >> s;
            scanf("%s",s); 
            if(strcmp(s,"END")==0) break;
            else if(strcmp(s,"SET")==0){
            	//cin >> x1 >> y1 >> num;
            	scanf("%lld%lld%lld",&x1,&y1,&num);
            	++x1; ++y1;
            	long long int val = sum(x1,y1)-sum(x1-1,y1)-sum(x1,y1-1)+sum(x1-1,y1-1);
            	update(x1,y1,num-val,n);
            	
            	//cout << x1 << ' ' << y1 << ' ' << num << ' ' << val << ' ' << num-val << "\n";
            	//print(n);
            }
            else if(strcmp(s,"SUM")==0){
            	//cin >> x1 >> y1 >> x2 >> y2;
            	scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            	++x1;++y1;++x2;++y2;
            	printf("%lld\n",sum(x2,y2)-sum(x2,y1-1) -sum(x1-1,y2) +sum(x1-1,y1-1));
            	//cout << "Sum"<< sum(x2,y2) << ' ' << sum(x1-1,y2) << ' ' << sum(x2,y1-1) << ' ' << sum(x1-1,y1-1) << ' ' << sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1) << '\n';
            }
		}
		//cout << '\n';
		printf("\n");
	}
	return 0;
}