/*945*/

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

map<int,int>par;
vector<edge>edges;
vector<int>costs;
int elt[210];
int eltc;

void clear(){
	par.clear();
	edges.clear();
	costs.clear();
}


int Find(int r){
	if(par[r] == r) return r;
    return par[r] = Find(par[r]);
}

int kruskal(int nv){
	for(int i = 1;i<= nv;i++){
		par[i] = i;
	}
	sort(edges.begin(),edges.end());
	int count = 0,s = 0;eltc = 0;
	for(int i = 0;i<(int)edges.size();i++){
		int u = Find(edges[i].x);
		int v= Find(edges[i].y);
		if(u != v){
			par[u] = v;
			count++;
			s += edges[i].w;
			elt[eltc++] = i;
			if(count == nv - 1){
				break;
			}
		}
		
	}
	if(count != nv - 1){
		return -1;
	}
	return s;
}


int main(){
	int tt;
	cin>>tt;
	int count = 0;
	while(tt--){
		int nv,ne;
		cin>>nv>>ne;
		while(ne--){
			int a,b,c;
			cin>>a>>b>>c;
			edges.push_back(edge(a,b,c));
		}
		int min;
		memset(elt,0,sizeof elt);
		min = kruskal(nv);
		if(min == -1){
			cout<<"Case #"<< ++count<<" : No way"<<endl;
			clear();
			continue;
		}
		int s;
		int cunt;
		for(int i = 0;i<eltc;i++){
			for(int k = 1;k<= nv;k++){
				par[k] = k;
			}
			cunt = 0;
			s = 0;
			for(int j = 0;j<(int)edges.size();j++){
				if(elt[i] != j){
					int u = Find(edges[j].x);
					int v= Find(edges[j].y);
					if(u != v){
						par[u] = v;
						cunt++;
						s += edges[j].w;
						if(cunt == nv - 1){
							break;
						}
					}
				}
			}
			if(cunt == nv -1 ){
				costs.push_back(s);
			}
		}
		if(costs.empty()){
			cout<<"Case #"<< ++count<<" : No second way"<<endl;
			clear();
		}else{
			sort(costs.begin(),costs.end());
			cout<<"Case #"<< ++count<<" : "<<costs[0]<<endl;
			clear();
		}
		
	}
}
