#include<iostream>
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(y==(x-2)||y==x){
			if(y%2==0){
				cout<<x+y<<endl;
				continue;
			}else{
				cout<<(x+y-1)<<endl;
				continue;
			}
		}else{
			cout<<"No Number"<<endl;
		}
	}
} 
