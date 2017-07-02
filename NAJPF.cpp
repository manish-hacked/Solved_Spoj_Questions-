#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char par[1000001],tar[1000001];
		scanf("%s%s",par,tar);
		ll n = strlen(par);
		ll m = strlen(tar);
		ll *lp = (ll*)malloc(sizeof(ll)*m);
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
				v.push_back(i-m+1);
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
			v.push_back(i-m+1);
		}
		if(count){
			printf("%d\n",count);
			for(i=0;i<v.size();i++)
			printf("%d ",v[i]);
			printf("\n");
		}else{
			printf("Not Found\n");
		}
	}
} 
