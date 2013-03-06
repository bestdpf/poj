#include"stdio.h"
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
typedef struct nodeD{
	int val;
	int cnt;
}node;

int main()
{
	int w;
	vector<node>nodeVec;
	vector<node>out;
	node tmp;
	int val,num;
	vector<int>pixCnt;
	while(scanf("%d",&w)!=EOF)
	{
		if(w==0)break;
		int pixNum=0;
		do{
			scanf("%d %d",&val,&num);
			tmp.val=val;
			tmp.cnt=num;
			pixNum+=num;
			nodeVec.push_back(tmp);
			pixCnt.push_back(num);
		}while(val!=0||num!=0);
		int roudNdNum[]={0,0,0,0,0,0,0,0,0};//around node num
		int dist[]={-w-1,-w,w+1,-1,0,1,w-1,w,w+1};
		int pos=0;int maxDiff=0;
		int zeroLeft=-1,zeroRight=0;//zero zone include left, but not right;
		node nowNode;
		node zeroNode;
		nowNode.val=0;
		nowNode.cnt=0;
		zeroNode.val=0;
		zeroNode.cnt=0;
		bool hasZero=false;
		bool testZero=true;//only test for first element in this node;
		bool lastZero=false;//last node is zeroNode, use to merge zeroNode;
		//bool hasJump=false;//in this circle i has jump
		//bool lastPushNowNode=false;//last has push the nowNode, don't make it twice;
		//int jumpSize=1;
		int i;
		while(pos<pixNum)
		{
			if(hasZero&&zeroLeft==pos)//push zeroNode, the first
			{
				if(lastZero==true&&nowNode.val==0)
				{
					out.back().cnt+=nowNode.cnt+zeroNode.cnt;
				}
				else if(nowNode.val==0)
				{
					zeroNode.cnt+=nowNode.cnt;
					out.push_back(zeroNode);
				}
				else
				{ 
					if(nowNode.cnt>0)out.push_back(nowNode);
					out.push_back(zeroNode);
				}
				hasZero=false;
				lastZero=true;
				nowNode.cnt=0;
				nowNode.val=0;//reset nowNode 
				//lastPushNowNode=true;
				//jumpSize=zeroRight-zeroLeft;
				pos=zeroRight;//jump to the next
			}
			else//not to push zeroNode
			{
			//jumpSize=1;//just increase 1;
			if(testZero)
			{
				if(nodeVec[roudNdNum[4]].cnt>2*w)
				{
					zeroNode.cnt=nodeVec[roudNdNum[4]].cnt-2*w;
					zeroLeft=pos+w;
					zeroRight=pos+nodeVec[roudNdNum[4]].cnt-w;
					hasZero=true;
				}
				testZero=false;
			}
			//for a normal pix, calc the maxDiff;
			/*
			for(i=0;i<9;i++)
			{
			}
			*/
			if(pos-w-1>=0)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[0]].val));
			if(pos-w>=0)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[1]].val));
			if(pos-w+1>=0)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[2]].val));
			if(pos-1>=0)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[3]].val));
			if(pos+1<pixNum)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[5]].val));
			if(pos+w-1<pixNum)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[6]].val));
			if(pos+w<pixNum)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[7]].val));
			if(pos+w+1<pixNum)maxDiff=max(maxDiff,abs(nodeVec[roudNdNum[4]].val-nodeVec[roudNdNum[8]].val));
			if(nowNode.cnt>0)//nowNode is has value
			{
			if(maxDiff==nowNode.val)nowNode.cnt++;//increase the size of nowNode
			else{//push old nowNode,create a new nowNode
				//if(lastZero==true)
				if(lastZero==true&&nowNode.val==0)out.back().cnt+=nowNode.cnt;//last is zero, now is still, merge them;
				else 
					{
					if(nowNode.val==0)lastZero=true;//meaningless!!!
					out.push_back(nowNode);
					}
				nowNode.cnt=1;
				nowNode.val=maxDiff;
				
				}
			}
			else//last has just jump  nowNode is out of date info
			{
				nowNode.val=maxDiff;
				nowNode.cnt=1;
			}
				//lastPushNowNode=false;//the second 
			}//end else (not to push zeroNode)
			//update new roudNdNum and pos;
			int p,q;
			for(p=0;p<9;p++)
				{
					while(pos+dist[i]>pixCnt[roudNdNum[i]]-1)
									{
									roudNdNum[i]++;	
									//for current pos, should test zero next one
									if(i==4)testZero=true;
									}
				}
		}
		vector<node>::iterator it;
		for(it=nodeVec.begin();it!=nodeVec.end();it++)
			{
				printf("%d %d\n",it->val,it->cnt);
			}
		printf("0 0\n");
		nodeVec.clear();//free mem
		out.clear();
	}
	printf("0\n");
	return 0;
}
