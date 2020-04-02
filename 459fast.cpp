#include<bits/stdc++.h>
using namespace std;

int par[27];
int rnk[27];
int setCount;

map<string,int>nodes;



void makeSet(int x){
	par[x] =x;
	rnk[x] = 0;
}
int Find(int x){
	if(par[x] == x){
		return x;
	}
	par[x] = Find(par[x]);
	return par[x];
}
bool sameSet(int x,int y){
	return Find(x) == Find(y);
}
void link(int x,int y){
	if( !sameSet(x,y)){
		if(rnk[x] > rnk[y]){
			par[y] = x;
		}
		else{
			par[x] = y;
			if(rnk[x] == rnk[y]){
				rnk[y] = rnk[y] + 1;
			}
		}
		setCount--;
	}
}
void Union(int a,int b){
	link(Find(a),Find(b));
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
		setCount = x - 'A' + 1;
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
		}
		set<int> x1;
		if(tx){
			cout<<endl;
		}
		tx = true;
		cout<< setCount <<endl;
	}
}
