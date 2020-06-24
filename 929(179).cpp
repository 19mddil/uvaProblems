#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);
#define infinity INT_MAX
#define MAX 1001
using namespace std;

int G[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];


int r,c;
int fx[] = {-1,0,+1,0};
int fy[] = {0,-1,0,+1};
int sx = 0,sy = 0;
int tt;
int i,j;
using pii = pair<int,pair<int,int> >;



void dijkstra(){
	priority_queue< pii, vector<pii>, greater<pii> >pq;
	dist[sx][sy] = G[sx][sy];
	pq.push({dist[sx][sy],{sx,sy}});
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();
		int cx = p.second.first;
		int cy = p.second.second;
		
		//this part made it rank 179
		if( (cx == r-1 && cy == c-1) || (r ==1 && c == 1) ){
			return ;
		}
		
		visited[cx][cy] = true;
		int tcx,tcy;
		for(i = 0;i<4;i++){
			tcx = cx + fx[i];
			tcy = cy + fy[i];
			if(tcx >= 0 && tcy >= 0 && tcx < r && tcy <c && !visited[tcx][tcy]){
					if(dist[tcx][tcy] > G[tcx][tcy]+dist[cx][cy]){
						dist[tcx][tcy] = G[tcx][tcy]+dist[cx][cy];
						pq.push({dist[tcx][tcy],{tcx,tcy}});
					}	
			
			}
		}
	}
}

int main(){
	FasterIO;
	cin>>tt;
	while(tt--){
		cin>>r;
		cin>>c;
		short x;
		for(i =0;i<r;i++){
			for(j = 0;j<c;j++){
				cin>>x;
				G[i][j] = x;
				visited[i][j] = false;
				dist[i][j] = infinity;
			}
		}
		dijkstra();
		cout<< dist[r-1][c-1] <<endl;
	}
	return 0;
}
