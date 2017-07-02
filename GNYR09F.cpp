#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
ll find(ll prev,ll n,ll k){
	if(n<0||k<0)
	return 0;
	if(n==0&&k==0)
	return 1;
	if(prev){
		return find(1,n-1,k-1)+find(0,n-1,k);
	}else{
		return find(1,n-1,k)+find(0,n-1,k);
	}
}
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
	ll t;sl(t);
	while(t--){
		ll a,n,k;
		sl(a);sl(n);sl(k);
		ll i,j;
		//cout<<find(0,n-1,k)+find(1,n-1,k)<<endl;
		ll dp[n][k+1][2];
 
		for(j=0;j<=k;j++)
		dp[0][j][0]=dp[0][j][1]=0;
		
		
		
		dp[0][0][0]=dp[0][0][1]=1;
		for(i=1;i<n;i++){
			for(j=0;j<=k;j++){
				dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
				dp[i][j][1] = j>0?dp[i-1][j-1][1]+dp[i-1][j][0]:dp[i-1][j][0];
			}
		}
		cout<<a<<" "<<dp[n-1][k][0]+dp[n-1][k][1]<<endl;
	}
} 
