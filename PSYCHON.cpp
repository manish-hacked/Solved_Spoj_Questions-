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
 
int main(){
	/**ios_base::sync_with_stdio(false);
    cin.tie(NULL); **/
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
	while(t--){
		ll n;sl(n);
		ll i,j;ll e=0,o=0;
		for(i=2;i*i<=n;i++){
			if(n%i==0){
				ll cnt=0;
				while(n%i==0){
					n/=i;
					cnt++;
				}
				if(cnt%2==0)
				e++;
				else
				o++;
			}
		}
		if(n>1)
		o++;
		/**if(e>0){
			printf("Psycho Number\n");
		}else{
			printf("Ordinary Number\n");
		}**/
		(e>o)?printf("Psycho Number\n"):printf("Ordinary Number\n");
	}	
}
 
 
 
 
 
 
 
 
 
 
