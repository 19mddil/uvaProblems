#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)

using namespace std;


using pii = pair<int,pair<string,bool> >; /**<language<word,visited> >**/
using px = pair< pair<int,char>, int >; /**< < total len,last letter>,language >**/




int dijkstra(vector< vector< pii > > &G,int source_lan,int des_lan){
	priority_queue<px> pq;
	pq.push(make_pair(make_pair(0,'#'),source_lan));

	while(!pq.empty()){
		px p = pq.top();
		pq.pop();
		int curr_val = p.first.first;
		char cc = p.first.second;
		int u = p.second;

		if(u == des_lan) return -curr_val;

		for(int i = 0;i< (int)G[u].size();i++){
			char uv_char = G[u][i].second.first[0];
			int uv_cost = G[u][i].second.first.size();
			int v = G[u][i].first;

			if( !G[u][i].second.second and uv_char != cc){
				int x = -curr_val + uv_cost;
				pq.push(make_pair(make_pair(-x,uv_char),v));
				G[u][i].second.second = true;
			}
		}
	}
	return -1;
}

int main(){
	//Fin;
	//Fout;
	int n;
	while(cin>>n,n){
		//cin.ignore();
		string source,destination;
		vector< vector< pii> >G;
		map<string,int>mp;

		cin>>source>>destination;

		int _n = n;
		int graph_index = 0;
		string x,y,w;

		while(_n--){
			cin>>x>>y>>w;

			if(mp.find(x) == mp.end()){
				mp[x] = graph_index;
				graph_index++;
				G.push_back( vector< pii >());
			}

			if(mp.find(y) == mp.end()){
				mp[y] = graph_index;
				graph_index++;
				G.push_back(vector< pii >());
			}
			G[mp[x]].push_back(make_pair(mp[y],make_pair(w,false)));
			G[mp[y]].push_back(make_pair(mp[x],make_pair(w,false)));
		}
		if(mp.find(source) == mp.end() or mp.find(destination) == mp.end()){
			cout<<"impossivel"<<endl;
		}else{
			int cost; 
			cost =  dijkstra(G,mp[source],mp[destination]);
			if(cost < 0){
				cout << "impossivel" << endl;
			}else{
				cout<<cost<<endl;
			}
		
		}
	}

}
