#include"stdio.h"
#include"stdlib.h"
#define e 0.000001f
#define MAX 280
int main(int argc,char*argv[])
{
	float tab[MAX];
	float sum=0.0f;
	int i;
	for(i=0;i<MAX;i++)
	{
		sum+=1.0f/(2+i);
		tab[i]=sum;
	}
	float tmp;
	while(scanf("%f",&tmp)!=EOF)
	{
		if(tmp<e)break;
		else
		{
			i=0;
			while(tab[i]<tmp+e)i++;
			printf("%d card(s)\n",i+1);	
		}
	}
	return 0;
}
