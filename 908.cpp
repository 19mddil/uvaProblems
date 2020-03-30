#include<bits/stdc++.h>
using namespace std;

struct node{
	int u;
	int key;
	node(int u,int key){
		this->u = u;
		this->key = key;
	}
	bool operator < (const node& p) const{
		return  this->key > p.key  ;
	}
};
 

map<int,vector<int>> G;
map<pair<int,int>,int> edgeCost;
set<int> vertices;
map<int,int>key;
map<int,int>selected;

void clear(){
	G.clear();
	edgeCost.clear();
	vertices.clear();
	key.clear();
	selected.clear();
}

void mst(int source){
	priority_queue<node> q;
	q.push(node(source,0));
	key[source] = 0;
	for(auto i:vertices){
		if(i != source){
			key[i] = INT_MAX;
		}
	}
	while(!q.empty()){
		node top = q.top();
		q.pop();
		for(auto i :G[top.u]){
			if(!selected.count(i)){
				if(key[i] > edgeCost[{top.u,i}]){
					q.push(node(i,edgeCost[{top.u,i}]));
					key[i] = edgeCost[{top.u,i}];
				}
			}
		}
		selected[top.u] = 1;
	}
}



int main(){
	int v,e;
	int count = 0;
	int t = 0;
	while(cin>>v){
		int cst = 0;
		count++;
		v = v-1;
		while(v--){
			int a,b,c;
			cin>>a>>b>>c;
			cst = cst + c;
		}
		if(t!=0) cout<<endl;
		int m;
		cin>>m;
		while(m--){
			int x,y,c;
			cin>>x>>y>>c;
			G[x].push_back(y);
			G[y].push_back(x);
			edgeCost[pair<int,int>(x,y)] = c;
			edgeCost[pair<int,int>(y,x)] = c;
			vertices.insert(x);
			vertices.insert(y);
		}
		cin>>e;
		while(e--){
			int x,y;
			int c;
			cin>>x>>y>>c;
			G[x].push_back(y);
			G[y].push_back(x);
			edgeCost[pair<int,int>(x,y)] = c;
			edgeCost[pair<int,int>(y,x)] = c;
			vertices.insert(x);
			vertices.insert(y);
		}
		for(auto i: vertices){
			mst(i);
			break;
		}
		int sum = 0;
		for(auto i:vertices){
			sum += key[i];
		}
		
		cout<<cst<<endl<<sum<<endl;
		clear();
		t++;
	}
}
