#include<bits/stdc++.h>
using namespace std;
 
int n,m;
struct Point{
	int x;
	int y;
};
 
struct qNode{
	Point p;
	int dist;	
};
bool isValid(int row, int col)
{
    return (row >= 0) && (row < n) &&
           (col >= 0) && (col < m);
}
int a[]={-1, 0, 0, 1};
int b[]={0, -1, 1, 0};
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		string s[n];
		for(int i=0;i<n;i++)
		cin>>s[i];
		int i,j,mat[n][m];
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		mat[i][j]=s[i][j]-'0';
		int fin[n][m];
		bool visited[n][m];
		memset(visited,false,sizeof visited);
		queue<qNode> q;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		if(mat[i][j]){
			fin[i][j]=0;
			q.push({{i,j},0});
			visited[i][j]=true;
		}
		while(!q.empty()){
			qNode cur = q.front();
			Point p = cur.p;
			q.pop();
			for(int i=0;i<4;i++){
				int r = p.x+a[i];
				int c = p.y+b[i];
				if(isValid(r,c)&&!visited[r][c]){
					visited[r][c]=true;
					qNode temp = {{r,c},cur.dist+1};
					fin[r][c]=cur.dist+1;
					q.push(temp);
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
			cout<<fin[i][j]<<" ";
			cout<<endl;	
		}
	}
} 
