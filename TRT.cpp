#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug1(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
ll *arr;
ll dp[2001][2001];
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll n,i,j;sl(n);
	arr = (ll*)malloc(sizeof(ll)*(n+1));
	for(i=1;i<=n;i++)sl(arr[i]);
	for(i=1;i<=n;i++)
	dp[i][i]=arr[i]*n;
	ll k=n-1;
	for(i=n-1;i>0;i--){
		for(j=i+1;j<=n;j++){
			k=n - (j-i+1) + 1;
			dp[i][j]=max(arr[i]*k+dp[i+1][j],arr[j]*k+dp[i][j-1]);
		}
	}
	cout<<dp[1][n]<<endl;	
}
