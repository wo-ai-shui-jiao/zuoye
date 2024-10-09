#include<stdio.h>
#include"add.h"
#include"add_adv.h"
int main(){
	int a=0,b=0,c=0;
	scanf("%d %d",&a,&b);
	c=add(a,b);
	printf("%d\n",c);
	c=add_adv(a,b,c);
	printf("%d\n",c);
	return 0;
}
