#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
const ll N = 1e6+1;
ll dp[N+1];
vector<ll> ans;
void seive(){
	ll i,j;
	for(i=0;i<N;i++)
	dp[i]=1;
	for(i=2;i<N;i++){
		if(dp[i]==1){
			for(j=i;j<N;j+=i){
				ll cnt=0;
				ll k=j;
				while(k%i==0){
					cnt++;
					k/=i;
				}
				dp[j]*=(cnt+1);
			}
		}
	}
	bool hola[N];
	memset(hola,true,N+1);
	for(i=2;i<N;i++){
		for(j=2*i;j<N;j+=i){
			if(dp[j]%dp[i]!=0)
			hola[j]=false;
		}
	}
	for(i=2;i<N;i++)
	if(dp[i]>3&&hola[i]){
		ans.push_back(i);
	}
}
 
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	seive();
   	ll l = ans.size();
   	ll i;
   	for(i=107;i<l;i+=108){
   		cout<<ans[i]<<endl;	
	}
} 
 
