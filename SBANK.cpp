#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
int main(){
	
	ll t;
	sl(t);
	while(t--){
		ll n;sl(n);
		string s[n],a[n],b[n],c[n],d[n],e[n],f[n];
		ll i,j;
		map<string,ll> m1;
		map<string,ll> m2;
		for(i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>f[i];
			s[i]=a[i]+b[i]+c[i]+d[i]+e[i]+f[i];
			if(m1.find(s[i])==m1.end()){
				m1[s[i]]=i;
				m2[s[i]]=1;
			}else{
				ll p = m2[s[i]];
				m2[s[i]]=p+1;
			}
			//cout<<a[i]<<endl;
		}
		map<string,ll>::iterator itr;
		for(itr=m1.begin();itr!=m1.end();itr++){
			string s = (*itr).first;
			ll p = (*itr).second;
			cout<<a[p]<<" "<<b[p]<<" "<<c[p]<<" "<<d[p]<<" "<<e[p]<<" "<<f[p]<<" "<<m2[s]<<endl;
		}
		cout<<endl;
	}
} 
