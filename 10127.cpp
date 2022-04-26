#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);
#define infinity INT_MAX
using namespace std;
short c;
short cnt;
void F(short n){
	c = (c*10+1)%n;
	cnt++;
	if(c == 0) return;
	F(n);
}


int main(){
	short n;
	//Fin;
	while(cin>>n){
		c = 0;
		cnt = 0;
		F(n);
		cout<<cnt<<endl;
	}
	
}
