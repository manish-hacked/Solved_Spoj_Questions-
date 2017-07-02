#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j,k,l1,l2,n;
char a[2001],b[2001];
int min(int a,int b,int c){
	if(a<=b&&a<=c)
	return a;
	else if(b<=a&&b<=c)
	return b;
	else
	return c;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",a,b);
		l1=strlen(a);
		l2=strlen(b);
		if(l1>l2)
		n=l1;
		else
		n=l2;
		int arr[n+1][n+1];
		arr[0][0]=0;
		for(i=1;i<=l1;i++)
		arr[i][0]=i;
		for(j=1;j<=l2;j++)
		arr[0][j]=j;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(((i<(l1+1))&&(j<(l2+1)))&&(a[i-1]==b[j-1])){
					arr[i][j]=arr[i-1][j-1];
				}else{
					if(i>l1){
						arr[i][j]=arr[l1][j];
					}else if(j>l2){
						arr[i][j]=arr[i][l2];
					}else{
						arr[i][j]=min(arr[i-1][j-1],arr[i-1][j],arr[i][j-1])+1;
					}
				}
			}
		}
		printf("%d\n",arr[n][n]);
	}
	return 0;
} 
