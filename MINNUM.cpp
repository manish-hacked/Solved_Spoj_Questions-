#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define sll(m,n) scanf("%lld%lld",&m,&n)
#define debug(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
 
string no[]={"0","1","2","3","4","5","6","7","8","9"};
 
string add(string s){
	ll l = s.length();
	if(l==0)
	return "1";
	if(s[l-1]<'9'){
		s[l-1]+=1;
	}else{
		ll i=l-1;
		while(s[i]=='9'){
			s[i]='0';
			i--;
		}
		if(i>=0){
			s[i]+=1;
		}else{
			s="1"+s;
		}
	}
	return s;
}
 
string get(string s){
	string ans="";
	ll l  = s.length();
	ll rem=0;
	ll i=0;
	while(i<l){
		ll p = rem*10+(s[i]-'0');
		if(p<9){
			if(i==l-1){
				rem=(s[i]-'0');
				break;			
			}
			if(i>0)
			ans+=no[0];
			p  = rem*100+(s[i]-'0')*10+(s[i+1]-'0');
			rem = p%9;
			ans=ans+no[p/9];
			i+=2;
		}else{
			rem = p%9;
			ans=ans+no[p/9];
			i+=1;	
		}
	}
	if(rem){
		return add(ans);
	}
	return ans;
}
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       freopen("output.cpp", "w", stdout);
   	#endif
   	string s;cin>>s;
   	while(s!="-1"){
   		if(s=="0")
   		cout<<"0"<<endl;
   		else{
   			cout<<get(s)<<endl;	
		}
   		cin>>s;
	}
	
} 
 
 
 
 
 
