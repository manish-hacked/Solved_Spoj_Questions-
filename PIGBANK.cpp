#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug1(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll m = 1e9+7;
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll t;sl(t);
	while(t--){
		ll n,e,f;sl(e);sl(f);sl(n);
		ll req=f-e;
		ll arr[n][2];
		ll i,j,k;
		for(i=0;i<n;i++){
			scanf("%lld%lld",&arr[i][0],&arr[i][1]);
		}
		ll dp[req+1];
		dp[0]=0;
		for(i=1;i<=req;i++){
			ll minn=m;
			for(j=0;j<n;j++){
				ll a = arr[j][0];
				ll b = arr[j][1];
				if(i>=b){
					if(dp[i-b]!=m){
						minn = min(minn,dp[i-b]+a);
					}
				}	
			}
			dp[i]=minn;
		}
		if(dp[req]==m){
			cout<<"This is impossible."<<endl;
		}else{
			printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[req]);
		}
	}	
}
