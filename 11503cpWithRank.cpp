#include<bits/stdc++.h>
using namespace std;

vector<int> parent, rnk;
map<string,int>nodes;
map<int,int>group;

void makeSet(int v) {
    parent[v] = v;
    rnk[v] = 0;
    group[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

int union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        group[a] += group[b];
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
    return group[a];
}

int main(){
	int tt;
	cin>>tt;
	int n = 100000;
	while(tt--){
		parent.resize(n);
		rnk.resize(n);
		int edge;
		cin>>edge;
		int a = 1;
		while(edge--){
			string s1,s2;
			cin>>s1;
			cin>>s2;
			if(nodes.find(s1) == nodes.end()){
				nodes[s1] = a;
				makeSet(a);
				a++;
			}
			if(nodes.find(s2) == nodes.end()){
				nodes[s2] = a;
				makeSet(a);
				a++;
			}
			if(find_set(nodes[s1]) != find_set(nodes[s2])){
				cout<<union_sets(nodes[s1],nodes[s2])<<endl;
			}else{
				cout<<group[find_set(nodes[s1])]<<endl;
			}
		}
		parent.clear();
		rnk.clear();
		nodes.clear();
		group.clear();
	}
}
