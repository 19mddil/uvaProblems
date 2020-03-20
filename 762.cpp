#include<bits/stdc++.h>
using namespace std;
/**New line para ola code**/
/*
 *There will be a blank line between two input 
 * There will be a blank line between two output
 * but but but there will be no blank line between output and input
 * 
*/

map< string, int > visited;
map< string,string > parent;
string path = "";

void find_path(string Start ,string End){
		if((Start == End) || (End == "&")){
			path += Start;
		}
		else{
			find_path(Start,parent[End]);
			path += End;
		}
}
int BFS(string s, string d,map< string, vector< string > >G)
{
	queue< string >q;
	q.push(s);
	visited[s] = 0;
	parent[s] = "&";
	while(!q.empty())
	{
		
		string top = q.front();    
		for(int i=0; i<(int)G[top].size(); i++)
		{
		   string n = G[top][i];
			/*
			The map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container. It returns 0 if the element with key K is not present in the container. 
			*/
		   if(!visited.count(n)) 
		   {
			   visited[n] = visited[top] + 1;
			   parent[n] = top;
			   if( n == d){
				   return 1;
			   }
			   q.push(n);
		   }
		}
		q.pop();
	}
	return 0;
}

int main(){
	int edges;
	bool p = false;
	while(cin>>edges){
		map< string,vector< string > >G;
		string x,y;
		while(edges--){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		string s,d;
		cin>>s>>d;
		if(p == true){
			cout<<endl;
		}
		p = true;
		if(BFS(s,d,G)){
			find_path(s,d);
			for(int i = 0; i+3 < (int)path.length();i = i+2){
				cout<< path[i]<<path[i+1]<< ' '<<path[i+2]<<path[i+3]<<endl;
			}
			
		}else{
			cout<<"No route"<<endl;
		}
		visited.clear();
		path = "";
		parent.clear();
		G.clear();
	}
}
