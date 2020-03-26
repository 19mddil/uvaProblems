#include<bits/stdc++.h>
using namespace std;

double dist(double x1,double y1,double x2,double y2){
	return  sqrt( powf( fabs(x1 - x2) , 2) + powf( fabs(y1 - y2) , 2) );
}

struct node{
	double x;
	double y;
	double key;
	node(double x,double y,double key){
		this->x = x;
		this->y = y;
		this->key = key;
	}
	bool operator < (const node& p) const{
		return  this->key > p.key  ;
	}
};


vector< pair<double,double> > vertices;
map< pair<pair<double,double>,pair<double,double> >,double > edgeCost;
map< pair<double,double>,double > key;
map< pair<double,double> ,int > selected;

void clear(){
	vertices.clear();
	edgeCost.clear();
	key.clear();
	selected.clear();
}

void mst(pair<double,double> n){
	priority_queue<node> q;
	q.push(node(n.first,n.second,0));
	key[n] = 0;
	for(auto i : vertices){
		if(i != n){
			key[i] = DBL_MAX;
		}
	}
	while(!q.empty()){
		node top = q.top();
		q.pop();
		selected[{top.x,top.y}] = 1;
		for(auto i : vertices){
			if(!selected.count({i.first,i.second})){
				double x;
				edgeCost[{ {top.x,top.y},{i.first,i.second} }] = x = dist(i.first,i.second,top.x,top.y);
				if(key[{i.first,i.second}] > x){
					q.push(node(i.first,i.second,x));
					key[{i.first,i.second}] = x;
				}
			}
		}
	}
}

int main(){
	int tt;
	cin>>tt;
	while(tt--){
		
		int numOfCordinations;
		cin>>numOfCordinations;
		while(numOfCordinations--){
			double x,y;
			cin>>x>>y;
			vertices.push_back(pair<double,double>(x,y));
		}
		double sum = 0;
		mst(vertices.front());
		for(auto i : key){
			sum += i.second;
		}
		printf("%.2lf\n",sum);
		clear();
		if(tt){
			cout<<endl;
		}
	}
}
