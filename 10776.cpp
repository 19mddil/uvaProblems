#include<bits/stdc++.h>
using namespace std;

vector<bool>use;
vector<char>res;
string str;
int k;
int n;

void clear(){
	use.clear();
	res.clear();
	str = "";
	k = 0;
	n = 0;
}

void back(int x){
	if((int)res.size() == k){
		for(auto i : res){
			cout<<i;
		}
		cout<<endl;
		return;
	}
	for(int i = x;i< n;i++){
		if(use[i] == false){
			use[i] = true;
			res.push_back(str[i]);
			back(i+1);
			use[i] = false;
			res.pop_back();
		}
		
		while((i+1) < n && str[i] == str[i+1]){
			i++;
		}
		
	}
}

int main(){
	while(cin>>str>>k){
		n = str.length();
		sort(str.begin(),str.end());
		use.resize(n);
		for(int i = 0;i<n;i++){
			use[i] = false;
		}
		back(0);
		clear();
	}
}
