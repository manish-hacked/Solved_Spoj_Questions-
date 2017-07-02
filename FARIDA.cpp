#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
 
typedef long long int ll;
 
ll max(ll a,ll b){
	return (a>=b)?a:b;
}
 
int main(){
	ll t;
	scanf("%lld",&t);
	ll k;
	for(k=0;k<t;k++){
		ll n;
		scanf("%lld",&n);
		long long int arr[1001], dp[1001];
		ll i,j;
		for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
		if(n==1){
			printf("Case %lld: %lld\n",k+1,arr[0]);
			continue;
		}else if(n==2){
			ll p = max(arr[0],arr[1]);
			printf("Case %lld: %lld\n",k+1,p);
			continue;
		}
			dp[0]=arr[0];
			dp[1]=max(arr[0],arr[1]);
			for(i=2;i<n;i++){
				dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
			}
			printf("Case %lld: %lld\n",k+1,dp[n-1]);
	}
	return 0;
} 
