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
const ll m = 1e9+7;
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		ll n,i,j;sl(n);ll p[n+1],pre[n+1];
   		forall(i,1,n+1){
   			sl(p[i]);
   			pre[i] = (p[i]*(p[i]-1))/2;
   			pre[i] = pre[i]%m;
   		}
   		ll dp[n+1][n+1];
   		dp[0][0]=1;
   		forall(i,1,n+1){
   			dp[0][i]=0;
   			dp[i][0]=1;
   		}
   		forall(i,1,n+1){
   			forall(j,1,n+1){
   				if(j>2*i){
   					dp[i][j]=0;
   				}else{
   					dp[i][j] = (dp[i-1][j]+(dp[i-1][j-1]*p[i])%m)%m;
   					if(j>1){
   						dp[i][j] = (dp[i][j]+(dp[i-1][j-2]*pre[i])%m)%m;
   					}
   				}
   			}
   		}
   		debug1(dp[n][n-1]);
   	}
}
 
 
 
 
 
