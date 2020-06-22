#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);

using namespace std;


using pii = pair<int,pair<string,bool> >; /**<language<word,visited> >**/

using px = pair< int,pair<char, int> >; /**< < total <len,last <letter,language > >**/

string source,destination;
vector< vector< pii> >G;
map<string,int>mp;

void clear(){
	G.clear();
	mp.clear();
}



int dijkstra( ){
	int source_lan = mp[source];
	int des_lan = mp[destination];
	priority_queue<px,vector<px>,greater<px> >pq;
	//pq.push(make_pair( 0, make_pair('#',source_lan));
	pq.push({ 0,{'#',source_lan}});

	while(!pq.empty()){
		px p = pq.top();
		pq.pop();
		int curr_val = p.first;
		char cc = p.second.first;
		int u = p.second.second;

		if(u == des_lan) return curr_val;

		for(int i = 0;i< (int)G[u].size();i++){
			char uv_char = G[u][i].second.first[0];
			int uv_cost = G[u][i].second.first.size();
			int v = G[u][i].first;

			if( !G[u][i].second.second and uv_char != cc){
				int x = curr_val + uv_cost;
				//pq.push(make_pair(make_pair(-x,uv_char),v));
				//pq.push(make_pair( -x,make_pair(uv_char,v)));
				pq.push({ x,{uv_char,v}});
				G[u][i].second.second = true;
			}
		}
	}
	return -1;
}

int main(){
	Fin;
	Fout;
	FasterIO;
	int n;
	while(cin>>n,n){
		//cin.ignore();
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
			G[mp[x]].push_back({mp[y],{w,false}});
			G[mp[y]].push_back({mp[x],{w,false}});
		}
		if(mp.find(source) == mp.end() or mp.find(destination) == mp.end()){
			cout<<"impossivel"<<endl;
		}else{
			int cost; 
			cost =  dijkstra( );
			if(cost < 0){
				cout << "impossivel" << endl;
			}else{
				cout<<cost<<endl;
			}
		
		}
		clear();
	}

}
