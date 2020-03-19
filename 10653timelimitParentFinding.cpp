#include<bits/stdc++.h>
using namespace std;

//I need a an array of pairs
int fx[]={1,-1,0,0}; 
int fy[]={0,0,1,-1};
map< pair<int,int>, pair<int,int> > parent;
int visited[1000][1000];
int G[1000][1000];
int m,n;

int BFS(int x,int y, int x1,int y1)  // calling bfs also saves the vertices in visited map
{
    //queue< int >q;
	queue< pair<int,int> > q;
    q.push(pair<int,int>(x,y));
    visited[x][y] = 0;
    parent[pair<int,int>(x,y)] = pair<int,int>(-1,-1);
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        int xaxis = top.first;
        int yaxis = top.second;
        for(int k=0;k<4;k++)
		{
			int tx = xaxis + fx[k];
			int ty = yaxis + fy[k];
			
			if( tx >= 0 && tx < m && ty >= 0 && ty < n && G[tx][ty] != 1 && visited[tx][ty] == 0){
				 parent[pair<int,int>(tx,ty)] = top;
				 visited[tx][ty] = visited[top.first][top.second] + 1;
				 q.push(pair<int,int>(tx,ty));
				 if(x1 == tx && y1 == ty){
					 return visited[tx][ty];
				 }
			}
		}
		q.pop();
        
    }
    return -1;
}

int main(){
	while(cin>>m>>n && m !=0 && n != 0){
		int l;
		memset(G,0,sizeof(G));
		memset(visited,0,sizeof(visited));
		cin>>l;
		while(l--){
			int r,b;
			cin>>r>>b;
			while(b--){
				int c;
				cin>>c;
				G[r][c] = 1;
			}
		}
		
		int sx,sy;
		int dx,dy;
		cin>>sx>>sy>>dx>>dy;
		
		cout<<BFS(sx,sy,dx,dy)<<endl;
		
		parent.clear();
		
	}
}
