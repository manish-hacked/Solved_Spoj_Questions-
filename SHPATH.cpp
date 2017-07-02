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
//typedef pair<ll,ll> pair;
map<string,ll> m;
vector< pair<ll,ll> > v[10001];
bool visited[10001];
ll dist[10001];
char s[20];
void Dijkastra(ll s,ll d){
	dist[s]=0;
	priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > q;
	q.push(mp(0,s));
	while(!q.empty()){
		pair<ll,ll> p = q.top();q.pop();
		ll a = p.first;
		ll b = p.second;
		if(b==d)
		return;
		if(visited[b])
		continue;
		else
		visited[b]=true;
		//vector< pair >::iterator itr;
		foreach(i,v[b]){
			ll c = (*i).first;
			ll d = (*i).second;
			if(dist[d]>dist[b]+c){
				dist[d]=dist[b]+c;
				q.push(mp(dist[d],d));	
			}
		}
	}
	//debug();
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
   	ll t;sl(t);
   	while(t--){
   		
   		ll n;sl(n);
		ll i,j;
		forall(i,0,n){
			ss(s);ll p;
			m[s]=i+1;
			sl(p);while(p--){
				ll a,b;sl(a);sl(b);
				v[i+1].pb(mp(b,a));
			}
		}
		ll k;sl(k);
			while(k--){
				fill(visited,false);
				forall(j,0,n+1)
				dist[j]=10000000;
				ss(s);//cout<<a;
				ll sr = m[s];ss(s);ll d = m[s];
				dist[sr]=0;
				priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > q;
				q.push(mp(0,sr));
				while(!q.empty()){
					pair<ll,ll> p = q.top();q.pop();
					ll a = p.first;
					ll b = p.second;
					if(b==d)
					break;
					if(visited[b])
					continue;
					else
					visited[b]=true;
					//vector< pair >::iterator itr;
					foreach(i,v[b]){
						ll c = (*i).first;
						ll d = (*i).second;
						if(dist[d]>dist[b]+c){
							dist[d]=dist[b]+c;
							q.push(mp(dist[d],d));	
						}
					}
				}
				debug1(dist[d]);
			}	
		forall(i,1,n+1)v[i].clear();
		m.clear();
   	}
}
//End 
