#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
ll m;
ll get(ll a,ll b){
	if(b==0)
	return 1;
	ll p = get(a,b/2);
	if(b%2==0)
	return (p*p)%m;
	else
	return ((a%m)*((p*p)%m))%m;
}
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll p,n;
	sl(p),sl(n);
	ll i,j;
	while(p&&n){
		vector<ll> v;
		m=p;
		p--;
		for(i=2;i*i<=p;i++){
			if(p%i==0){
				v.push_back(i);
				while(p%i==0){
					p/=i;
				}
			}
		}
		if(p>1)
		v.push_back(p);
		ll l = v.size();
		while(n--){
			ll a;sl(a);
			for(i=0;i<l;i++){
				if(get(a,(m-1)/v[i])==1)
				break;
			}
			if(i==l)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
		sl(p),sl(n);
	}
} 
