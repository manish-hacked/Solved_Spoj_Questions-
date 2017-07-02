#include<bits/stdc++.h>
using namespace std;
 
 
typedef long long int ll;
 
 
int main(){
	ll n,m;
	cin>>n>>m;
	while(n&&m){
		ll arr[m+1][2];
		ll i,j;
		for(i=1;i<=m;i++)
		cin>>arr[i][0]>>arr[i][1];
		ll dp[m+1][n+1];
		for(i=1;i<arr[1][0];i++)
		dp[1][i]=0;
		for(;i<=n;i++)
		dp[1][i]=arr[1][1];
		for(i=2;i<=m;i++){
			for(j=1;j<=n;j++){
				if(arr[i][0]<=j){
					if(arr[i][0]==j){
						dp[i][j]=max(arr[i][1],dp[i-1][j]);
					}else{
						dp[i][j]=max(arr[i][1]+dp[i-1][j-arr[i][0]],dp[i-1][j]);
					}
				}else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		ll k = dp[m][n];
		ll ans;
		for(i=1;i<=n;i++){
			if(dp[m][i]==k){
				ans = i;
				break;
			}
		}
		/**for(i=1;i<=m;i++){
			for(j=1;j<=n;j++)
			cout<<dp[i][j]<<" ";
			cout<<endl;
		}**/
		cout<<ans<<" "<<k<<endl<<endl;
		cin>>n>>m;
	}
} 
