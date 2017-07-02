#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug1(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll m = 1e9+7;
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll n,m;sl(n);sl(m);
	ll arr[n];ll i,j,k;
	for(i=0;i<n;i++)sl(arr[i]);
	ll p=0;
	for(i=0;i<n;i++){
		p+=arr[i];
		if(p>=m)
		break;
	}
	if(p==m){
		cout<<p<<endl;
		return 0;
	}
	p-=arr[i];
	ll ans=0;
	ans=max(ans,p);
	//debug1(ans);
	p+=arr[i];
	ll start=0;
	ll end=i;
	while(1){
		while(1){
			p-=arr[start];
			start++;
			if(p<=m){
				break;
			}
		}
		ans=max(ans,p);
		//debug1(ans);
		while(end!=n){
			end++;
			if(p+arr[end]>m){
				ans=max(ans,p);
				p+=arr[end];
				break;
			}
			p+=arr[end];
		}
		if(end==n)
		break;
	}
	debug1(ans);
}
