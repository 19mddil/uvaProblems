#include<bits/stdc++.h>
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0);
#define infinity INT_MAX
using namespace std;
long int m;
long int F(long int n,long int p){
	if(p == 0) return 1;
	if(p%2==0){
		long int ret = F(n,p/2);
		return((ret%m)*(ret%m))%m;
	}
	else
		return ((n%m)*(F(n,p-1)%m))%m;
}

int main(){
	long int b,p;
	//Fin;
	while(cin>>b>>p>>m){
		cout<<F(b,p)<<endl;
	}
}
