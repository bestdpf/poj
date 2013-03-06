#include"stdio.h"
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 100
int main(int argc,char*argv[])
{
	int type[MAX];
	int request[MAX];
	int maxNum[MAX];
	int count[MAX];
	int tidx,ridx;
	while(scanf("%d",type)!=EOF)
	{
		tidx=1;
		ridx=0;
		while(scanf("%d",type+tidx)!=EOF)
		{
			if(*(type+tidx)==0)break;
			else
			{
			tidx++;
			}
		}
		while(scanf("%d",request+ridx)!=EOF)
		{
			if(*(request+ridx)==0)break;
			else
			{
			ridx++;
			}
		}
		int i;
		for(i=0;i<ridx;i++)
		{
			int all=request[i];
			int j;
			for(j=0;j<tidx;j++)
			{
				maxNum[j]=min((int)ceil((float)all/type[j]),25);
				count[j]=0;
			}
			int give=0;
			for(j=0;j<tidx;j++)
			{
				give+=
			
			}
		}
	}
	return 0;
}
