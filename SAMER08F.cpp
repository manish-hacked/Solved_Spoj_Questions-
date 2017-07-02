#include<iostream>
using namespace std;
int main(){
	int x;
	while(2){
		int x;
		cin>>x;
		if(x==0)
		break;
		else{
			int sum=0;
		while(x>0){
			sum = sum + x*x;
			x--;
		}
		cout<<sum<<endl;
		}
	}
} 
