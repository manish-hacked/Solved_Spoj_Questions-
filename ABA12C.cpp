#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define s(n)  scanf("%d",&n) 
#define p(n) printf("%d\n",n)
#define sc(n) scanf("%c",&n)
#define pc(n) printf("%c\n",n)
#define sl(n) scanf("%lld",&n)
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
#define checkbit(n,b) ( (n >> b) & 1)
#define index(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
//#define INPUT
 
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		ll n,k,i,j,z;sl(n);sl(k);
   		ll p[k+1];forall(i,1,k+1)sl(p[i]);
   		p[0]=0;
   		ll dp[n+1][k+1];
   		forall(i,1,k+1)dp[0][i]=0;
   		forall(i,1,k+1){
   			dp[1][i]=p[i];
   		}
   		forall(i,2,n+1){
   			forall(j,1,k+1){
   				//ll a = dp[i-1][j];
   				ll b = 1e9+7;ll flag=0;
   				forall(z,1,j+1){
   					if(p[j-z]!=-1&&dp[i-1][z]!=-1){
   						flag=1;
   						b = min(b,dp[i-1][z]+p[j-z]);
   					}
   				}
   				if(flag)
   				dp[i][j]=b;
   				else
   				dp[i][j]=-1;
   			}
   		}
   		debug1(dp[n][k]);
   	}
}
