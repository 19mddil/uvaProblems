#include<bits/stdc++.h>
using namespace std;

int par[27];

map<string,int>nodes;

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
	scanf("%d\n\n",&tt);
	bool tx = false;
	while(tt--){

		memset(par,0,sizeof par);
		nodes.clear();

		char x;
		cin>>x;
		cin.ignore();
		for(int i = 'A',j = 1;i<= x && j<= 26;i++,j++){
			char c = (char)i;
			string s = "";
			s += c;
			nodes[s] = j;
		}
		for(auto i:nodes){
			makeSet(i.second);
		}

		string s;
		while(getline(cin,s) && s != ""){
			string x,y;
			x = s[0];
			y = s[1];
			Union(nodes[x],nodes[y]);
			Union(nodes[y],nodes[x]);
		}
		set<int> x1;
		for(auto i:nodes){
			x1.insert(Find(i.second));
		}
		if(tx){
			cout<<endl;
		}
		tx = true;
		cout<<x1.size()<<endl;
	}
}

