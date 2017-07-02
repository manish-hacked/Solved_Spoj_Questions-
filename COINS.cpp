#include<bits/stdc++.h>
using namespace std;
 
long long int no[100000000];
 
 
long long int p(long long int n){
	if(n<100000000)
	return no[n];
	else
	return max(n,p(n/2)+p(n/3)+p(n/4));
}
 
int main(){
	no[0]=0;
no[1]=1;
no[2]=2;
no[3]=3;
no[4]=4;
no[5]=5;
for(long long int i=6;i<100000000;i++)
no[i]=max(i,no[i/2]+no[i/3]+no[i/4]);
	int h = 10;
	while(h--){
		
		long int x;
		cin>>x;
		cout<<p(x)<<endl;
	}
}
