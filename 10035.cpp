#include<stdio.h>

int main(){
	long long  a,b;
	int res;
	int c;
	while(scanf("%llu %llu",&a,&b)==2){
		if(a == 0 && b == 0){
			break;
		}
		res = 0;
		c = 0;	
		while(a || b){
			res = ( res + a%10 + b%10)/10;
			a = a/10;
			b = b/10;
			c += res;
		}
		c == 0?printf("No carry operation.\n"):c != 1?printf("%d carry operations.\n",c):printf("%d carry operation.\n",c);
	}
}	
