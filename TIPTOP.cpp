#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
 
 
 
 
int main(){
	//seive();
	//cout<<l<<endl;
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;cin>>t;ll k;
   	
   	for(k=1;k<=t;k++){
   		ll n;cin>>n;
   		ll p = sqrt(n);
		cout<<"Case "<<k<<": ";
		if(p*p==n)	
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
} 
 
 
