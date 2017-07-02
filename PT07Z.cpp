#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define N 10001
vector<ll> v[N];
bool visited[N];
ll maxx=0;
ll n;
 
ll DFS(ll s){
	visited[s]=true;
	vector<ll>::iterator itr;
	vector<ll> temp;
	for(itr=v[s].begin();itr!=v[s].end();itr++){
		temp.push_back(DFS(*itr));
	}
	ll p =-1;
	sort(temp.begin(),temp.end());
	if(!temp.empty()){
		ll l = temp.size();
		p = temp[l-1];
		if(l>1){
			maxx=max(maxx,temp[l-1]+temp[l-2]+2);
		}
	}
	return p+1;	
}
 
int main(){
	cin>>n;
	ll m = n-1;
	while(m--){
		ll a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	ll i;
	ll ans=0;
	for(i=1;i<=n;i++)
	visited[false];
	for(i=1;i<=n;i++)
	if(!visited[i])
	ans=max(ans,DFS(i));
	maxx = max(ans,maxx);
	cout<<maxx<<endl;
} 
