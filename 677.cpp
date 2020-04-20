#include<bits/stdc++.h>
using namespace std;

bool a[11][11];
bool b[11];
bool t[11];
bool flag; 
int m;
int r;
int w;
int rr = 0;
int x;
int destination;
map<int ,bool>visited;
map<int,set<int> >G;
vector<int>nums;
vector<string>s;

void clear(){
	visited.clear();
	G.clear();
	nums.clear();
	s.clear();
}

inline string itos(int x){
	stringstream ss;
	ss<<x;
	string s1;
	ss>>s1;
	return s1;
}

void dfs(int x){
	if(rr == w  && x == destination){
		string x;
		flag = true;
		for(auto i:nums) x += itos(i);
		s.push_back(x);
		return;
	}
	if(rr < w ){
		for(auto i:G[x]){
			if(visited[i] == false){
				visited[i] = true;
				rr++;
				nums.push_back(i);
				dfs(i);
				visited[i] = false;
				nums.pop_back();
				rr--;
			}
		}
	}
}

int main(){
	bool p = 0;
	while(cin>>m>>w){
		for(int i = 1;i<=m;i++){
			for(int j = 1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j] == 1){
					G[i].insert(j);
					G[j].insert(i);
				}
			}
			visited[i] = false;
		}
		for(int i = 1;i<=m;i++){
			b[i] = a[1][i];
		}
		r = w - 1;
		while(r--){
			for(int j = 1;j<=m;j++){
				bool s = 0;
				for(int i = 1;i<=m;i++){
					s += a[i][j]*b[i];
				}
				t[j] = s;
			}
			for(int i = 1;i<=m;i++){
				b[i] = t[i];
			}
		}
		flag = false;
		for(int i = 1;i<=m;i++){
			if(b[i] == 1){
				destination = i;
				visited[1] = true;
				nums.push_back(1);
				rr = 0;
				dfs(1);
			}
			nums.clear();
		}
		if(p) cout<<endl;
		p = 1;
		if(!flag){
			cout<<"no walk of length "<<w<<endl;
			cin>>x;
			clear();
		}else{
			sort(s.begin(),s.end());
			int commaPutter;
			for(auto i: s){
				cout<<"(";
				char o = ',';
				commaPutter = w;
				for(char c:i){
					cout<<c;
					if(commaPutter--){
						cout<<o;
					}
				}
				cout<<")"<<endl;
			}
			cin>>x;
			clear();
		}
	}
}
