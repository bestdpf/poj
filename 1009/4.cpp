#include"stdio.h"
#include<list>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
using namespace std;
typedef struct nodeD{
	int val;
	int cnt;
	int ofs;
}node;

int main(int argc,char*argv[])
{
	int w;//width
	int tmpVal=0;
	int tmpCnt=0;
	node tmpNode;
	node lastNode,zeroNode;
	lastNode.val=0;
	lastNode.cnt=0;
	lastNode.ofs=0;
	list<node> inList;
	list<node> outList;
	list<node>::iterator it[9];
	set<int> tab;
	while(true)
	{
	scanf("%d",&w);
	//printf("\n\n\nnew image %d\n",w);
	int dist[]={-w-1,-w,-w+1,-1,0,1,w-1,w,w+1};
	int pixCnt=0;
	if(w==0)break;//end
	//do-while build inList;
	scanf("%d %d",&tmpVal,&tmpCnt);
	while(tmpVal!=0||tmpCnt!=0)	
	{
	//scanf("%d %d",&tmpVal,&tmpCnt);
	//printf("new node %d %d\n",tmpVal,tmpCnt);
	tmpNode.val=tmpVal;
	tmpNode.cnt=tmpCnt;
	tmpNode.ofs=pixCnt;
	int k,l;
	for(k=0;k<9;k++)
	{
		l=tmpNode.ofs+dist[k];
	//	printf("test ofs=%d  l=%d\n",tmpNode.ofs,l);
		if(l>=0)tab.insert(l);
	}
	//printf("this node val: %d cnt: %d ofs: %d\n",tmpNode.val,tmpNode.cnt,tmpNode.ofs);
	inList.push_back(tmpNode);
	pixCnt+=tmpCnt;
	scanf("%d %d",&tmpVal,&tmpCnt);
	}
	//first level generate outList
	tmpNode.val=0;
	tmpNode.cnt=0;
	tmpNode.ofs=0;
	zeroNode.val=0;
	zeroNode.cnt=0;
	zeroNode.ofs=0;
	int pos=0;
	int i;
	list<node>::iterator it1=inList.begin();
	for(i=0;i<9;i++)
	{
	//	printf("init it[]\n");
	//	printf("%d Vs. %d\n",it1->ofs+it1->cnt,pos+dist[i]);
		while(it1->ofs+it1->cnt<=pos+dist[i])it1++;
		it[i]=it1;
	}
	//printf("just after init it[]\n");
	//it={inList.begin()};
	int maxDiff=0,lastDiff=0;
	while(pos<pixCnt)
	{	
		maxDiff=0;
		if(tab.count(pos)>0)
		{
			//printf("should calc\n");
		for(i=0;i<9;i++)
		{
			/*
			if(pos<w&&i<3)continue;
			if(pos>pixCnt-w&&i>5)continue;
			if(pos%w==0&&i==3)continue;
			if(pos%w==w-1&&i==5)continue;
			if(i==4)continue;//itself
			*/
			if((pos<w&&i<3)||(pos>pixCnt-w&&i>5)||(pos%w==0&&i%3==0)||(pos%w==w-1&&i%3==2)||(i==4))continue;
			//if(pos==20)printf("special test pos=%d i=%d not continue\n",pos,i);
			if(pos+dist[i]>=0&&pos+dist[i]<pixCnt)maxDiff=max(maxDiff,abs(it[i]->val-it[4]->val));
		}
		}
		else
		{
			//printf("old value\n");
			maxDiff=lastDiff;
		}
		//printf("pos: %d dif: %d\n",pos,maxDiff);
		lastDiff=maxDiff;//store the maxDiff;
		if(tmpNode.val==maxDiff)
		{
			tmpNode.cnt++;
		}
		else
		{
			if(tmpNode.cnt>0)
			{
				outList.push_back(tmpNode);
				tmpNode.cnt=0;
				tmpNode.val=0;
			}
			//else//just make the new tmpNode;
			//{
			//make the new node
			tmpNode.val=maxDiff;
			tmpNode.cnt=1;
			//}
		}
		pos++;//increase 1
		//set it[]
		for(i=0;i<9;i++)
		{
	//		printf("%d times reset it[]: %d Vs %d\n",i,it[i]->ofs+it[i]->cnt,pos+dist[i]);
			while(it[i]->ofs+it[i]->cnt<=pos+dist[i]&&it[i]!=inList.end())it[i]++;
		}
	}
	
		if(tmpNode.cnt>0)
		{
			if(tmpNode.cnt>0)
			{
				outList.push_back(tmpNode);
				tmpNode.cnt=0;
				tmpNode.val=0;
				tmpNode.ofs=0;
			}
		}
		//dump outList
		list<node>::iterator it2;
		printf("%d\n",w);
		for(it2=outList.begin();it2!=outList.end();it2++)
		{
			printf("%d %d\n",it2->val,it2->cnt);
		}
		
		printf("0 0\n");
		//free mem
		tab.clear();
		inList.clear();
		outList.clear();
	}
	printf("0\n");
	return 0;
}
