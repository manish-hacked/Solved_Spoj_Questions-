#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	//scanf("%d",&t);
	ll m;
	while(scanf("%lld",&m)!=-1){
		char *tar = (char*)malloc(sizeof(char)*(m+1));
		scanf("%s",tar);
		ll *lp = (ll*)malloc(sizeof(ll)*m);
		string par;
		cin>>par;
		ll n = par.length();
		ll len=0,i=0;
		while(i<m){
			if(i==0){
				lp[i]=0;
				i++;
			}else{
				if(tar[i]==tar[len]){
					len++;
					lp[i]=len;
					i++;
				}else{
					if(len>0){
						len = lp[len-1];
					}else{
						lp[i]=0;
						i++;
					}
				}
			}
		}
		i=0;ll j=0,count=0;
		vector<ll> v;
		while(i<n){
			if(j==m){
				v.push_back(i-m);
				j=lp[j-1];
				count++;
			}
			if(par[i]==tar[j]){
				i++;
				j++;
			}else{
				if(j>0){
					j=lp[j-1];
					
				}else{
					i++;
				}
			}
		}
		if(j==m){
			count++;
			v.push_back(i-m);
		}
		if(count){
			for(i=0;i<v.size();i++)
			cout<<v[i]<<endl;
			printf("\n");
		}else{
			printf("\n");
		}
		cin>>m;
	}
} 
