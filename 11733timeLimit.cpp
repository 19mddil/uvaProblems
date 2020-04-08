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
map<int,int>rep;
map<int,int>repV;
set<int>repSet;
vector<int>costs;

void clear(){
	edges.clear();
	par.clear();
	rep.clear();
	repSet = set<int>();
	costs.clear();
	repV.clear();
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
		int tv = numOfVertices;
		int te = numOfEdges;
		for(int i = 1;i<=tv;i++){
			makeSet(i);
			repV[i] = 0;
		}
		while(te--){
			int x,y,z;
			cin>>x>>y>>z;
			if(z < airportCost){
				edges.push_back(edge(x,y,z));
				Union(x,y);
			}else{
				par[x] = x;
				par[y] = y;
			}
		}
		for(int i = 1;i<=tv;i++){
			rep[i] = Find(i);
			//cout<<"rep["<<i<<"] = "<<rep[i]<<endl;
			repSet.insert(rep[i]);
			repV[rep[i]]++;
		}
		/*
		for(auto i:repSet){
			cout<<"repV["<<i<<"] = "<<repV[i]<<endl;
		}
		*/
		int s;
		int cunt;
		
		for(auto i:repSet){
			for(int k = 1;k<= tv;k++){
				par[k] = k;
			}
			cunt = 0;
			s = 0;
			sort(edges.begin(),edges.end()); // it prevents repetation sweet khushkal ....
			for(int j = 0;j<(int)edges.size();j++){
				if( rep[ edges[j].x ] == i && rep[ edges[j].y ] == i ){
					int u = Find(edges[j].x);
					int v= Find(edges[j].y);
					if(u != v){
						par[u] = v;
						cunt++;
						s += edges[j].w;
						if(cunt == repV[rep[i]] - 1){
							break;
						}
					}
				}
			}
			if(cunt == repV[rep[i]] - 1){
				costs.push_back(s);
			}
		}
		/*
		for(auto i:costs){
			cout<<i<<' ';
		}
		cout<<endl;
		*/
		cout<<"Case #"<< ++cnt <<": "<< ( accumulate(costs.begin(),costs.end(),0)+ ((int)repSet.size()*airportCost) ) <<" "<< repSet.size() <<endl;
		clear();
		
	}
}
