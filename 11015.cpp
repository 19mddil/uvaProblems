#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inf INT_MAX/2
using namespace std;

int n,m;
int i,_i,j,k;
int mini,s,index;

map<int,string>memberNames;
vector< vector<int> > G;

int main(){
	//Fin;
	//Fout;
	FasterIO;
	int tt = 0;
	while(tt < 105){
		cin>>n>>m;
		if(!n) break;
		for(_i = 1;_i<=n;_i++){
			cin>>memberNames[_i];
		}
		G.resize(n+1,vector<int>());
		for(i = 1;i<=n;i++){
			G[i].resize(n+1);
			for(j = 1;j<=n;j++){
				if(i == j) G[i][j] = 0;
				else G[i][j] = inf;
			}
		}
		for(_i = 1;_i<=m;_i++){
			cin>>i>>j>>k; // scanf use korta parci na kno??
			G[i][j] = G[j][i] = k;
			
		}
		for(k =1;k<=n;k++){
			for(i=1;i<=n;i++){
				for(j = 1; j<=n;j++){
					G[i][j] = min(G[i][j],(G[i][k]+G[k][j]));
				}
			}
		}
		mini = inf+1;
		index = -1;
		for(i=1;i<=n;i++){
			s = 0;
			for(j=1;j<=n;j++){
				s += G[i][j];
			}
			if(mini>s){
				mini = s;
				index = i;
			}
			
		}
		cout<<"Case #"<< ++tt <<" : "<< memberNames[index]<< '\n';
		G.clear();
		memberNames.clear();
	}
}
