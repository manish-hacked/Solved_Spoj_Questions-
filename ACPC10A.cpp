#include<iostream>
using namespace std;
int main(){
	while(2){
		float a,b,c,cd,r,ap,gp,res;
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0)
		return 0;
		cd=b-a;
		r=b/a;
		ap=a+2*cd;
		gp=a*r*r;
		if(ap==c){
			res=a+3*cd;
			cout<<"AP "<<res<<endl;
		}else{
			res = a*r*r*r;
			cout<<"GP "<<res<<endl;
		}
	}
} 
