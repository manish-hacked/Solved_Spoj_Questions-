#include<stdio.h>
 
/**#include<bits/stdc++.h>
using namespace std;**/
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
#define gcd __gcd
typedef long long int ll;
//#define INPUT
const ll N = 1e6+1;
ll x[N];
ll hola[N];
 
void seive(){
	ll i,j;
	for(i=1;i<N;i++)
	x[i]=i;
	for(i=2;i<N;i++){
		if(x[i]==i){
			for(j=i;j<N;j+=i){
				x[j] -= x[j] / i;
			}
		}
	}
	for(i=1;i<N;i++)
	hola[i]=(i*i)*x[i];
	for(i=2;i<N;i++){
			for(j=2*i;j<N;j+=i){
				hola[j]+=((j*j)*x[j/i])/i;
			}
	}
}
 
 
int main(){
	seive();
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		ll n;
   		sl(n);
   		debug((hola[n]/2)+n);
	}
} 
 
