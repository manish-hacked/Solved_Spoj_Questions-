#include<bits/stdc++.h>
using namespace std;
#define sl(n) scanf("%lld",&n)
#define debug1(n) printf("%lld\n",n)
typedef long long int ll;
//#define INPUT
vector<ll> v[2001];
ll visited[2001][2];
bool DFS(ll s){
	ll flag=0,i,j;
	visited[s][1]=1;
	queue<ll> q;
	q.push(s);
	while(!q.empty()){
		ll p = q.front();q.pop();
		if(visited[p][0])
		continue;
		visited[p][0]=1;
		ll k = visited[p][1];
		ll l = v[p].size();
		for(i=0;i<l;i++){
			ll m = visited[v[p][i]][1];
			if(m==-1){
				visited[v[p][i]][1]=k^1;
				q.push(v[p][i]);
			}else if(m^k==0){
				return 1;
			}else{
				q.push(v[p][i]);
			}
		}
	}
	return flag;
}
int main(){
	#ifdef INPUT
       freopen("input.cpp", "r", stdin);
       //freopen("output.cpp", "w", stdout);
   	#endif
	ll t,p;sl(t);
	for(p=1;p<=t;p++){
		ll n,m;
		sl(n);sl(m);
		ll i,j;
		for(i=1;i<=n;i++){
			visited[i][0]=0;
			visited[i][1]=-1;
		}
		while(m--){
			ll a,b;sl(a);sl(b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ll flag=0;
		printf("Scenario #%lld:\n",p);
		for(i=1;i<=n;i++){
			if(!visited[i][0]){
				if(DFS(i)){
					printf("Suspicious bugs found!\n");
					flag=1;
					break;
				}
			}
		}
		if(!flag){
			printf("No suspicious bugs found!\n");
		}
		for(i=1;i<=n;i++)
		v[i].clear();
	}
}
