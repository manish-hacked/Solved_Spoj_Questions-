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
	ll t;sl(t);
	while(t--){
		ll n,p;
		sll(n,p);
		ll arr[n];
		ll i,j;
		for(i=0;i<n;i++)
		sl(arr[i]);
		ll a=0,b=0;
		ll sum=0;
		for(i=0;i<n;i++){
			sum+=arr[i];
			if(sum>p)
			break;
		}
		if(sum<=p){
			printf("%lld %lld\n",sum,i);
			continue;
		}
		sum-=arr[i];
		a=sum;b=i;
		ll start=0,end=i;
		while(1){
			sum-=arr[start];
			start++;
			while(end<n&&sum+arr[end]<=p){
				sum+=arr[end];
				end++;
			}
			if((end-start)==b){
				a=min(a,sum);
			}else if((end-start)>b){
				b=(end-start);
				a=sum;
			}
			if(end>n-1)
			break;
		}
		printf("%lld %lld\n",a,b);
	}
} 
