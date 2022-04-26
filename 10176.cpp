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



int main(){
	string s;
	int m = 131071;
	int modsum = 0;
	int b = 0;
	//Fin;
	while(cin>>s){
		modsum = 0;
		b = 0;
		for(int i = 0;i<s.length();i++){
			if(s[i] == '#'){
				cout<<(modsum == 0?"YES":"NO")<<endl;
				//Fout;
				break;
			}
			b = s[i] - '0';
			modsum= (modsum* 2 + b)% m;
			
		}
	}
	return 0;
}
