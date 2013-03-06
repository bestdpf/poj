#include"stdio.h"
#include"string.h"
#include<vector>
#include<algorithm>
#include<iterator>
#define MAX 50
using namespace std;
typedef struct nodeD{
	char str[MAX+1];
	int unsort;
}node;
bool cmp(const node &n1,const node &n2)
{
	return n1.unsort<n2.unsort;
}
int main(int argc,char* argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	char tmp[MAX+1];
	vector<node>nodeVec;
	for(i=0;i<m;i++)
	{
		scanf("%s",tmp);
		int j,k;
		int unsort=0;
		for(j=0;j<strlen(tmp)-1;j++)
			for(k=j+1;k<strlen(tmp);k++)
			{
				if(tmp[j]>tmp[k])unsort++;
			}
		node tmpNode;
		tmpNode.unsort=unsort;
		strcpy(tmpNode.str,tmp);
		nodeVec.push_back(tmpNode);
	}
	stable_sort(nodeVec.begin(),nodeVec.end(),cmp);
	vector<node>::iterator it;
	for(it=nodeVec.begin();it!=nodeVec.end();it++)
	{
		printf("%s\n",it->str);
	}
	return 0;
}
