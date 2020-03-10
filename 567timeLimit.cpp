#include<bits/stdc++.h>

using namespace std;
int c =  0;

map< int, int > visited;
map<int ,int> parent;

void BFS(int s,int d, map< int, vector< int > >G)  // calling bfs also saves the vertices in visited map
{
    queue< int >q;
    q.push(s);
    visited[s] = 0;
    parent[s] = -1;
    while(!q.empty())
    {
        int top = q.front();
        for(int i=0; i<(int)G[top].size(); i++)
        {
           int n = G[top][i];
           if(!visited.count(n)) // checks whether n is the valid key or not
           {
               parent[n] = top;
               visited[n] = visited[top] + 1;
               q.push(n);
               
               if(n == d){
				   return;
			   }
			   
           }
        }
        q.pop();
    }
}
void find_path(int start ,int end){
        if((start == end) || (end == -1)){
            //cout<<start<<' ';
            return;
        }
        else{
            find_path(start,parent[end]);
            c++;
            //cout<<end<<' ';
        }
    }


int main(){
	int u = 1;
	while(true){
		map< int, vector< int > >G;
		for(int i = 1;i<20;i++){
			int j;
			scanf("%d",&j);
			for(int k = 0;k<j;k++){
				int m;
				scanf("%d",&m);
				G[i].push_back(m);
				G[m].push_back(i);
			}
		}
		
		//BFS(1,2,G);
		
		
		map<int,int>::iterator it;
		
		for(it = visited.begin();it != visited.end();it++){
			cout<<it->first<<" : ";
			for(int i = 0;i<(int)G[it->first].size();i++){
				cout<<G[it->first][i]<<' ';
			}
			cout<<endl;
		}
		
		
		int m;
		scanf("%d",&m);
		cout<<"Test Set #"<<u<<endl;
		while(m--){
			c = 0;
			int x,y;
			scanf("%d %d",&x,&y);
			BFS(x,y,G);
			if(x == y){
				c=1;
				goto a;
			}
			find_path(x,y);
			
			a:printf("%2d to %2d: %d\n", x, y, c);
			visited.clear();
			parent.clear();
		}
		visited.clear();
		parent.clear();
		u++;
		cout<<endl;
	}
	
}
