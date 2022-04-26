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
int main(){
	int n;//number of perticipants
	int b;//the budget
	int h;//number of hotels to consider
	int w;//the number of weeks you can choose between
	int t;
	//Fin;
	while(cin>>n>>b>>h>>w){
		int p;//price of one person staying in the hotel
		int min = 100000000;
		while(h--){
			t = w;
			cin>>p;
			//cout<<"p:"<<p<<endl;
			int room;
			bool f = 0;
			while(t--){
				cin>>room;
				if(room >= n && f == 0){
					int s = n*p;
					if(s<=min){
						//cout<<n<<"*"<<p<<endl;
						//cout<<s<<endl;
						min = s;
						f = 1;
					}
				}
			}
		}
		if(min < b || min == b){
			cout<<min<<endl;
		}
		else{
			cout<<"stay home"<<endl;
		}
	}
	
}
