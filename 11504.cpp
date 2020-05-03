#include<bits/stdc++.h>
using namespace std;
/*
 * This does not work while sorting why?!
struct node{
	int x;
	int f;
	node(int a,int b){
		x = a;
		f = b;
	}
	bool operator < (const node& p) const{
		return this->f > p.f;
	}
	
};
*/


map<int,bool>visited;
map<int,vector<int> > adj;
stack<int>topoVertices;
//int t = 0;
int cnt = 0;

inline void clear(){
	cnt = 0;
	adj.clear();
	//t = 0;
}

inline void dfs(int x){
	visited[x] = true;
	//t += 1;
	for(auto i:adj[x]){
		if(visited[i] == false){
			dfs(i);
		}
	}
	visited[x] = true;
	//t += 1;
	topoVertices.push(x);
}

inline void dfs1(int x){
	visited[x] = true;
	for(auto i:adj[x]){
		if(visited[i] == false){
			dfs(i);
		}
	}
	visited[x] = true;
}


int main(){
	int tt;
	cin>>tt;
	int nodes,edges;
	while(tt--){
		cin>>nodes>>edges;
		for(int i = 1;i<=nodes;i++){
			visited[i] = false;
		}
		while(edges--){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y); /**This is the break through I was hoping for**/
		}
		
		for(int i=1;i<=nodes;i++){
			if(visited[i] == false){
				dfs(i);
			}
		}
		/*sort(topoVertices.begin(),topoVertices.end());*/
		
		for(int i = 1;i<=nodes;i++){
			visited[i] = false;
		}
		/*
		for(auto j : topoVertices){
			int i = j.x;
			if(visited[i] == false){
				cnt++;
				dfs1(i);
			}
		}
		*/
		while(!topoVertices.empty()){
			int i = topoVertices.top();
			topoVertices.pop();
			if(visited[i] == false){
				cnt++;
				dfs(i);
			}
		}
		cout<<cnt<<endl;
		clear();
	}
}
