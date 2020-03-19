#include<bits/stdc++.h>
using namespace std;
/*
 * needs optimization and finding path is also important
 */


int visited[9][9];
int lebel[9][9]; // no tension of time limit... 
int fx[]= {1, -1, 1, -1, 2, 2, -2, -2};
int fy[]= {2, 2, -2, -2, 1, -1, 1, -1};

int sr,sc,dr,dc;


int BFS(int x,int y, int x1,int y1)  // calling bfs also saves the vertices in visited map
{
	queue< pair<int,int> > q;
    q.push(pair<int,int>(x,y));
    while(!q.empty())
    {
        pair<int,int> top = q.front();
        int xaxis = top.first;
        int yaxis = top.second;
        visited[xaxis][yaxis] = 1;
        for(int k=0;k<8;k++)
		{
			int tx = xaxis + fx[k];
			int ty = yaxis + fy[k];
			
			
			if( tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && visited[tx][ty] == 0){
				 visited[xaxis][yaxis] = 1;
				 lebel[tx][ty] = lebel[top.first][top.second] + 1;
				 q.push(pair<int,int>(tx,ty));
				 if(x1 == tx && y1 == ty){
					 return lebel[tx][ty];
				 }
			}
		}
		q.pop();
    }
    return 0;
}


int main(){
	string source,destination;
	while(cin>>source>>destination){
		memset(visited,0,sizeof visited);
		memset(lebel,0,sizeof lebel);
		sr = source[1] - '0';
		sc = source[0] - 96;
		dr = destination[1] - '0';
		dc = destination[0] - 96;
		printf("To get from %s to %s takes %d knight moves.\n",source.c_str(),destination.c_str(),BFS(sr,sc,dr,dc));
	}
}
