#include<bits/stdc++.h>
using namespace std;
 
int main(){
	
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int col=1,row=1,path=0,i,j;
		int flag=0;
		while(path<(n-1)){
			if(flag){
				int p = col;
				for(i=1;i<p;i++){
					row++;
					col--;
					path++;
					if(path==(n-1))
					break;
				}
				if(path<(n-1)){
					row++;
					path++;
				}
				flag=0;
			}else{
				int p=row;
				for(i=1;i<p;i++){
					col++;
					row--;
					path++;
					if(path==(n-1))
					break;
				}
				if(path<(n-1)){
					col++;
					path++;
				}
				flag=1;
			}
		}
		cout<<"TERM "<<n<<" IS "<<row<<"/"<<col<<endl;
	}
	
}
