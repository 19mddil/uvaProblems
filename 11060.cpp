#include<bits/stdc++.h>
using namespace std;

int nodes,edges;
vector<string>vertices;
map<string,int>indegree;
map<string,vector<string> >adj;
priority_queue< pair<int,string> >pq;
vector<string>topoSort;
map<string,int>xx;
int cnt = 0;

void clear(){
	vertices.clear();
	indegree.clear();
	adj.clear();
	pq = priority_queue< pair<int,string> >();
	topoSort.clear();
}

int main(){
	bool p = true;
	while(cin>>nodes){
		vertices.resize(nodes+1);
		string x,y;
		int nums = 0;
		for(int i = 1;i<=nodes;i++){
			cin>>x;
			vertices[i] = x; 
			xx[x] = nums++;
		}
		cin>>edges;
		for(int i = 0;i<edges;i++){
			cin>>x>>y;
			adj[x].push_back(y);
			indegree[y]++;
		}
		for(int i = 1;i<=nodes;i++){
			if(!indegree.count(vertices[i])){
				pq.push( pair<int,string>(-1*xx[vertices[i]],vertices[i]) );
			}
		}
		int z = nodes;
		while(nodes--){
			string y = pq.top().second;
			pq.pop();
			topoSort.push_back(y);
			if(!adj.count(y)) continue;
			for(string j:adj[y]){
				indegree[j]--;
				if(indegree[j] == 0) { pq.push(pair<int,string>(-1*xx[j],j));}
			}
		}
		cout<<"Case #"<< ++cnt <<": Dilbert should drink beverages in this order: ";
		for(auto i:topoSort){
			z--;
			cout<<i;
			if(z != 0)
			cout<<' ';
		}
		cout<<"."<<endl;
		if(p) cout<<endl;
		p = true;
		clear();
	}
}
