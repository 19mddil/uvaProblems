#include<bits/stdc++.h>
using namespace std;


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
double rs = 0.0;
double rails = 0.0;
void clear(){
	edges.clear();
	par.clear();
	vertices.clear();
	cnt = 0;
	rs = 0.0;
	rails = 0.0;
}

pair<int,int> Find(pair<int,int>x){
	if(par[x] == x) return x;
	return par[x] = Find(par[x]);
}
void mst(int n,int r)
{
    cnt = 0;
    sort(edges.begin(), edges.end());

    int count = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        pair<int,int> u  = Find(edges[i].x);
        pair<int,int> v = Find(edges[i].y);
        if (u != v) {
            par[u] = v;
            count++;
            if(edges[i].cost >r ){
				rails += edges[i].cost;
				cnt++;
			}else{
				rs += edges[i].cost;
			}
            if (count == n - 1)
                break;
        }
    }
}

int main(){
	int tt;
	cin>>tt;
	int c = 1;
	while(tt--){
		int numOfVertices;
		int r;
		cin>>numOfVertices>>r;
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
				edges.push_back(edge(xx,yy,dist(vertices[i].first,vertices[i].second,vertices[j].first,vertices[j].second)));
				par[xx] = xx;
				par[yy] = yy;
			}
		}
		mst(numOfVertices,r);
		printf("Case #%d: %d %.lf %.lf\n",c++,cnt==0?1:++cnt,rs,rails); 
		clear();
	}
}
