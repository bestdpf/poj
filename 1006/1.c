#include"stdio.h"
//#include"stdlib.h"
#define pt 23
#define et 28
#define it 33
#define MAX 21252

int main(int argc,char* argv[])
{
	int p,e,i,d;
	int count=1;
	while(scanf("%d %d %d %d",&p,&e,&i,&d)!=EOF)
	{
		//printf("input p e i d is %d %d %d %d \n",p,e,i,d);
		if(p==-1)break;
		while(p<=d)p+=pt;//increase p>d
		while(e<=d)e+=et;
		while(i<=d)i+=it;
		//printf("after increase: %d %d %d %d\n",p,e,i,d);
		while(p>d+pt)p-=pt;//decrease p make p is not too big
		while(e>d+et)e-=et;
		while(i>d+it)i-=it;
		//printf("after decrease: %d %d %d %d\n",p,e,i,d);
		//ans is must at right side
		while(((p-e)<0||(p-i)<0||(p-e)%et!=0||(p-i)%it!=0)&&(p-d)<=MAX-pt)p+=pt;//make p>e p-e=5m p-i=5n	
		//while(e<p)e+=et;
		//while(i<p)i+=it;
		//printf("result: %d %d %d %d\n",p,e,i,d);
		printf("Case %d: the next triple peak occurs in %d days.\n",count,p-d);
		count++;
	}
	return 0;
}
