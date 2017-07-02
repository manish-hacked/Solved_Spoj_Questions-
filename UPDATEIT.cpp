#include<stdio.h>
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,u;
		scanf("%d%d",&n,&u);
		int a[n],t[n+1];
		int i;
		for(i=0;i<=n;i++)
		t[i]=0;
		int l,r,p;
		while(u--){
			scanf("%d%d%d",&l,&r,&p);
			t[l]+=p;
			t[r+1]-=p;
		}
		int count=0;
		for(i=0;i<n;i++){
			count+=t[i];
			a[i]=count;
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int d;
			scanf("%d",&d);
			printf("%d\n",a[d]);
		}
	}
} 
