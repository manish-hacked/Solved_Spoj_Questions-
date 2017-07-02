#include<iostream>
using namespace std;
#include<math.h>
int main(){
    int t;
    cin>>t;
    while(t--){
        long int n,m;
        cin>>m>>n;
        long int i,j;
        for(i=m;i<=n;i++){
                int flag=1;
            for(j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    flag=0;
                    break;
                }
            }
        if(flag&&i!=1)
            cout<<i<<endl;
        }
    }
    return 0;
} 
