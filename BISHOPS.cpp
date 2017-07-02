#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
string s;
ll l;
void fun(){
	ll i,j;
	ll carry=0;
	for(i=(l-1);i>=0;i--){
		ll a = s[i]-'0';
		ll b = (a+a+carry);
		carry = b/10;
		b=b%10;
		s[i]=b+'0';
	}
	string p;
	if(carry){
		while(carry){
			l++;
			ll a = carry%10;
			char c = (a+'0');
			p = p+c;
			carry/=10;
		}
	}
	s=p+s;
}
void funn(){
	ll i,j;
	ll borrow=0;
	ll a = s[l-1]-'0';
	if(a>=2){
		a-=2;
		s[l-1]=a+'0';
	}else{
		ll a = s[l-1]-'0';
		a=(10+a)-2;
		s[l-1]=a+'0';
		ll p = l-2;
		while(s[p]=='0'){
			s[p]='9';
			p--;
		}
		if(p==0&&s[p]=='1'){
			s = s.substr(1);
		}else{
			ll k = s[p]-'0';
			k--;
			s[p]=k+'0';
		}
	}
}
int main(){
	while(getline(cin,s)){
		if(s=="1"){
			cout<<s<<endl;
			continue;
		}
		l = s.length();
		fun();
		funn();
		cout<<s<<endl;
	}
} 
