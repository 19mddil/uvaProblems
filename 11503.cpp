
#include<bits/stdc++.h>
using namespace std;

long long int par[100010];
long long int group[100010];

map<string,long long int>nodes;

void makeSet(long long int x){
	par[x] =x;
	group[x] = 1;
}

long long int Find(long long int x){
	if(par[x] == x){
		return x;
	}
	par[x] = Find(par[x]);
	return par[x];
}

long long int Union(long long int a,long long int b){
	int x = Find(a);
	int y = Find(b);
	if(x != y){
		par[y] = x;
		group[x] += group[y];
	}
	return group[x];
}

int main(){
	long long int tt;
	cin>>tt;
	while(tt--){
		for(long long int i = 0;i<100010;i++){
			par[i] = 0;
			group[i] = 0;
		}
		nodes.clear();
		long long int edge;
		cin>>edge;
		long long int a = 1;
		while(edge--){
			string s1,s2;
			cin>>s1;
			cin>>s2;
			if(nodes.find(s1) == nodes.end()){
				makeSet(a);
				nodes[s1] = a;
				a++;
			}
			if(nodes.find(s2) == nodes.end()){
				makeSet(a);
				nodes[s2] = a;
				a++;
			}
			cout<<Union(nodes[s1],nodes[s2])<<endl;	
		}
	}
}
