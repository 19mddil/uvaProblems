#include<bits/stdc++.h>
using namespace std;

map<int,vector<int> >G;
map<int,bool>visited;

void dfs(int y){
    for(auto i:G[y]){
        if(visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
		stringstream ss;
		getline(cin,s);
		ss<<s;
		int n,m,l;
		ss>>n>>m>>l;
		for(int i=1;i<=n;i++){
			visited[i] = false;
		}
		ss.clear();
		int a,b;
		while(m--){
			getline(cin,s);
			ss<<s;
			ss>>a>>b;
			G[a].push_back(b);
			ss.clear();
		}
		int x;
		while(l--){
			cin>>x;
			visited[x] = true;
			dfs(x);
			cin.ignore();
		}
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(visited[i] == true){
				cnt++;
			}
		}
		cout<< cnt  <<endl;
		G.clear();
	}
}
