#include<bits/stdc++.h>
using namespace std;
int main(){
	string c;
	long long dp[5001];
	while(true){
		cin>>c;
		if(c[0]=='0')
		break;
		int l = c.length();
		dp[0]=dp[1]=1;
		for(int i=2;i<=l;i++){
			dp[i]=0;
			char c1=c[i-2]-'0';
			char c2=c[i-1]-'0';
			if(c1==1||(c1==2&&c2<7))
			dp[i]=dp[i]+dp[i-2];
			if(c2!=0)
			dp[i]=dp[i]+dp[i-1];
		}
		cout<<dp[l]<<endl;
	}
} 
