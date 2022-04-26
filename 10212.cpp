#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);
#define infinity INT_MAX
using namespace std;
int main(){
	long long n,m,last9digits,i;
	//Fin;
	while(cin>>n>>m){
		last9digits = 1ll;
		i = n;
		while(i>=(n-m+1)){ // here down calculation needed
			last9digits *= i;
			while(last9digits%10 == 0) last9digits /= 10;
			last9digits %= 1000000000;
			i--;
		}
		cout<<(last9digits%10)<<endl;
	}
	return 0;
}
