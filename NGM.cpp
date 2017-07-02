#include<stdio.h>
 
int main(){
	long long int n;
	scanf("%lld",&n);
	int p;
	bool flag=true;
	if(n<10){
		p=n;
		n=n-p;
	}else if(n<20){
		p = n-10;
		if(p==0)
		flag=!flag;
		n=n-p;
	}else{
		int x = n-20;
		if(x>9){
			p=9;
			n=n-p;
		}else if(x!=0){
			p=x;
			n=n-x;
		}else{
			p=1;
			n=n-1;
		}
		flag=!flag;
	}
	while(n>19){
		int x = n-20;
		if(x>9){
			n=n-9;
		}else if(x!=0){
			n=n-x;
		}else{
			n=n-1;
		}
		flag=!flag;
	}
	if(flag){
		printf("1\n%d\n",p);
	}else{
		printf("2\n");
	}
	
} 
