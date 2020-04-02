#include<bits/stdc++.h>
using namespace std;

long long int par[100010];
long long int rnk[100010];

map<string,long long int>nodes;
map<long long int,long long int> group;

void makeSet(long long int x){
	par[x] =x;
	rnk[x] = 0;
	group[x] = 1;
}
long long int Find(long long int x){
	if(par[x] == x){
		return x;
	}
	par[x] = Find(par[x]);
	return par[x];
}
bool sameSet(long long int x,long long int y){
	return Find(x) == Find(y);
}
long long int  link(long long int x,long long int y){
	if( !sameSet(x,y)){
		if(rnk[x] > rnk[y]){
			par[y] = x;
			return ++group[x];
		}
		else{
			par[x] = y;
			if(rnk[x] == rnk[y]){
				rnk[y] = rnk[y] + 1;
			}
			return ++group[y];
		}
	}
	return group[Find(x)];
}
long long int Union(long long int a,long long int b){
	return link(Find(a),Find(b));
}

int main(){
	long long int tt;
	scanf("%lld",&tt);
	while(tt--){
		for(long long int i = 0;i<100010;i++){
			par[i] = 0;
			rnk[i] = 0;
		}
		nodes.clear();
		group.clear();
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
