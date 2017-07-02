#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(i=0;i<n;i++)
typedef long long int ll;
#include<algorithm>
ll poww(ll n){
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return (poww(n/2)*poww(n/2))%1000000009;
	}else{
		return (2*poww(n/2)*poww(n/2))%1000000009;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,k,i,sum=0,maxx,start,end,countt=0;
		scanf("%lld",&n);
		ll *arr = (ll*)malloc(sizeof(ll)*n);
		loop(i,n){
			scanf("%lld",&arr[i]);
		}
		std::sort(arr,arr+n);
		i=n-1;
		countt=0;
		while(arr[i]>=0&&i>=0){
			if(arr[i]==0)
			countt++;
			sum+=arr[i];
			i--;
		}
		start=1;
		if(i==(n-1)){
			sum=arr[i];
			i--;
		}else{
			if(sum==0){
				countt=(poww(countt)-1+1000000009)%1000000009;
			}else{
				countt=poww(countt);
			}
			printf("%lld %lld\n",sum,countt);
			continue;
		}
		while(arr[i]==sum&&i>=0){
			start++;
			i--;
		}
		printf("%lld %lld\n",sum,start);
	}
} 
