#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(i=0;i<n;i++)
 
 
typedef long long int ll;
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i,p;
		ll cur=0,countt=0,max=0,x,min,kp=0;
		scanf("%d",&n);
		ll *arr = (ll*)malloc(sizeof(ll)*n);
		loop(i,n){
			scanf("%d",&p);
			cur = cur+p;
			arr[i]=cur;
		}
		max=arr[0];
		min=arr[0];
		countt=1;
		kp=1;
		for(i=1;i<n;i++){
				if(min<=0){
					x=arr[i]-min;
				}else{
					x=arr[i];
				}
				if(x==max){
					if(min==0){
						countt+=kp;
						countt++;
					}else{
						countt+=kp;
					}
				}else if(x>max){
					countt=0;
					if(min==0){
						countt+=kp;
						countt++;
					}else{
						countt+=kp;
					}
					max=x;
				}else{
					
				}
				if(arr[i]==min){
					kp++;
				}else if(arr[i]<min){
					min=arr[i];
					kp=1;
				}
		}
		printf("%lld %lld\n",max,countt);
	}
} 
