
/**Make it fast using eulers path algorithm current rating 2348**/

#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> > G;
map<pair<int,int>,bool>visited;
vector<int>num;
int c = 0;

void dfs(int x){
	num.push_back(x);
	if(c == 8){
		for(auto i : num){
			cout<<i;
		}
		cout<<endl;
	}
	if(c != 8){
		for(auto i :G[x]){
			if(visited[{x,i}] == false){
				visited[{x,i}] = true;
				visited[{i,x}] = true;
				c++;
				dfs(i);
				visited[{x,i}] = false;
				visited[{i,x}] = false;
				num.pop_back();
				c--;
			}
		}
	}
	
}

int main(){
	
	G[1].push_back(2);
	visited[pair<int,int>(1,2)] = false;
	G[1].push_back(3);
	visited[pair<int,int>(1,3)] = false;
	G[1].push_back(5);
	visited[pair<int,int>(1,5)] = false;
	G[2].push_back(1);
	visited[pair<int,int>(2,1)] = false;
	G[2].push_back(3);
	visited[pair<int,int>(2,3)] = false;
	G[2].push_back(5);
	visited[pair<int,int>(2,5)] = false;
	G[3].push_back(1);
	visited[pair<int,int>(3,1)] = false;
	G[3].push_back(2);
	visited[pair<int,int>(3,2)] = false;
	G[3].push_back(4);
	visited[pair<int,int>(3,4)] = false;
	G[3].push_back(5);
	visited[pair<int,int>(3,5)] = false;
	G[4].push_back(3);
	visited[pair<int,int>(4,3)] = false;
	G[4].push_back(5);
	visited[pair<int,int>(4,5)] = false;
	G[5].push_back(1);
	visited[pair<int,int>(5,1)] = false;
	G[5].push_back(2);
	visited[pair<int,int>(5,2)] = false;
	G[5].push_back(3);
	visited[pair<int,int>(5,3)] = false;
	G[5].push_back(4);
	visited[pair<int,int>(5,4)] = false;
	dfs(1);
}
