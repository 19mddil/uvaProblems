/*883 rank*/
#include<bits/stdc++.h>
using namespace std;

struct node{
	string u;
	int key;
	node(string u,int key){
		this->u = u;
		this->key = key;
	}
	bool operator < (const node& p) const{
		return  this->key < p.key  ;
	}
};
 
map<string,string> parent;
map<string,vector<string>> G;
map<pair<string,string>,int> edgeCost;
set<string> vertices;
map<string,int>key;
map<string,int>selected;
vector<int>costs;

void clear(){
	parent.clear();
	G.clear();
	edgeCost.clear();
	vertices.clear();
	key.clear();
	selected.clear();
	costs.clear();
}

void mst(string source){
	priority_queue<node> q;
	q.push(node(source,INT_MAX));
	key[source] = INT_MAX;
	parent[source] = "&";
	for(auto i:vertices){
		if(i != source){
			key[i] = 0;
		}
	}
	while(!q.empty()){
		node top = q.top();
		q.pop();
		for(auto i :G[top.u]){
			if(!selected.count(i)){
				if(key[i] < edgeCost[{top.u,i}]){
					q.push(node(i,edgeCost[{top.u,i}]));
					parent[i] = top.u;
					key[i] = edgeCost[{top.u,i}];
				}
			}
		}
		selected[top.u] = 1;
	}
}

void find_path(string Start ,string End){
		if((Start == End) || (End == "&")){
			return;
		}
		else{
			find_path(Start,parent[End]);
			costs.push_back(key[End]);
		}
}

int main(){
	int v,e;
	int count = 0;
	while((cin>>v>>e)&& v!= 0 && e!= 0){
		count++;
		while(e--){
			string x,y;
			int c;
			cin>>x>>y>>c;
			G[x].push_back(y);
			G[y].push_back(x);
			edgeCost[pair<string,string>(x,y)] = c;
			edgeCost[pair<string,string>(y,x)] = c;
			vertices.insert(x);
			vertices.insert(y);
		}
		string source,destination;
		cin>>source>>destination;
		mst(source);
		find_path(source,destination);
		cout<<"Scenario #"<<count<<endl;
		cout<<*min_element(costs.begin(), costs.end())<<" tons"<<endl<<endl;
		clear();
	}
}

/*
	cout<<endl<<endl;
	for(auto i:vertices){
		for(auto j: G[i]){
			cout<<"("<<i<<'-'<<j<<") : "<<edgeCost[{i,j}]<<endl;
		}
	}

	cout<<endl<<endl;
	for(auto i:vertices){
		cout<<i<<" : ";
		for(auto j: G[i]){
			cout<<j<<' ';
		}
		cout<<endl;
	}
*/
/*
	for(auto i = key.begin();i != key.end();i++){
		cout<<(i->first)<<' '<<(i->second)<<' '<<parent[i->first]<<endl;
	}
*/
