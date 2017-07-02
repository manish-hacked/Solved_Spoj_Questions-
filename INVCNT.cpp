#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int i;
 
long long int sum(long long int BIT[],long long int index){
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index=index&(index-1);
	}
	return sum;
}
 
void update(long long int BIT[],long long int index,int value,long long int n){
	while(index<=n){
		BIT[index]+=value;
		index=index+(index&(-index));
	}
}
 
long long int getCount(long long int arr[],long long int n){
	long long int max=arr[0],count=0;
	for(i=0;i<n;i++)
	if(arr[i]>max)
	max=arr[i];
	long long int BIT[max+1];
	for(i=1;i<(max+1);i++){
		BIT[i]=0;
	}
	for(i=(n-1);i>=0;i--){
		count+=sum(BIT,arr[i]-1);
		update(BIT,arr[i],1,max+1);
	}
	return count;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n;
		scanf("%lld",&n);
		long long int *arr = (long long int *)malloc(sizeof(long long int)*n);
		for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
		printf("%lld\n",getCount(arr,n));
	}
} 
