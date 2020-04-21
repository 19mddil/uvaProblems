#include<cstdio>
int main(){
	char cc;
	bool flag = false;
	while(scanf("%c",&cc) == 1){
		if(cc == '"'){
			if(!flag){
				printf("%c%c",'`','`');
				flag = !flag;
				continue;
			}
			if(flag){
				printf("%c%c",'\'','\'');
				flag = !flag;
				continue;
			}
		}
		printf("%c",cc);
	}
}
