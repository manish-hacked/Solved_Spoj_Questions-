#include<iostream>
using namespace std;
int fac(int a[],int n,int x){
	if(n==1){
		return x;
	}
	int i=0,temp=0,p;
	for(i=0;i<x;i++){
		p=a[i]*(n-1)+temp;
		a[i]=p%10;
		temp=p/10;
	}
	while(temp!=0){
		a[i]=temp%10;
		temp=temp/10;
		i++;
	}
	return fac(a,n-1,i);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i=0,a[200];
		cin>>n;
		int p=n;
		while(n!=0){
			a[i]=n%10;
			n=n/10;
			i++;
		}
		int x=fac(a,p,i);
		for(i=(x-1);i>=0;i--)
		cout<<a[i];
		cout<<endl;
	}
} 
