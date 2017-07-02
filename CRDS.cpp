#include<bits/stdc++.h>
using namespace std;
 
#define m 1000007
 
typedef long long int ll;
ll dp[1000001]={0};
 
ll value(ll n){
	if(n==1)
	return 2;
	if(!dp[n]){
		dp[n] = ((n-1)%m+(2*(n%m))%m+value(n-1))%m;
	}
	return dp[n];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<value(n)<<endl;
	}
} 
