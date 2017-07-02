#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
const ll N =1e4+1;
ll arr[N];
 
void seive(){
	ll i,j;
	for(i=1;i<N;i++)
	arr[i]=i;
	for(i=2;i<N;i++){
		if(arr[i]==i){
			for(j=i;j<N;j+=i)
			{
				arr[j]/=i;
				arr[j]*=(i-1);
			}
		}
	}
	for(i=2;i<N;i++)
	arr[i]+=arr[i-1];
}
 
 
 
 
int main(){
	seive();
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;cin>>t;
   	//cout<<arr[10000]<<endl;
   	while(t--){
   		ll n;cin>>n;
   		cout<<arr[n]*arr[n]<<endl;	
	}
} 
 
 
 
 
