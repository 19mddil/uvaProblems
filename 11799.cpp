/** Sorting problem **/
#include<sstream>
#include<algorithm>
#include<queue>
#include<iostream>
std::priority_queue<int> x;
std::stringstream ss;
std::string s;
int c = 0;
void clear(){
	x = std::priority_queue<int>();
	ss.clear();
}
int main(){
	int tt;
	scanf("%d",&tt);
	getchar();
	while(tt--){
		getline(std::cin,s);
		ss<<s;
		int a;
		while(ss>>a){
			x.push(a);
		}
		printf("Case %d: %d\n",++c,x.top());
		clear();
		
	}
}
