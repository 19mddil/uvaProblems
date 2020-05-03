#include<stdio.h>

int main(void){
	int tt;
	scanf("%d",&tt);
	int count= 0;
	while(tt--){
		count++;
		int a,b;
		scanf("%d %d",&a,&b);
		if(a&1){
			printf("Case %d: %d\n",count,( ((b+1)/2)*((b+1)/2) )- ( (a/2)*(a/2) ) );
		}else{
			printf("Case %d: %d\n",count,( ((b+1)/2)*((b+1)/2) )- ( ((a+1)/2)*((a+1)/2) ) );
		}
	}
}
