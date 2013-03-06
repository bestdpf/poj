#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"stdbool.h"
#define INMAX 1005
#define OUTMAX 9005
//#include<list>
//#include<algorithm>
//using namespace std;
//#include<iterator>

int  max(int a,int b)
{
	return a>b?a:b;
}

//using namespace std;
//val is maxDiff, ofs is its pos;
typedef struct nodeD{
	int val;
	int cnt;
	int ofs;
}node;
//binary search, in fact stl has binary_search() 
bool binSearch(node* nvec,int left,int right,node nd)
{
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(nd.ofs>nvec[mid].ofs)left=mid+1;
		else if(nd.ofs<nvec[mid].ofs)right=mid;
		else
		{
			//found
			return true;	
		}
	}
	//not found
	return false;
}
//binary insert, compare ofs 
bool binInsert(node* nvec,int left,int right,node nd)
{
	int mid;
	int right_back=right;
	while(left<right)
	{
		mid=(left+right)/2;
		if(nd.ofs>nvec[mid].ofs)left=mid+1;
		else if(nd.ofs<nvec[mid].ofs)right=mid;
		else
		{
			//found
			return true;	
		}
	}
	//not found
	int i;
	for(i=right_back;i>left;i--)
	{
		nvec[i]=nvec[i-1];
	}
	nvec[left]=nd;
	return false;
}
node inList[INMAX];
node outList[OUTMAX];
int main(int argc,char*argv[])
{
	int w;//width
	int tmpVal=0;
	int tmpCnt=0;
	node tmpNode;
	node nd;
	int it[9];
	while(true)
	{
	scanf("%d",&w);
	//printf("\n\n\nnew image %d\n",w);
	int dist[]={-w-1,-w,-w+1,-1,0,1,w-1,w,w+1};
	int pixCnt=0;
	int idx=0;
	int outidx=0;
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
	int k,l,m;
	nd.val=0;nd.cnt=-1;
	for(k=0;k<9;k++)
	{	
		l=tmpNode.ofs+dist[k];
		//printf("node%d pos: %d\n",tmpNode.ofs,l);
		m=tmpNode.ofs;
	//	if((m<w&&k<3)||(m%w==0&&k%3==0)||(m%w==w-1&&k%3==2))continue;	
		if(l<0)continue;
		//l=tmpNode.ofs+dist[k];
		//nd.val=0;
		//nd.cnt=-1;
		nd.ofs=l;
		//printf("node%d pos: %d\n",tmpNode.ofs,l);
		//if(binSearch(outList,0,outidx,nd))printf("found\n");
		if(!binInsert(outList,0,outidx,nd))outidx++;
	}
	//printf("this node val: %d cnt: %d ofs: %d\n",tmpNode.val,tmpNode.cnt,tmpNode.ofs);
	inList[idx++]=tmpNode;//inList.push_back(tmpNode);
	pixCnt+=tmpCnt;
	//idx++;
	scanf("%d %d",&tmpVal,&tmpCnt);
	}
	//test input is enough
	if(pixCnt%w!=0)printf("test pixCnt enough %d\n",pixCnt%w);
	//insert a watch dog in outList
	nd.ofs=pixCnt-w;//the left down element
	if(!binInsert(outList,0,outidx,nd))outidx++;
	nd.val=1000;
	nd.ofs=pixCnt;
	nd.cnt=-1;
	if(!binInsert(outList,0,outidx,nd))outidx++;
	int pos=0;
	//init it[]
	int i;
/*	
	for(i=0;i<outidx;i++)
	{
		printf("outList[%d].ofs=%d\n",i,outList[i].ofs);
	}
*/	
	int it1=0;
	for(i=0;i<9;i++)
	{
	//	printf("init it[]\n");
	//	printf("%d Vs. %d\n",it1->ofs+it1->cnt,pos+dist[i]);
		while(inList[it1].ofs+inList[it1].cnt<=pos+dist[i])it1++;
		it[i]=it1;
	}
	int j;
	for(j=0;outList[j].ofs<pixCnt;j++)
	{
		pos=outList[j].ofs;
		//set it[]
		for(i=0;i<9;i++)
		{
			while(inList[it[i]].ofs+inList[it[i]].cnt<=pos+dist[i]&&it[i]<idx)it[i]++;
		}
		int maxDiff=0;
		for(i=0;i<9;i++)
		{
			if((pos<w&&i<3)||(pos>pixCnt-w&&i>5)||(pos%w==0&&i%3==0)||(pos%w==w-1&&i%3==2)||(i==4))continue;
			if(pos+dist[i]>=0&&pos+dist[i]<pixCnt)maxDiff=max(maxDiff,abs(inList[it[i]].val-inList[it[4]].val));
		}
		//printf("pos: %d dif: %d\n",pos,maxDiff);
		outList[j].val=maxDiff;
		outList[j].cnt=0;
	}
		//outList[j].val=1000;//invaid value to use;
	
		//dump outList
	/*	
		for(i=0;i<outidx;i++)
		{
			printf("test outList[%d] val:%d  ofs:%d\n",i,outList[i].val,outList[i].ofs);
		}
	*/	
		int it3=1,it2=0;
		printf("%d\n",w);
		while(it3<j+1)
		{
			//printf("it3=%d\n",it3);
			if(outList[it3].val!=outList[it2].val)
			{
				printf("%d %d\n",outList[it2].val,outList[it3].ofs-outList[it2].ofs);
				it2=it3;
				it3++;
			}
			else
			{
				it3++;
			}
		}
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}
