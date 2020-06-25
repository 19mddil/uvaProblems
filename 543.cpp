#include<stdio.h>
#include<math.h>
/**use binary search if you can for brute force approach which took 15 sec to complete**/

/*
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define Faster       cin.tie(0);cout.tie(0); 

double pi = acos(-1.);

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
*/

int prime[78499];
bool mark[1000001];
int primeIndex = 0;
int i,j,n,limit,b;
bool flag;

void sieve(int n){
	limit = sqrt(n * 1.) + 2;
	mark[1] = true;
	for(i = 4;i<=n;i+=2) 
		mark[i] = true;
	prime[++primeIndex] = 2;
	for(i=3;i<=n;i+=2){
		if(!mark[i]){
			prime[++primeIndex] = i;
			if(i<=limit){	
				for(j=i*i;j<= n; j+= i * 2){
					mark[j] = true;	
				}
			}
		}
	}
}

int main(){
	//Fin;
	//Fout;
	//FasterIO;
	sieve(1000000);
	while(scanf("%d",&n)==1 && n != 0){
		flag = false;
		for(i = 1 ;i<=(primeIndex/2)+2;i++){
			b = n - prime[i];
			if(mark[b] == false){
				flag = true;
				printf("%d = %d + %d\n",n,prime[i],b);
				break;
			}
		}
		if(flag){
			continue;
		}else{
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
}

