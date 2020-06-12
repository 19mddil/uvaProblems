#include<bits/stdc++.h>
using namespace std;

string s;
map<string,int>indegree;
map<string,vector<string> > G;
vector<string>vertices;
priority_queue< pair<int,string> >pq;
map<string,int>duration;
map<string,int>result;

void clear(){
	indegree.clear();
	G.clear();
	vertices.clear();
}

int main(){
	int T;
	cin>>T;
	cin.ignore();
	cin.ignore();
	bool p = false;
	
	while(T--){
		if(p) cout<<endl;
		p = true;
		string x;
		for(char a = 'A';a <= 'Z';a++){
			x = a;
			indegree[x] = 0;
			result[x] = 0;
		}
		while(true){
			getline(cin,s);
			if(s == "") break;
			stringstream ss;
			ss<<s;
			string s;
			int x;
			string b;
			while(ss>>s>>x){
				vertices.push_back(s);
				duration[s] = x;
				string j;
				if(ss>>b){
					for(auto i:b){
						j = i;
						G[j].push_back(s);
						indegree[s] = indegree[s] + 1;
					}
				}
			}
		}
		for(auto i:vertices){
			if(indegree[i] == 0){
				result[i] = duration[i];
				pq.push(pair<int,string>(0,i));
			}
		}
		
		int z = vertices.size();
		while(z--){
			string y = pq.top().second;
			pq.pop();
			for(string i:G[y]){
				indegree[i] = indegree[i] - 1;
				if(indegree[i] == 0){
					pq.push(pair<int,string>(0,i));
				}
				int z = duration[i] + result[y];
				if(result[i] <= z){
					result[i] = z;
				}
			}
		}
		vector<int>xx;
		for(auto i:vertices){
			xx.push_back(result[i]);
		}
		cout<< *max_element(xx.begin(),xx.end()) <<endl;
		clear();
	}
}
