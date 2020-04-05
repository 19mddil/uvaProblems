#include<bits/stdc++.h>
using namespace std;

long long int par[5005];
long long int group[5005];

map<string,long long int>nodes;
priority_queue<long long int> q;


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
	if( !q.empty() && (group[y] > q.top())){
		q.pop();
		q.push(group[y]);
		return;
	} 
	q.push(group[y]);
}

int main(){
	long long int v,e;
	while(cin>>v>>e){
		if(v == 0 && e == 0){
			return 0;
		}
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
		if(q.empty()){
			cout<<1<<endl;
			continue;
		}
		cout<<q.top()<<endl; // when priority queue will be empty it wont show anything so generating an exception
		q = priority_queue<long long int>();
	}
	return 0;
}
