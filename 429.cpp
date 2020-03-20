#include<bits/stdc++.h>
using namespace std;
map< int,vector<string> > sizedInput;
string s;
string d;
map<string,int> visited;
map<string,int> lebel;

int BFS(string s,string d,vector<string> G){
	/*
	for(int i = 0;i<(int)G.size();i++){
		cout<<G[i]<<' ';
	}
	cout<<endl;
	*/
	queue<string> q;
	q.push(s);
	visited[s] = 1;
	lebel[s] = 0;
	while(!q.empty()){
		string top = q.front();
		//cout<<"we have top as "<<top<<endl;
		for(int i =0;i<(int)top.length();i++){
			string x = top;
			x.erase(x.begin() + i);
			//cout<<x<<" Searching with "<<i<<"th disappearence from "<<top<<endl;
			//cout<<"matching "<<top<<" with :";
			for(int j = 0; j<(int) G.size() ;j++){
				
				string y = G[j];
				y.erase(y.begin() + i);
				//cout<<y<<' ';
				if(x == y){
					
					if(visited[G[j]] == 0){
						lebel[G[j]] = lebel[top] + 1;
						//cout<<"(found match with "<<G[j]<<" and "<<top<<". So lebel["<<G[j]<<"] = "<<lebel[G[j]]<<" ) ";
						if(d == G[j]){
							return lebel[G[j]];
						}
						visited[G[j]] = 1;
						q.push(G[j]);
					}
				}
			}
		}
		q.pop();
	}
	return 0;
}

int main(){
	int tt;
	cin>>tt;
	while(tt--){
		string x;
		while(cin>>x && x != "*"){
			int l = x.length();
			sizedInput[l].push_back(x);
		}
		cin.ignore();
		string sd;
		while(getline(cin,sd) && sd != ""){
			stringstream str(sd);
			str >> s >> d;
			
			cout<<s<<' '<<d<<' '<<BFS(s,d,sizedInput[s.length()])<<endl;
			
			visited.clear();
			lebel.clear();
		}
		sizedInput.clear();
		visited.clear();
		lebel.clear();
		if(tt){
			cout<<endl;
		}
	}
} 
