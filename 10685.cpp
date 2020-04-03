#include<bits/stdc++.h>
using namespace std;

long long int par[5005];
long long int group[5005];

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

void Union(long long int a,long long int b){
	int x = Find(a);
	int y = Find(b);
	if(x != y){
		par[x] = y;
		group[y] += group[x];
	}
}

int main(){
	long long int v,e;
	while(cin>>v>>e){
		if(v == 0 && e == 0){
			return 0;
		}
		int tmp = v;
		nodes.clear();
		long long int a = 1;
		while(v--){
			string s1;
			cin>>s1;
			if(nodes.find(s1) == nodes.end()){
				nodes[s1] = a;
				makeSet(a);
				a++;
			}
		}
		while(e--){
			string s1,s2;
			cin>>s1>>s2;
			Union(nodes[s1],nodes[s2]);
		}
		long long int ans = 0;
		for(int i =1;i<=tmp;i++){
			if(ans < group[i]) ans = group[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
	
