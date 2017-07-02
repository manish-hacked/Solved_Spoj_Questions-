#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
ll dp[2000][2000];
 
ll get(ll h,ll a,ll p,ll cnt){
	if(h<=0||a<=0)
	return -1;
	if(p==1){
		if(dp[h][a]!=-1)
		return cnt+dp[h][a];
		dp[h][a]=max(get(h-5,a-10,(ll)2,1),get(h-20,a+5,(ll)3,1));
		cnt+=dp[h][a];
		return cnt;
	}
	cnt=cnt+get(h+3,a+2,1,1);
	return cnt;
}
 
 
int main(){
	//seive();
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll i,j;
   	for(i=1;i<=1500;i++)
   	for(j=1;j<=1500;j++)
   	dp[i][j]=-1;
   	ll t;cin>>t;
   	while(t--){
   		ll h,a;
   		ll ans=0;
		cin>>h>>a;
		cout<<get(h,a,2,1)<<endl;	
	}
} 
