#include<bits/stdc++.h>
using namespace std;
int main(){
	double a;
	while(scanf("%lf",&a)&&a!=0){
		double x=0.50;
		double i;
		double scale = 0.01;
		for(i=1;x<a;i++){
			x=x+(1/(i+2));
		}
		cout<<i<<" card(s)"<<endl;
	}
} 
