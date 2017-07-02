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
   	ll n,m,i,j;
   	sl(n);
   	while(n){
   		ll a[n];forall(i,0,n)sl(a[i]);
   		sl(m);ll b[m];forall(j,0,m)sl(b[j]);
   		i=0;j=0;
   		ll as[n],bs[m];as[0]=a[0];bs[0]=b[0];
   		forall(i,1,n)as[i]=a[i]+as[i-1];
   		forall(j,1,m)bs[j]=b[j]+bs[j-1];
   		i=0;j=0;
   		ll ans = 0,q=0,w=0;
   		while(i<n&&j<m){
   			if(a[i]<=b[j]){
   				if(binary_search(a,a+n,b[j])){
   					ll p = lower_bound(a,a+n,b[j])-a;
   					if(ans==0){
   						ans+=max(as[p],bs[j]);
   						
   					}else{
   						ans+=max(as[p]-as[q],bs[j]-bs[w]);	
   					}
   					q=p;w=j;
   					//debug1(ans);
   					i=q+1;j=w+1;
   				}else{
   					j++;
   				}
   			}else{
   				if(binary_search(b,b+m,a[i])){
   					ll p = lower_bound(b,b+m,a[i])-b;
   					if(ans==0){
   						ans+=max(as[i],bs[p]);
   						//q=i;w=j;
   					}else{
   						ans+=max(as[i]-as[q],bs[p]-bs[w]);	
   					}
   					q=i;w=p;
   					//debug1(ans);
   					i=q+1;j=w+1;
   				}else{
   					i++;
   				}
   			}
   		}
   		if(ans)
   		ans+=max(as[n-1]-as[q],bs[m-1]-bs[w]);
   		else
   		ans=max(as[n-1],bs[m-1]);
   		debug1(ans);
   		sl(n);
   	}
}
