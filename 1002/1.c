#include"stdio.h"
#include"stdbool.h"
#include"stdlib.h"
#include"string.h"
#define MAX 10000000
int vec[MAX];
int char2int(char c)
{
	switch(c)
	{
		case 'A': case'B': case'C': return 2;
		case 'D': case'E': case'F': return 3;
		case 'G': case'H': case'I': return 4;
		case 'J': case'K': case'L': return 5;
		case 'M': case'N': case'O': return 6;
		case 'P': case'R': case'S': return 7;
		case 'T': case'U': case'V': return 8;
		case 'W': case'X': case'Y': return 9;
		default: return 0;
	}
}
int main(int argc,char*argv[])
{
	int n;
	scanf("%d",&n);
	int i,j;
	char tmp[100];
	int intStr;
	char s[7];
	int count;
	//int vec[MAX];
	for(i=0;i<MAX;i++)
	{
		vec[i]=0;
	}
	for(i=0;i<n;i++)
	{
		count=0;
		scanf("%s",tmp);
		for(j=0;j<strlen(tmp);j++)
		{
			if(tmp[j]>='0'&&tmp[j]<='9')s[count++]=tmp[j];
			else if(tmp[j]>='A'&&tmp[j]<='Z')s[count++]=char2int(tmp[j])+'0';
			else continue;
		}
		intStr=atoi(s);
		//printf("input: %d\n",intStr);
		vec[intStr]++;
	}
	bool has=false;
	for(i=0;i<MAX;i++)
	{
		if(vec[i]>1)
		{
			printf("%d%d%d-%d%d%d%d %d\n",i/1000000,i/100000%10,i/10000%10,i/1000%10,i/100%10,i/10%10,i%10,vec[i]);
			has=true;
		}
	}
	if(has==false)printf("No duplicates.\n");
	return 0;
}
