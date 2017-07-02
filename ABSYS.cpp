#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
 
ll value(string s){
	ll l = s.length();
	ll ans=0;
	for(ll i=(l-1);i>=0;i--){
		ans+=(s[i]-'0')*pow(10,l-i-1);
	}
	return ans;
}
 
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s,z;
		getline(cin, z);
		getline(cin, s);
		//cout<<s<<endl;
		ll a,b;
		ll p,q,r;
		p=s.find("+");
		q=s.find("=");
		r=s.find("machula");
		if(r<p&&r<q){
			b = atoi(s.substr(p+2,q-p-3).c_str());
			a = atoi(s.substr(q+2).c_str())-b;
		}else if(r>p&&r<q){
			a = atoi(s.substr(0,p-1).c_str());
			b = atoi(s.substr(q+2).c_str())-a;
		}else{
			a = atoi(s.substr(0,p-1).c_str());
			b = atoi(s.substr(p+2,q-p-3).c_str());
		}
		cout<<a<<" + "<<b<<" = "<<a+b<<endl;
	}
	
} 
