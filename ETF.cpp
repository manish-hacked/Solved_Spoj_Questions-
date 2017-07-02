#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
const ll N = 1e6+1;
ll arr[N];
void Seive(){
	fill(arr,0);
	ll i,j;
	for(i=2;i<N;i++){
		if(!arr[i]){
			for(j=2*i;j<N;j+=i){
				if(!arr[j]){
					arr[j]=j;
				}
				arr[j]-=arr[j]/i;
			}	
		}
	}
}
 
int main(){
	/**ios_base::sync_with_stdio(false);
    cin.tie(NULL); **/
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	Seive();
	ll t;sl(t);
	while(t--){
		ll n;sl(n);
		if(n==1){
			debug1(n);
			continue;
		}
		if(!arr[n]){
			debug1(n-1);
		}else{
			debug1(arr[n]);
		}
	}	
}
 
