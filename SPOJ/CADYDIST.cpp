#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
    int n;
    long long int amount;
    scanf("%d",&n);
    while(n!=0){
        amount = 0;        
        int student[n], price[n];
        for(int i = 0;i<n;i++) scanf("%d",&student[i]);
        for(int i = 0;i<n;i++) scanf("%d",&price[i]);
        sort(student,student+n);
        sort(price,price+n,greater<int>());
        for(int i=0;i<n;i++){
            amount+=((long long int)student[i] * (long long int)price[i]);
        }
        printf("%lld\n",amount);
        scanf("%d",&n);
    }                    
    return 0;
}

