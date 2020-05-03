#include<bits/stdc++.h>

using namespace std;
map< int, int > visited;
map<int ,string> color;

void BFS(int s, map< int, vector< int > >G)
{
    queue< int >q;
    q.push(s);
    visited[s] = 0;
    color[s] = "r";
    while(!q.empty())
    {
        string x;
        int top = q.front();    
        if(color[top] == "r"){
		x = "b";
	}
	else{
		x = "r";
	}	
        for(int i=0; i<(int)G[top].size(); i++)
        {
           int n = G[top][i];
           if(!visited.count(n)) // checks whether n is the valid key or not
           {
               visited[n] = visited[top] + 1;
               color[n] = x;
               q.push(n);
           }
        }
        q.pop();
    }
}

int main()
{
	int totVertice;
    	int edges;
    	while( (scanf("%d",&totVertice) == 1) && totVertice != 0 && (scanf("%d",&edges)== 1))
    	{
		map< int,vector< int > >G;
		int source; // for this problem code source = 0
		for(int i=0; i<edges; i++)
		{
		    int x, y;
		    scanf("%d %d", &x, &y);
		    if(i == 0){
					source = x;
				}
		    G[x].push_back(y);
		    G[y].push_back(x);
		}
		BFS(source,G);
		string t1;
		int flag = 0;
		map< int ,int >:: iterator i;
		for(i = visited.begin();i != visited.end();i++){
			//cout<< color[i->first]<< " : ";
			t1 = color[i->first];
			for( int j = 0; j<(int)G[i->first].size() ; j++){
				if(t1 == color[G[i->first][j]] ){
					flag = 1;
				}
				//cout<< color[G[i->first][j]] <<' ';

			}
			//cout<<endl;
		}
		
		G.clear();
		visited.clear();
		color.clear();

		if(flag){
			cout<<"NOT BICOLORABLE."<<endl;
		}else{
			cout<<"BICOLORABLE."<<endl;
		}
    }
    return 0;
}
