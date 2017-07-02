#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#define loop(i,n) for(i=0;i<n;i++)
typedef long long int ll;
ll *arr,*tree,p;
void build(ll node,ll start,ll end){
	if(start==end){
		tree[node]=arr[start];
	}else{
		ll mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=std::max(tree[2*node],tree[2*node+1]);
	}
}
 
ll query(ll node,ll start,ll end,ll l,ll r){
	if(r<start||l>end||start>end){
		return 0;
	}else{
		if(l<=start&&r>=end){
			return tree[node];
		}
		int mid = (start+end)/2;
		return std::max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
	}
}
 
int main(){
	ll n,k,i,sum=0,maxx,start,end;
	scanf("%lld",&n);
	arr = (ll*)malloc(sizeof(ll)*n);
	loop(i,n){
		scanf("%lld",&arr[i]);
	}
	scanf("%lld",&k);
	p=(ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree=(ll*)malloc(sizeof(ll)*p);
	build(1,0,n-1);
	for(i=0;i<=(n-k);i++){
		printf("%lld ",query(1,0,n-1,i,i+k-1));
	}
	printf("\n");
} 
