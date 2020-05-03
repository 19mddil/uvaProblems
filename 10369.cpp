#include<bits/stdc++.h>
using namespace std;

/*Satelites can communicate with each other but satelites should exits at least between two of them.Last Code? Is she pregnent? I don't know.

*/

struct edge{
	pair<int,int>x;
	pair<int,int>y;
	double cost;
	edge(pair<int,int>x1,pair<int,int>y1,double cost){
		x = x1;
		y = y1;
		this->cost = cost;
	}
	bool operator < (const edge& p) const{
		return  this->cost < p.cost  ;
	}
};

double dist(double x1,double y1,double x2,double y2){
	return  sqrt( powf( fabs(x1 - x2) , 2) + powf( fabs(y1 - y2) , 2) );
}

vector<edge>edges;
vector<pair<int,int> >vertices;
map< pair<int,int> ,pair<int,int> >par;
int cnt;

void clear(){
	edges.clear();
	par.clear();
	vertices.clear();
}

pair<int,int> Find(pair<int,int>x){
	if(par[x] == x) return x;
	return par[x] = Find(par[x]);
}

inline double mst(int &n,int &s)
{
    sort(edges.begin(), edges.end());
    int count = 0;
    double D = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        pair<int,int> u  = Find(edges[i].x);
        pair<int,int> v = Find(edges[i].y);
        if (u != v) {
			D = max(D,edges[i].cost);
            par[u] = v;
            count++;
        }
        if( (n - count) == s ){
			return D;
		}
    }
}

int main(){
	int tt;
	cin>>tt;
	while(tt--){
		int numOfVertices;
		int s;
		cin>>s>>numOfVertices;
		int temp = numOfVertices;
		while(temp--){
			int u,v;
			cin>>u>>v;
			vertices.push_back( pair<int,int>(u,v) );
		}
		for(int i = 0;i< (int)vertices.size();i++){
			for(int j = i;j<(int)vertices.size();j++){
				if(j == i) continue;
				pair<int,int> xx = pair<int,int>(vertices[i].first,vertices[i].second);
				pair<int,int> yy = pair<int,int>(vertices[j].first,vertices[j].second);
				edges.push_back( edge( xx,yy,dist(vertices[i].first,vertices[i].second,vertices[j].first,vertices[j].second)));
				par[xx] = xx;
				par[yy] = yy;
			}
		}
		printf("%.2lf\n",mst(numOfVertices,s)); 
		clear();
	}
}
