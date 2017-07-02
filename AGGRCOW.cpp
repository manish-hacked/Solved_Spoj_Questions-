#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
ll n,c;
ll *pos;
 
bool check(ll p){
	ll countt=1;
	ll temp=pos[0];
	ll i,j;
	for(i=1;i<n;i++){
		if(pos[i]-temp>=p){
			countt++;
			temp=pos[i];
		}
		if(countt==c)
		return 1;
	}
	return 0;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		pos=(ll*)malloc(sizeof(ll)*n);
		ll i,j;
		for(i=0;i<n;i++)
		cin>>pos[i];
		sort(pos,pos+n);
		ll start=0;
		ll end = pos[n-1]-pos[0];
		while(end-start>1){
			ll mid = (start+end)/2;
			if(check(mid)){
				start=mid;
			}else{
				end=mid;
			}
		}	
		cout<<start<<endl;	
	}
	
} 
