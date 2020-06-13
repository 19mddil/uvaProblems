#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,vector<int> >G;
vector<int>result;

void dfs(int y){
    for(auto i:G[y]){
        if(visited[i] == false){
            visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    int numOfVertices;
    while(cin>>numOfVertices,numOfVertices){
        cin.ignore();
        string s;
        stringstream ss;
        int a,b;
        while(getline(cin,s)){
            if(s == "0"){
                break;
            }
            ss<<s;
            ss>>a;
            while(ss>>b){
                if(b == 0){
                    break;
                }
                G[a].push_back(b);

            }
            ss.clear();
        }
        getline(cin,s);
        ss.clear();
        ss<<s;
        int x,y;
        ss>>x;
        while(x--){
            while(ss>>y){
                for(int i = 1;i<= numOfVertices;i++){
                    visited[i] = false;
                }
                dfs(y);
                int cnt = 0;
                for(int i = 1;i<=numOfVertices;i++){
                    if(visited[i] == false){
						cnt++;
                        result.push_back(i);
                    }
                }
                cout<< cnt;
                if(!result.empty()) cout<<' ';
                bool p = false;
                for(auto i:result){
                    if(p) cout<<' ';
                    p = true;
                    cout<<i;
                }
                cout<<endl;
                result.clear();
            }
        }
        G.clear();
    }
}
