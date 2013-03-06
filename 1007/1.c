#include"stdio.h"
#include"string.h"
#define MAX 50
typedef nodeD{
	char str[MAX+1];
	int unsort;
}node;
int main(int argc,char* argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	char tmp[MAX+1];
	for(i=0;i<m;i++)
	{
		scanf("%s",tmp);
		int j,k
		int unsort=0;
		for(j=0;j<strlen(tmp)-1;j++)
			for(k=j+1;k<strlen(tmp);k++)
			{
				if(tmp[j]>tmp[k])unsort++;
			}
		node tmpNode;
		tmpNode.unsort=unsort;
		strcpy(tmpNode.str,tmp);
		
	}
	return 0;
}
