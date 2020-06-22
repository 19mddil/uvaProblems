#include<bits/stdc++.h>
#define infinity INT_MAX/2 // here distant maximum should be long maximum because 10^6(num of edges) * 10 ^ 5(highest wieght of edge) > INT_MAX

#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);

using namespace std;

string source;
string destination;
map< string, vector< pair <string, pair<int,string> > > >G;
map<string, int >dist;
map<string,string>par;
set<string>vertices;
map<string,string>snapshot;
map<string,bool>selfLoop;


void clear(){
	G.clear();
	dist.clear();
	par.clear();
	vertices.clear();
	selfLoop.clear();
	snapshot.clear();
}

void dijstkra(){
	if(source == destination){
		par[source] = source;
		dist[source] = 0;
		return;
	}
    priority_queue< pair<int,pair<string,string> >,vector <pair<int,pair<string,string> > >,greater<pair<int,pair<string,string> > > >q; //Do not use struct its slow.
    dist[source] = 0LL;
    q.push({0LL,{source,"#"}});
    snapshot[source] = "#";
	string temp = "@";
	
    while(!q.empty()){
        string u=q.top().second.first;
        string cc = q.top().second.second;
        
        int  d_v = q.top().first;
        q.pop();
		//cout<<"#########Popping:"<<' '<<u<<" which has character : "<<cc<<endl;
        if(u == destination){
			return;
		}
		
        if(selfLoop.count(u)){
			//cout<<"\t*************Strating  self loop check on "<<u<<endl;
			vector<int>distances;
			map<int,string>mp;
			if(u == source){
				//cout<<"\t\t@@@@ "<<u<<" is a source "<<endl; 
				for(auto pp = G[u].begin();pp != G[u].end();pp++ ){ //pair <string, pair<int,string> >
					if(pp->first == u){
						//cout<<"\t\t\tdeleting "<<pp->first<<" : "<<pp->second.second<<endl;
						pp->second.first = infinity;
					}
				}
				
				//cout<<"\t\t\t@@@@ After deleting all the self looping edges "<<endl;
				//cout<<"\t\t\t\t"<<u<<" : "<<endl;
				for(auto pp = G[u].begin();pp != G[u].end();pp++ ){ //pair <string, pair<int,string> >
					//cout<<"\t\t\t\t\tvertex: "<<pp->first<<" cost: "<<pp->second.first<< " associative char:"<< pp->second.second<<endl; 
				}
				//cout<<"\t\t\t$$$$$$$$$$$Priority queue pushing$$$$$$$$$"<<endl;
				//cout<<"\t\t\t\t"<<dist[u]<<' '<<u<<' '<<" associative char: "<<cc<<endl;
				q.push({dist[u],{u,cc}});
				//cout<<"\t\t\t$$$$$$$$$$$Priority queue pushing$$$$$$$$$"<<endl;
				//cout<<"\t\t@@@@ "<<u<<" is a source ends"<<endl;
				snapshot[u] = cc;
				selfLoop.erase(selfLoop.find(u));
			}else{
				bool flag = false;
				//cout<<"\t\t@@@@ "<<u<<" is a not a source "<<endl;
				for(auto pp = G[u].begin();pp != G[u].end();pp++ ){ //pair <string, pair<int,string> >
					//cout<<"\t\t\tConditon: "<<" "<<pp->first <<" == "<<u << " && "<<pp->second.second<<" != "<<cc<<endl;
					if(pp->first == u && pp->second.second != cc ){
						//cout<<"\t\t\t"<<u<<" had a associtaive character :"<<cc<<"which does not match to now self loop cost: "<<pp->second.second<<endl;
						flag = true;
						distances.push_back(pp->second.first + dist[u]);
						mp[pp->second.first + dist[u]] = pp->second.second;
						//G[u].erase(pp);/**Jugantokari abishkar**/
					}
					if(pp->first == u && pp->second.second == cc){
						pp->second.first = infinity;
						pp->second.second = "#";
					}
				}
				if(flag == true){
					//cout<<"here"<<endl;
					dist[u] = *min_element(distances.begin(),distances.end());
					cc = mp[dist[u]];
					par[u] = u;
					snapshot[u] = cc;
					selfLoop.erase(selfLoop.find(u));
					q.push({dist[u],{u,cc}});
				}else{
					selfLoop.erase(selfLoop.find(u));
					snapshot[u] = cc;
					q.push({dist[u],{u,cc}});
				}
				//cout<<"\t\t@@@@ "<<u<<" is a not a source ends "<<endl;
			}
			
			//cout<<"\t*************end self Loop check"<<endl;
			continue;
		}
        /*
        if( u == destination){
			return;
		}
        */
        
        if(d_v != dist[u]){ // Saves some times.
			continue;
		}
        for(auto ep:G[u]){
			string v = ep.first;
			int uv_cost = ep.second.first;
			string uv_char = ep.second.second;
			
			if(uv_char == cc && par[u] != v){
				
				//cout<<endl<<"Characeter Matched"<<endl;
				//cout<<par[u] << " = "<< v <<endl;
				
				dist[u] = infinity;
				for(auto pp = G[par[u]].begin();pp != G[par[u]].end();pp++ ){ //indicates vector of pairs
					//cout<<u<<pp->first<<endl;
					if(u == pp->first && cc == pp->second.second){
						//cout<<pp->second.first <<endl;
						pp->second.first = infinity;
						//cout<<"pusing"<<endl;
						//cout<<dist[par[u]]<<' '<<par[u]<<' '<<snapshot[par[u]]<<endl;
						q.push({dist[par[u]],{par[u],snapshot[par[u]]}});
					}
				}
				
				//cout<<u<<' '<<v<<endl;
				//cout<<"character Matched"<<endl<<endl;
				continue;
			}
			
			//cout<<u<<' '<<v<<' '<<uv_cost<<uv_char<<endl;
			//cout<<dist[u]<<" + "<<uv_cost<<" < "<< dist[v]<<endl;
			
			if(dist[u] + uv_cost < dist[v] ){
				//cout<<"into start"<<endl;
				//cout<<u<<' '<<v<<endl;
				dist[v] = dist[u] + uv_cost;
				par[v] = u;
				//cout<<"par["<<v<<"] = "<<u<<endl;
				snapshot[v] = uv_char;
				q.push({dist[v],{v,uv_char}});
				//cout<<"into end"<<endl;
			}
        }
        //cout<<"################Popping Ends############"<<endl;
    }
}
bool p = false;
void find_path(string s ,string e){
        if( (s == e) || (!par.count(e)) ){
			if(p) cout<<' ';
			p = true;
            cout<<s;
        }
        else{
            find_path(s,par[e]);
            if(p) cout<<' ';
            p = true;
            cout<<e;
        }
}

int main(){
	Fin;
	Fout;
	FasterIO;
	int M;
	while(cin>>M){
		if(M == 0){
			break;
		}
		cin>>source>>destination;
		//cout<<source<<' '<<destination<<endl;
		/*
		if(source == destination){
			cout<<"here"<<endl;
			cout<<"0"<<endl;
			clear();
			continue;
		}
		*/
		string u,v;
		string w;
		int l;
		string f;
		for(int i = 1;i<=M;i++){
			cin>>u>>v>>w;
			l = w.length();
			f = w[0]+'\0';
			if(u != v){
				G[u].push_back({v,{l,f}});
				G[v].push_back({u,{l,f}});
			}
			else{
				G[u].push_back({u,{l,f}});
				selfLoop[u] = true;
			}
			dist[u] = infinity;
			dist[v] = infinity;
			vertices.insert(u);
			vertices.insert(v);
		}
		/*
		for(auto i:vertices){
			cout<<i<< " : ";
			for(auto j:G[i]){
				cout<<j.first<<"["<<j.second.first<<","<<j.second.second<<"]"<<' ';
			}
			cout<<endl;
		}
		*/
		
		dijstkra();
		if(par.count(destination)){
			int x = dist[destination];
			cout<< x <<endl;
			//find_path(source,destination);
		}else{
			cout<<"impossivel"<<endl;
		}
		clear();
	}
}
