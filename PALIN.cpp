#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a;
		b=a;
		int inc,dec;
		inc = a.size()/2;
		dec = inc;
		if(a.size()%2==0){
			dec--;
		}
		for(int i=inc,j=dec;i<b.size()&&j>=0;i++,j--){
			b[i]=b[j];
		}
		while(b.size()<=a.size()&&b<=a){
			int i=dec,j=inc;
			while(b[i]=='9'&&i>=0&&j<b.size()){
				b[i]=b[j]='0';
				i--;
				j++;
			}
			if(i<0){
				b="1"+b;
				int l = b[b.size()-1]-'0';
                l++;
                b[b.size()-1] = (l+'0');
			}
			else{
				int l = b[i]-'0';
				l++;
				b[i]=b[j]=l+'0';
			}
		}
		cout<<b<<endl;
	}
} 
