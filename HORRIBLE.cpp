#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pr;
#define bitcount                    __builtin_popcount
#define gcd                         __gcd 
#define p(n) printf("%d\n",n)
#define sc(n) scanf("%c",&n)
#define pc(n) printf("%c\n",n)
#define sl(n) scanf("%lld",&n)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define debug() printf("hello\n")
#define debug1(n) printf("%lld\n",n)
#define debug2(a,b) printf("%lld %lld\n",a,b)
#define debug3(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define sf(n) scanf("%lf",&n)
#define pf(n) printf("%lf\n",n)
#define ss(n) scanf("%s",n)
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a) a.begin(), a.end()
#define pb push_back
#define in(a,b) ( (b).find(a) != (b).end())
#define fill(a,v) memset(a, v, sizeof a)
#define sz(a) ((int)(a.size()))
#define mp  make_pair
#define f first
#define s second
#define checkbit(n,b) ( (n >> b) & 1)
#define index(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
//#define INPUT
ll *arr,*tree,n,p,*lazy;
void buildTree(ll node,ll start,ll end){
	if(start==end){
		tree[node]=arr[start];
		return;
	}
	ll mid = (start+end)/2;
	buildTree(2*node,start,mid);
	buildTree(2*node+1,mid+1,end);
	tree[node]=tree[2*node]+tree[2*node+1];
}
ll queryRange(ll node,ll start,ll end,ll l,ll r){
	if(start>end||r<start||l>end){
		return 0;
	}
	if(lazy[node]!=0){
		tree[node]+=(end - start + 1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l&&end<=r){
		return tree[node];
	}
	ll mid=(start+end)/2;
	return queryRange(2*node,start,mid,l,r)+queryRange(2*node+1,mid+1,end,l,r);
}
void updateRange(ll node,ll start,ll end,ll l,ll r,ll value){
	if(lazy[node]!=0){
		tree[node]+=(end - start + 1)*lazy[node];
		if(start!=end){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end||l>end||r<start)
	return;
	if(start>=l&&end<=r){
		tree[node]+=(end-start+1)*value;
		if(start!=end){
			lazy[2*node]+=value;
			lazy[2*node+1]+=value;
		}
		return;
	}
	ll mid=(start+end)/2;
	updateRange(2*node,start,mid,l,r,value);
	updateRange(2*node+1,mid+1,end,l,r,value);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int main(){
	//cout<<b<<endl;
	/**ios_base::sync_with_stdio(false);
    cin.tie(NULL); **/
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		ll n,m,i,j;sll(n,m);
   		arr=(ll*)malloc(sizeof(ll)*n);
		p=(ceil)((log(n)/log(2))+1);
		p=1<<p;
		tree=(ll*)malloc(sizeof(ll)*p);
		lazy=(ll*)malloc(sizeof(ll)*p);
		forall(i,0,n)arr[i]=0;
		forall(i,0,p)lazy[i]=0;
		buildTree(1,0,n-1);
		while(m--){
			ll k;sl(k);
			if(k){
				ll a,b;sll(a,b);a--;b--;
				debug1(queryRange(1,0,n-1,a,b));
			}else{
				ll a,b,c;sll(a,b);sl(c);a--;b--;
				updateRange(1,0,n-1,a,b,c);
			}
		}
   	}
}
 
 
 
 
 
//End 
