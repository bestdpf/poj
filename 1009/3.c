#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"stdbool.h"
#define MAX 2000
//#include<list>
//#include<algorithm>
//using namespace std;
//#include<iterator>

int  max(int a,int b)
{
	return a>b?a:b;
}

//using namespace std;
typedef struct nodeD{
	int val;
	int cnt;
	int ofs;
}node;
node inList[MAX];
node outList[MAX];
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
	//node inList[MAX];
	//node outList[MAX];
	int it[9];
	while(true)
	{
	scanf("%d",&w);
	//printf("\n\n\nnew image %d\n",w);
	int dist[]={-w-1,-w,-w+1,-1,0,1,w-1,w,w+1};
	int pixCnt=0;
	int idx=0;
	if(w==0)break;//end
	//do-while build inList;
	scanf("%d %d",&tmpVal,&tmpCnt);
	while(tmpVal!=0||tmpCnt!=0)	
	{
	//scanf("%d %d",&tmpVal,&tmpCnt);
	//printf("new node inList[%d] %d %d\n",idx,tmpVal,tmpCnt);
	tmpNode.val=tmpVal;
	tmpNode.cnt=tmpCnt;
	tmpNode.ofs=pixCnt;
	//printf("this node val: %d cnt: %d ofs: %d\n",tmpNode.val,tmpNode.cnt,tmpNode.ofs);
	inList[idx++]=tmpNode;//inList.push_back(tmpNode);
	pixCnt+=tmpCnt;
	//idx++;
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
	int it1=0;
	for(i=0;i<9;i++)
	{
	//	printf("init it[]\n");
	//	printf("%d Vs. %d\n",it1->ofs+it1->cnt,pos+dist[i]);
		while(inList[it1].ofs+inList[it1].cnt<=pos+dist[i])it1++;
		it[i]=it1;
	}
	//printf("just after init it[]\n");
	//it={inList.begin()};
	int zeroLeft=0,zeroRight=0;
	int outidx=0;
	while(pos<pixCnt)
	{	
		//printf("pos = %d val: %d\n",pos,inList[it[4]].val);
		if(pos==inList[it[4]].ofs)//the first pix of current node,test zero
		{
			if(inList[it[4]].cnt>2*w+2)
			{
			zeroLeft=pos+w+1;
			zeroRight=pos+inList[it[4]].cnt-w-1;
			zeroNode.cnt=zeroRight-zeroLeft;
			//printf("zeroNode build %d\n",zeroNode.cnt);
			}
		}
		int maxDiff=0;
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
			//printf("%d %d %d vs %d\n",pos,pos+dist[i],maxDiff,abs(inList[it[i]].val-inList[it[4]].val));
			if(pos+dist[i]>=0&&pos+dist[i]<pixCnt)maxDiff=max(maxDiff,abs(inList[it[i]].val-inList[it[4]].val));
		}
		//printf("pos: %d dif: %d\n",pos,maxDiff);
		if(tmpNode.val==maxDiff)
		{
			tmpNode.cnt++;
		}
		else
		{
			if(tmpNode.cnt>0)
			{
				//printf("change node\n");
				outList[outidx++]=tmpNode;
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
		if(zeroRight>zeroLeft&&pos==zeroLeft)
		{//reach zero node
			if(tmpNode.cnt>0)
			{
				//printf("before zero push_back %d %d\n",tmpNode.val,tmpNode.cnt);
				outList[outidx++]=tmpNode;
				tmpNode.cnt=0;
				tmpNode.val=0;
			}
			//printf("zero push_back %d %d\n",zeroNode.val,zeroNode.cnt);
			outList[outidx++]=zeroNode;
			zeroNode.cnt=0;
			pos=zeroRight;
			zeroLeft=0;
			zeroRight=0;
		}
		//set it[]
		for(i=0;i<9;i++)
		{
	//		//printf("%d times reset it[]: %d Vs %d\n",i,it[i]->ofs+it[i]->cnt,pos+dist[i]);
			while(inList[it[i]].ofs+inList[it[i]].cnt<=pos+dist[i]&&it[i]<idx)it[i]++;
		}
	}
	
		if(tmpNode.cnt>0)
		{
			if(tmpNode.cnt>0)
			{
				//printf("last push\n");
				outList[outidx++]=tmpNode;
				tmpNode.cnt=0;
				tmpNode.val=0;
				tmpNode.ofs=0;
			}
		}
		//printf("second level\n\n");
		//second level
		//printf("%d\n",w);
		int it2=0,it3=1/*,it3=outList.begin()*//*,it4=outList.begin()*/;
		//it3++;
		//i=0;
		while(it3<outidx)
		{
			//printf("test remove it2: %d it3: %d val2: %d val3: %d\n",it2,it3,outList[it2].val,outList[it3].val);
			if(outList[it2].val==outList[it3].val)
			{
				outList[it2].cnt+=outList[it3].cnt;
				outList[it3].ofs=-1;
				it3++;
				//it4=it2;
				//it3=it4++;
				//printf("equal stay\n");
			}
			else
			{
				it2=it3;
				it3++;
				//printf("not equal just advance\n");
			}
		}		
		
		//dump outList
		printf("%d\n",w);
		for(it2=0;it2<outidx;it2++)
		{
			if(outList[it2].ofs==0)printf("%d %d\n",outList[it2].val,outList[it2].cnt);
		}
		
		printf("0 0\n");
		//free mem
		//inList.clear();
		//outList.clear();
	}
	printf("0\n");
	return 0;
}
