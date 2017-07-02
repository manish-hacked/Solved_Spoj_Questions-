#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
string a,b;
ll dp[6101][6101];
 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin.ignore();
		cin>>a;
		ll l =a.length();
		b=a;
		ll i,j;
		reverse(b.begin(),b.end());
		for(i=0;i<l;i++){
			if(a[i]==b[0]){
				break;
			}
			dp[i][0]=0;
		}
		for(;i<l;i++)
		dp[i][0]=1;
		for(i=0;i<l;i++){
			if(b[i]==a[0]){
				break;
			}
			dp[0][i]=0;
		}
		for(;i<l;i++)
		dp[0][i]=1;
		for(i=1;i<l;i++){
			for(j=1;j<l;j++){
				if(a[i]==b[j]){
					dp[i][j]=dp[i-1][j-1]+1;
				}else{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		cout<<(l-dp[l-1][l-1])<<endl;
	}
}
 
