#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,vector<int> > adj;
stack<int>topoVertices;
int cnt = 0;

void clear(){
	cnt = 0;
	adj.clear();
}

void dfs(int x){
	visited[x] = true;
	for(auto i:adj[x]){
		if(visited[i] == false){
			dfs(i);
		}
	}
	visited[x] = true;
	topoVertices.push(x);
}

int main(){
	int nodes,edges;
	while(cin>>nodes>>edges){
		if(nodes == 0){
			break;
		}
		for(int i = 1;i<=nodes;i++){
			visited[i] = false;
		}
		while(edges--){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		for(int i=1;i<=nodes;i++){
			if(visited[i] == false){
				dfs(i);
			}
		}
		while(!topoVertices.empty()){
			int i = topoVertices.top();
			topoVertices.pop();
			cout<<i;
			if(!topoVertices.empty())
			cout<<' ';
		}
		cout<<endl;
		clear();
	}
}
