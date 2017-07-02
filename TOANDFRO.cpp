#include<iostream>
using namespace std;
#include<string.h>
int main(){
	while(5){
		int n;
		cin>>n;
		if(n==0)
		return 0;
		char c[201];
		cin>>c;
		int l = strlen(c);
		int p = l/n;
		int i=0,j,k;
		char a[p][n];
		for(j=0;j<p;j++)
		for(k=0;k<n;k++){
			if((j+1)%2==0){
				a[j][n-1-k]= c[i];
				i++;	
			}else{
				a[j][k]= c[i];
				i++;
			}
			
		}
		for(k=0;k<n;k++)
		for(j=0;j<p;j++)
		cout<<a[j][k];
		cout<<endl;
	}
} 
