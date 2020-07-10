#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<climits>
#include<sstream>
#include<algorithm>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define inf INT_MAX/2
using namespace std;

int i,j,k;
int _i;
int charlie;
string s;
int test;
bool p;
int cost;

stringstream ss;
int numOfVertices;

int debugMax;

vector< vector<int> > G;
vector< vector<int> > nxt;
vector<int>taxes;
vector<int>path;


void seeNxt();
void seeTable();
void pathFind();

void findPath(int i,int j);
void setNumofVertices(string s);
void printPath();
void floydWarshell();
void init();
void takeInput();

int main(){
	//Fin;
	//Fout;
	FasterIO;
	int M;
	cin>>M;
	cin.ignore();
	cin.ignore();
	while(M--){
		getline(cin,s);
		numOfVertices = 0;
		setNumofVertices(s);
		//cout<<s<<endl;
		init();
		takeInput();
		//seeTable();
		floydWarshell();
		//seeTable();
		cin.ignore();
		p = false;
		while(getline(cin,s)){
			if(p) cout<<endl;
			p = true;
			debugMax= 0;
			if(s == ""){
				break;
			}
			ss<<s;
			int source,destination;
			ss>>source>>destination;
			findPath(source,destination);
			cout<<"From "<<source<<" to "<<destination<<" :"<<endl;
			printPath();
			cout<<"Total cost : "<< G[source][destination]<<endl;
			path.clear();
			ss.clear();
		}
		G.clear();
		taxes.clear();
		nxt.clear();
	}
}
void seeNxt(){
	for(i = 1;i<=numOfVertices;i++){
		for(j = 1;j<=numOfVertices;j++){
			cout<<nxt[i][j]<<' ';
		}
		cout<<endl;
	}
}
void seeTable(){
	cout<<numOfVertices<<endl;
	for(i = 1;i<=numOfVertices;i++){
		for(j = 1;j<=numOfVertices;j++){
			cout<<G[i][j]<<"\t\t\t";
		}
		cout<<endl;
	}
	cout<<"taxes"<<endl;
	for(i = 1;i<(int) taxes.size();i++){
		cout<<taxes[i]<<' ';
	}
	cout<<endl;
}
void init(){
	G.resize(numOfVertices+1,vector<int>());
	nxt.resize(numOfVertices+1,vector<int>());
	taxes.resize(numOfVertices+1);
	for(i = 1;i<=numOfVertices;i++){
		G[i].resize(numOfVertices+1);
		nxt[i].resize(numOfVertices+1);
		for(j = 1;j<=numOfVertices;j++){
			nxt[i][j] = j;
			G[i][j] = (i==j)?0:inf;
		}
	}
}

void setNumofVertices(string s){
	ss<<s;
	while(ss>>test){
		//cout<<test<<' ';
		numOfVertices++;
	}
	ss.clear();
}

void findPath(int i,int j){
	path.push_back(i);
	while(i!=j){
		if(debugMax == 50){
			return;
		}
		i = nxt[i][j];
		//cout<<i<<' ';
		path.push_back(i);
		debugMax++;
	}
}
void pathFind(int s, int d)
{
    if(s==d)
    {
        printf("%d",s);
        return;
    }
    pathFind(s,nxt[s][d]);
    printf("-->%d",d);
}

void printPath(){
	p = false;
	cout<<"Path: ";
	for(auto i:path){
		if(p) cout<<"-->";
		p = true;
		cout<<i;
	}
	cout<<endl;
}
void floydWarshell(){
	for(k=1;k<=numOfVertices;k++){
		for(i=1;i<=numOfVertices;i++){
			for(j=1;j<=numOfVertices;j++){
				if(G[i][k] == inf && G[k][j] == inf) continue; //if middle node does not lead the way.
				cost = taxes[k];
				if(k == i || k == j) cost = 0; //if middile node is not unique at all.
				if(G[i][j]> (G[i][k]+G[k][j]+cost)){
					G[i][j] = G[i][k]+G[k][j]+cost;
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
}
void takeInput(){
	ss<<s;
	_i = 1;
	while(ss>>test){
		if(test == -1) test = inf;
		G[1][_i] = test;
		_i++;
	}
	ss.clear();
	if(numOfVertices != 1){
		for(i = 2;i<=numOfVertices;i++){
			for(j = 1;j<=numOfVertices;j++){
				cin>>charlie;
				if(charlie == -1){
					charlie = inf;
				}
				G[i][j] = charlie;
			}
		}
	}
	for(i = 1;i<=numOfVertices;i++){
		cin>>taxes[i];
	}
}
