#include<stdio.h>
typedef long long int ll;
 
int main(){
	ll n;
	scanf("%lld",&n);
	ll ans=0;
	ll p,i;
	for(i=0;i<n;i++){
		scanf("%lld",&p);
		ans=ans^p;
	}
	printf("%lld\n",ans);
}
