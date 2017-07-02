#include<iostream>
using namespace std;
#include<math.h>
int main(){
    int t;
    cin>>t;
    while(t--){
        long int m,n=0,i,c;
        cin>>m;
        i=5;
        while((m/i)!=0){
        	n=n+m/i;
        	i=5*i;
        }
        cout<<n<<endl;
        
    }
    return 0;
} 
