/* Slow but working:( updated 2998 */

#include<bits/stdc++.h>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int n;
vector<int> nums;
vector<bool> use;
vector<int> pos;
int c;
void clear(){
	nums.clear();
	use.clear();
	pos.clear();
}

bool isPrime(int n){
	/*
	for( int i = 2; i< (ceil(sqrt(n)) + 1); i++){
		if((n % i) == 0){
			return false;
		}
	}
	return true;
	*/
	for(int a: prime){
		if(n == a) return true;
	}
	return false;
}


void gen(int idx){
	use[idx] = true;
	pos.push_back(idx);
	if( (int) pos.size() == n && isPrime(pos[0] + pos[n-1]) ){
		int tt = 0;
		char xx = ' ';
		for(auto i: pos){
			cout<<i;
			if(tt < n-1){
				cout<<xx;
			}
			tt++;
		}
		cout<<endl;
	}
	if((int)pos.size() != n){
		for(int i = 1;i<(n+1);i++){
			if( !use[i] && isPrime(i+idx) ){
				gen(i);
			}
		}
	}
	use[idx] = false;
	pos.pop_back();
	return;
}

int main(){
	while(cin>>n){
		if(c)
		cout<<endl;
		cout<<"Case "<< ++c <<':'<<endl;
		nums.resize(n+1);
		use.resize(n+1);
		for(int i = 1;i<(n+1);i++){
			nums[i] = i;
			use[i] = false;
		}
		gen(1);
		clear();
	}
}
