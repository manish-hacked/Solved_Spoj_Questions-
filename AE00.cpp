#include<iostream>
using namespace std;
int main(){
	long int a,c=0,i,j;
	cin>>a;
	if(a==1){
		cout<<"1";
		return 0;
	}
	for(i=1;i<=(a/2);i++){
		for(j=i;j*i<=a;j++){
			c++;
		}
	}
	cout<<c<<endl;
} 
