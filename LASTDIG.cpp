#include<iostream>
using namespace std;
int last(long int base,long int pow,int r){
	int res=1;
	while(pow!=0){
		if(pow%2==1)
		res = (res*base)%10;
		pow = pow>>1;
		base = (base*base)%10;
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long int a,b;
		cin>>a>>b;
		int res = last(a,b,10);
		cout<<res<<endl;
	}
	return 0;
} 
