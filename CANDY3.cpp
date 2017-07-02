#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int x=n,sum=0,y;
		while(n--){
			cin>>y;
			y=y%x;
			sum = sum +y;
		}
		sum = sum%x;
		if(sum)
		cout<<"NO"<<endl;
		else
		cout<<"YES"<<endl;
	}
	return 0;
} 
