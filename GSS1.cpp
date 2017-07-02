#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
typedef long long int ll;
struct seg{
	ll Sum;
	ll pSum;
	ll sSum;
	ll mSum;
};
struct seg *tree;
struct seg maxx(struct seg a,struct seg b){
	struct seg res;
	res.Sum = a.Sum+b.Sum;
	res.pSum = std::max(a.pSum,a.Sum+b.pSum);
	res.sSum = std::max(b.sSum,a.sSum+b.Sum);
	res.mSum = std::max(std::max(a.mSum,b.mSum),a.sSum+b.pSum);
	return res;
}
void build(long long int node,long long int start,long long int end,long long int arr[]){
	if(start==end){
		tree[node].Sum=tree[node].pSum=tree[node].sSum=tree[node].mSum=arr[start];
	}else{
		long long int mid = (start+end)/2;
		build(2*node,start,mid,arr);
		build(2*node+1,mid+1,end,arr);
		tree[node]=maxx(tree[2*node],tree[2*node+1]);
	}
}
struct seg query(long long int node,long long int start,long long int end,long long int l,long long int r,long long int arr[]){
	if(r<start||l>end){
		struct seg temp;
		temp.Sum=temp.pSum=temp.sSum=temp.mSum=-15008;
		return temp;
	}
	if(l<=start&&r>=end){
		return tree[node];
	}
	long long int mid=(start+end)/2;
	return maxx(query(2*node,start,mid,l,r,arr),query(2*node+1,mid+1,end,l,r,arr));
}
int main(){
	long long int n,i;
	scanf("%lld",&n);
	long long int *arr=(long long int*)malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	long long int p = (ceil)((log(n)/log(2))+1);
	p=1<<p;
	tree = (struct seg*)malloc(sizeof(struct seg)*(p));
	build(1,0,n-1,arr);
	ll m;
	scanf("%lld",&m);
	while(m--){
			long long int l,r;
			scanf("%lld%lld",&l,&r);
			--l;--r;
			printf("%lld\n",query(1,0,n-1,l,r,arr).mSum);	
	}
	return 0;
} 
