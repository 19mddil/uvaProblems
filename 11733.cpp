#include<bits/stdc++.h>
using namespace std;

struct edge{
	int x;
	int y;
	int w;
	edge(int a,int b,int c){
		x = a;
		y = b;
		w = c;
	}
	bool operator < (const edge& p) const{
		return  this->w < p.w;
	}
};

int numOfVertices;
int numOfEdges;
int airportCost;
vector<edge>edges;
map<int,int>par;
vector<int>costs;

void clear(){
	edges.clear();
	par.clear();
	costs.clear();
}

void makeSet(int x){
	par[x] =x;
}

int Find(int x){
	if(par[x] == x){
		return x;
	}
	par[x] = Find(par[x]);
	return par[x];
}

void Union(int a,int b){
	int x = Find(a);
	int y = Find(b);
	if(x != y){
		par[y] = x;
	}
}

int main(){
	int tt;
	cin>>tt;
	int cnt = 0;
	while(tt--){
		cin>>numOfVertices>>numOfEdges>>airportCost;
		int ne = numOfEdges;
		while(ne--){
			int x,y,z;
			cin>>x>>y>>z;
			if(z < airportCost){
				edges.push_back(edge(x,y,z));
			}
		}
		
		for(int i = 1;i<=numOfVertices;i++){
			makeSet(i);
		}
		int cunt = 0;
		int s = 0;
		sort(edges.begin(),edges.end());  // it prevents repetation sweet khushkal ....
		for(int j = 0;j<(int)edges.size();j++){
			int u = Find(edges[j].x);
			int v= Find(edges[j].y);
			if(u != v){
				par[u] = v;
				cunt++;
				s += edges[j].w;
				if(cunt == numOfVertices - 1){
					break;
				}
			}
		}
		int air = numOfVertices - cunt;//Number of disjoint sets representatives
		s += air*airportCost;
		printf("Case #%d: %d %d\n", ++cnt, s, air);
		clear();
	}
	
}
