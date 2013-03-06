#include"stdlib.h"
#include"stdio.h"
#include"string.h"
#define LEFT 250 
#define RIGHT 250

typedef struct bigNumS{
	int num[LEFT+RIGHT];
	int left;
	int right;
} bigNum;

bigNum initNum(bigNum a)
{
	int i;
	for(i=0;i<LEFT+RIGHT;i++)
		a.num[i]=0;
	a.left=1;
	a.right=0;
	return a;
}

bigNum str2BigNum(char* str)
{
	bigNum a;
	a=initNum(a);
	int i,j;
	bool hasPoint=false;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]!='.')continue;
		else
		{
		hasPoint=true;
		break;
		}
	}
	a.left=i;
	a.right=hasPoint?(strlen(str)-a.left-1):0;
	for(i=LEFT-a.left,j=0;j<a.left;j++,i++)
	{
		a.num[i]=str[j]-'0';
	}
	for(++j;j<strlen(str);j++,i++)
	{
		a.num[i]=str[j]-'0';
	}
	return a;
}
void dumpNum(bigNum a)
{
	int i;
	//for(i=0;i<LEFT+RIGHT;i++)printf("%d ",a.num[i]);
	//printf("\n");
	for(i=LEFT-a.left;i<LEFT+a.right;i++)
	{
		if(i==LEFT)printf(".");
		printf("%d",a.num[i]);
	}
	return;
}

int main(int argc,char* argv[])
{
	char s[100];
	int n;
	bigNum a;
	while(scanf("%s%d",s,&n))
	{
		printf("%s %d\t",s,n);
		a=str2BigNum(s);
		//printf("left: %d right: %d",a.left,a.right);
		dumpNum(a);
	}
	return  0;
}
