#include<iostream>
using namespace std;
int main(){
	while(5){
		int n;
		cin>>n;
		if(n==-1)
		return 0;
		int arr[n],i,sum=0,counter=0;
		for(i=0;i<n;i++){
			cin>>arr[i];
			sum=sum+arr[i];
		}
		if(sum%n==0){
			int p = sum/n;
			for(i=0;i<n;i++){
				if(arr[i]>p){
					int x = arr[i]-p;
					counter = counter+x;
				}
			}
			cout<<counter<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
} 
