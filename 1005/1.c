#include"stdio.h"
#include"math.h"
#define MAX 1<<16
#define e 1e-6
#define pi 3.141592653
int main(int argc,char*argv[])
{
	int n,i;
	scanf("%d",&n);
	float x,y;
	float square;
	int yr;
	for(i=0;i<n;i++)
	{
		scanf("%f %f",&x,&y);
		square=0.5f*pi*(x*x+y*y);
		yr=ceil(square/50.0f+e);
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,yr);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
