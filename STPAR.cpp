#include<bits/stdc++.h>
using namespace std;
 
int main(){
	
	int n;
	cin>>n;
	while(n){
		int arr[n];
		int i,j;
		for(i=0;i<n;i++)
		cin>>arr[i];
		stack<int> s;
		int p=1,flag=0;
		for(i=0;i<n;i++){
			if(arr[i]==p)
			p++;
			else if(!s.empty()){
				if(s.top()==p){
					s.pop();
					p++;
					i--;
				}else if(s.top()>arr[i]){
					s.push(arr[i]);
				}else{
					flag=1;
					break;
				}
			}else{
				s.push(arr[i]);
			}
		}
		while(!s.empty()){
			//cout<<p<<endl;
			//cout<<p<<endl;
			if(p==s.top()){
				p++;
				s.pop();
			}else{
				break;
			}
		}
		if(s.empty()&&!flag){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
		cin>>n;
	}
	return 0;
} 
