#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		ll h,w;
		cin>>h>>w;
		ll arr[h][w];
		ll dp[h][w];
		ll i,j;
		for(i=0;i<h;i++)
		for(j=0;j<w;j++)
		cin>>arr[i][j];
		for(j=0;j<w;j++)
		dp[0][j]=arr[0][j];
		for(i=1;i<h;i++){
			for(j=0;j<w;j++){
				if(j==0)
				dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
				else if(j==(w-1))
				dp[i][j]=arr[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
				else
				dp[i][j]=arr[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
			}
		}
		ll maxx=-1;
		for(i=0;i<w;i++)
		if(dp[h-1][i]>maxx)
		maxx=dp[h-1][i];
		cout<<maxx<<endl;
	}
} 
