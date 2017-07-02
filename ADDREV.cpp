#include<iostream>
#include<math.h>
using namespace std;
int reverse(int x){
	int res=0,counter=0,a=x,i,p;
	while(a!=0){
		a=a/10;
		counter++;
	}
	for(i=(counter-1);i>=0;i--){
		p=x%10;
		res=res+p*pow(10,i);
		x=x/10;
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,sum,a1,b1;
		cin>>a>>b;
		a1=reverse(a);
		b1=reverse(b);
		sum=a1+b1;
		cout<<reverse(sum)<<endl;
	}
} 
