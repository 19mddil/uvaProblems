#include<bits/stdc++.h>
using namespace std;

string s;
vector<char>vertices;
map<char,int>indegreee;
map<char,vector<char> > G;
map<char,bool>visited;
vector<char>result;

void clear(){
    vertices.clear();
    indegreee.clear();
    visited.clear();
    result.clear();
    G.clear();
}

void allTopoSort(vector<char>& result,map<char,bool>visited){
    bool f = false;
    for(auto i:vertices){
        if(indegreee[i] == 0 && !visited[i]){
            for(auto j:G[i]){
                indegreee[j] = indegreee[j] - 1;
            }
            result.push_back(i);
            visited[i] = true;
            allTopoSort(result,visited);
            visited[i] = false;
            result.pop_back();
            for(auto j:G[i]){
                indegreee[j] = indegreee[j] + 1;
            }
            f = true;
        }
    }
    if(!f){
        for(auto i:result){
            cout<<i;
        }
        cout<<endl;
    }
}


int main(){
		for(int T = 0;;T++){
            if(!getline(cin,s)) break;
            if(T>0) cout<<endl;
            stringstream ss;
            char c;
            ss<<s;
            while(ss>>c){
                vertices.push_back(c);
                indegreee[c] = 0;
                visited[c] = false;
            }
            sort(vertices.begin(),vertices.end());
            getline(cin,s);
            stringstream ss1;
            char a,b;
            ss1<<s;
            while(ss1>>a>>b){
                G[a].push_back(b);
                indegreee[b] = indegreee[b] + 1;
            }
            allTopoSort(result,visited);
            clear();
        }

}
