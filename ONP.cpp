#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		stack <char> c;
		cin>>a;
		int i=0;
		while(a[i]!='\0'){
			if(a[i]=='('||a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='^'){
				c.push(a[i]);
				i++;
			}else if(a[i]==')'){
				while(c.top()!='('){
					cout<<c.top();
					c.pop();
				}
				c.pop();
				i++;
			}else{
				cout<<a[i];
				i++;
			}
		}
		cout<<endl;
	}
} 
