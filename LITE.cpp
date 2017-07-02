#include<stdio.h>
#include<malloc.h>
#include<math.h>	
 
long long int *arr,*tree,n,p,*lazy,i,C;
long long int queryRange(long long int node,long long int start,long long int end,long long int l,long long int r){
	if(start>end||r<start||l>end){
		return 0;
	}
	if(lazy[node]!=0){
		if(lazy[node]%2!=0)
		tree[node]=(end - start + 1)-tree[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l&&end<=r){
		return tree[node];
	}
	long long int mid=(start+end)/2;
	return queryRange(2*node,start,mid,l,r)+queryRange(2*node+1,mid+1,end,l,r);
}
void updateRange(long long int node,long long int start,long long int end,long long int l,long long int r,long long int value){
	if(lazy[node]!=0){
		if(lazy[node]%2!=0)
		tree[node]=(end - start + 1)-tree[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end||l>end||r<start)
	return;
	if(start>=l&&end<=r){
		tree[node]=(end-start+1)-tree[node];
		if(start!=end){
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
		return;
	}
	long long int mid=(start+end)/2;
	updateRange(2*node,start,mid,l,r,value);
	updateRange(2*node+1,mid+1,end,l,r,value);
	tree[node]=tree[2*node]+tree[2*node+1];
}
 
int main(){
		scanf("%lld",&n);
		p=(ceil)((log(n)/log(2))+1);
		p=1<<p;
		tree=(long long int*)malloc(sizeof(long long int)*p);
		lazy=(long long int*)malloc(sizeof(long long int)*p);
		for(i=0;i<p;i++){
			lazy[i]=0;
			tree[i]=0;
		}
		scanf("%lld",&C);
		while(C--){
			int x;
			scanf("%d",&x);
			if(!x){
				long long int l,r;
				scanf("%lld%lld",&l,&r);
				l--;r--;
				updateRange(1,0,n-1,l,r,1);
			}else{
				long long int l,r;
				scanf("%lld%lld",&l,&r);
				l--;r--;
				printf("%lld\n",queryRange(1,0,n-1,l,r));
			}	
		}
	return 0;
} 
