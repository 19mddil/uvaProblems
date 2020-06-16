#include<bits/stdc++.h>
using namespace std;

int fx[] = {0,-1,0};
int fy[] = {-1,0,+1};
char p[9][9];
int m,n;
map<char,char>save;
map< pair<int,int> ,string > resultMap;
map< pair<int,int>,bool >visited;
vector<string>result;

void clear(){
    visited.clear();
    result.clear();
}

void dfs(int dm,int dn){
    if(p[dm][dn] == '#' && result.size() == 7){
        bool p = false;
        for(auto i:result){
            if(p) cout<<' ';
            p = true;
            cout<<i;
        }
        cout<<endl;
        return;
    }
    int dmx,dny;
	for(int i = 0;i<3;i++){
        dmx = dm + fx[i];
        dny = dn + fy[i];
        if(dmx >= 0 && dny >= 0 && dmx<m && dny<n && visited[{dmx,dny}] == false && save.find(p[dmx][dny]) != save.end() ){
            visited[{dmx,dny}] = true;
            result.push_back(resultMap[{fx[i],fy[i]}]);
            dfs(dmx,dny);
            visited[{dmx,dny}] = false;
            result.pop_back();
        }
    }
}

int main(){
    int tt;
    cin>>tt;
    save['I'] = 'I';
    save['E'] = 'E';
    save['H'] = 'H';
    save['O'] = 'O';
    save['V'] = 'V';
    save['A'] = 'A';
    save['#'] = '#';
    resultMap[{0,-1}] = "left";
    resultMap[{-1,0}] = "forth";
    resultMap[{0,1}] = "right";
    while(tt--){
        cin>>m>>n;
        cin.ignore();
        string s;
        for(int i = 0;i<m;i++){
            getline(cin,s);
            int k = 0;
            for(auto j:s){
                p[i][k] = j;
                k++;
            }
        }
        for(int i = 0;i<n;i++){
            if(p[m-1][i] == '@'){
                visited[{m-1,i}] = true;
                dfs(m-1,i);
                break;
            }
        }
        clear();
    }
}
