#include<bits/stdc++.h>
using namespace std;

map<char,int>hehe;
int n;

inline string stoi(int x){
	stringstream ss;
	ss << x;
	string s;
	ss>>s;
	return s;
}

int main(){
	int tt;
	cin>>tt;
	while(tt--){
		cin>>n;
		string s;
		for(int i = 1;i<= n;i++){
			s += stoi(i);
		}
		int i = 0;
		for(char i = '0';i<='9';i++){
			hehe[i] = 0;
		}
		while(s[i] != '\0'){
			hehe[s[i]] = hehe[s[i]] + 1;
			i++;
		}
		for(char i = '0';i<='9';i++){
			if(i == '9'){
				cout<<hehe[i];
				continue;
			}
			cout<<hehe[i]<<' ';
		}
		cout<<endl;
	}
}
