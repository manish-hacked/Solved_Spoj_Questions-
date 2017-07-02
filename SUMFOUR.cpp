#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
	ll n;sl(n);
	ll a[n],b[n],c[n],d[n];
	ll i,j,k;
	for(i=0;i<n;i++)
	{
		sll(a[i],b[i]);sll(c[i],d[i]);
	}
	ll dp[n*n];
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dp[k]=c[i]+d[j];
			k++;
		}
	}
	sort(dp,dp+n*n);
	sort(d,d+n);
	ll cnt=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ll sum=-(a[i]+b[j]);
			cnt+=(upper_bound(dp,dp+n*n,sum)-lower_bound(dp,dp+n*n,sum));
		}
	}
	printf("%lld\n",cnt);
} 
