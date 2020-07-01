#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<climits>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inf INT_MAX/2
using namespace std;

int i,j,k;


int G[101][101];
set<int>vertices;


int main(){
	//Fin;
	//Fout;
	FasterIO;
	string s;
	int a,b;
	stringstream ss;
	double cost;
	int cnt;
	int cc = 0;
	while(getline(cin,s)){
		if(s == "0 0"){
			break;
		}
		cost = 0.0;
		cnt = 0;
		for(i = 1;i<=100;i++){
			for(j = 1;j<=100;j++){
				G[i][j] = inf;
			}
		}
		ss<<s;
		while(ss>>a>>b){
			if(a == 0 && b == 0){
				break;
			}
			G[a][b] = 1;
			vertices.insert(a);
			vertices.insert(b);
		}
		for(auto k:vertices){
			for(auto i:vertices){
				for(auto j:vertices){
					if(i != j && G[i][j] > G[i][k] + G[k][j]){
						G[i][j] = G[i][k] + G[k][j];
					} 
				}
			}
		}
		for(auto i:vertices){
			for(auto j:vertices){
				if(G[i][j] != inf){
					cost += G[i][j];
					cnt++;
				}
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n",++cc,cost/cnt);
		ss.clear();
		vertices.clear();
	}
}
