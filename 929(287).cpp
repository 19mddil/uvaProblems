#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);
#define infinity INT_MAX
using namespace std;

vector< vector<int> > G;
vector< vector<int> > dist;
int visited[1001][1001]; // for a map visited code got time limit


int r,c;
int fx[] = {-1,0,+1,0};
int fy[] = {0,-1,0,+1};
int sx = 0,sy = 0;
int tt;
int i,j;
using pii = pair<int,pair<int,int> >;

void clear(){
	G.clear();
	dist.clear();
}


void dijkstra(){
	priority_queue< pii, vector<pii>, greater<pii> >pq;
	dist[sx][sy] = G[sx][sy];
	pq.push({dist[sx][sy],{sx,sy}});
	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();
		int cx = p.second.first;
		int cy = p.second.second;
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
	//Fin;
	//Fout;
	FasterIO;
	cin>>tt;
	while(tt--){
		cin>>r;
		cin>>c;
		G.resize(r);
		dist.resize(r);
		for(i = 0;i<r;i++){
			dist[i].resize(c,infinity);
			G[i].resize(c);
		}
		short x;
		for(i =0;i<r;i++){
			for(j = 0;j<c;j++){
				cin>>x;
				G[i][j] = x;
				visited[i][j] = false;
				//cout<<"here"<<endl;
			}
		}
		dijkstra();
		cout<< dist[r-1][c-1] <<endl;
		clear();
	}
	return 0;
}

