#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug1(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
#define mp make_pair
ll BIT[30001]={0};
ll sum(ll index){
	ll sum=0;
	while(index!=0){
		sum = sum + BIT[index];
		index= index&(index-1);
	}
	return sum;
}
void update(ll index,ll value,ll n){
	while(index<=n){
		BIT[index]+=value;
		index = index+(index&(-index));
	}
}
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll n;sl(n);
	ll arr[n];ll i,j;
	pair<ll,ll> p2[n];
	for(i=0;i<n;i++){
		ll a;sl(a);
		p2[i]=mp(a,i+1);
	}
	ll q;sl(q);
	pair< pair<ll,ll> , pair<ll,ll> > p1[q];
	for(i=0;i<q;i++){
		ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
		p1[i]=mp(mp(c,i),mp(a,b));
	}
	ll res[q];
	sort(p1,p1+q,greater< pair< pair<ll,ll> , pair<ll,ll> > >());
	sort(p2,p2+n,greater< pair<ll,ll> >());
	ll k=0;
	for(i=0;i<q;i++){
		pair< pair<ll,ll> , pair<ll,ll> > p = p1[i];
		ll w = p.first.first;
		ll index = p.first.second;
		ll a = p.second.first;
		ll b = p.second.second;
		while(p2[k].first>w&&k<n){
			update(p2[k].second,1,n);
			k++;
		}
		res[index]=sum(b)-sum(a-1);
	}
	for(i=0;i<q;i++)
	debug1(res[i]);
}
