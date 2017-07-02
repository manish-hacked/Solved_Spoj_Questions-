#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
#define gcd __gcd
 
ll shrt(string s,ll m){
	ll ans=0;
	ll l = s.length();
	ll i,j;
	for(i=0;i<l;i++){
		ll p = s[i]-'0';
		ans = (ans*10+p)%m;
	}
	return ans;
}
 
int main(){
	ll t;
	sl(t);
	while(t--){
		ll a;sl(a);
		string s;cin>>s;
		if(a==0){
			cout<<s<<endl;
			continue;
		}
		ll p = shrt(s,a);
		//cout<<p<<endl;
		debug(gcd(a,p));		
	}
} 
