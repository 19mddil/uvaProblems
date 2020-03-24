#include<bits/stdc++.h>
using namespace std;



string stroin(string s){
	long long  x,y;
	stringstream geek(s);
	geek>>x;
	
	reverse(s.begin(),s.end());
	stringstream geek1(s);
	geek1>>y;
	
	return to_string(x+y);
}

int main(){
	
	int tt;
	cin>>tt;
	while(tt--){
		string s;
		cin>>s;
		int n = 1000;
		int count = -1;
		string t1,t2;
		while(n--){
			count++;
			t1 = s;
			reverse(s.begin(),s.end());
			t2 = s;
			if(t1 == t2){
				cout<<count <<' '<< t1<<endl;
				break;
			}
			s = stroin(t1);
		}
		
	}
}
