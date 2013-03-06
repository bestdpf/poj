#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"stdbool.h"
//#define MAX 100000
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
//#define bool _Bool 
//#define true 1
//#define false 0
typedef struct nodeD
{
	char str[8];
	int count;
} node;
/*
//recusive version
int binSearch(node* nVec,int left,int right,node nd)
{
	if (left>right)return -1;
	int mid=(left+right)/2;
	if(nVec[mid].str<nd.str)return binSearch(nVec,mid+1,right,nd);
	else if(nVec[mid].str>nd.str)return binSearch(nVec,left,mid-1);
	else return mid;
}
//direct version
int binSearch2(node* nVec,int left,int right,node nd)
{
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(nVec[mid].str<nd.str)left=mid+1;
		else if(nVec[mid].str>nd.str)right=mid-1;
		else return mid;
	}
	return -1;
}
*/
//include left, but not include right
bool binInsert(vector<node>& nVec,node nd)
{
	//printf("binInsert start: %d\n\n\n");
	vector<node>::iterator left=nVec.begin();
	vector<node>::iterator right=nVec.end();
	vector<node>::iterator mid;
	vector<node>::iterator right_back=right;
	while(left<=right)
	{
		//printf("left: %d right: %d\n",left,right);
		mid=left+(right-left)/2;
		//printf("mid.str vs. nd.str: %s  vs %s\n",nVec[mid].str,nd.str);
		if(mid==right_back)break;
		if(atoi(mid->str)<atoi(nd.str))
		{
			left=mid+1;
		//	printf("nd.str i bigger\n");
		}
		else if(atoi(mid->str)>atoi(nd.str))
		{
			right=mid-1;
		//	printf("nd.str is little\n");
		}
		else
		{
		//	printf("success! mid=%d\n",mid);
			mid->count++;
			return true;
		}
	}
	/*
	int i;
	for(i=right_back;i>mid;i--)
	{
		nVec[i]=nVec[i-1];
	}
	nVec[mid]=nd;
	*/
	nVec.insert(mid,nd);
	//printf("fail! mid=%d\n",mid);
	return false;
}

node createNode(char* str)
{
	node ret;
	strcpy(ret.str,str);
	//ret.str=str;
	ret.count=1;
	return ret;
}
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
void printStr(char*str)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		printf("%c",str[i]);
		if(i==2)printf("%c",'-');
	}	
	return;
}
int main(int argc,char* argv[])
{
	int n;
	scanf("%d",&n);
	int i;
	char s[100];
	char tmp[8];
	vector<node> nodeVec;
	//node nullNode;
	//nullNode.count=0;
	//nullNode.str[0]='\0';
	
	//int num=0;
	for(i=0;i<n;i++)
	{	//nodeVec[i]=nullNode;
		scanf("%s",s);
		int j,k;
		for(j=0,k=0;j<strlen(s);j++)
		{
			if(s[j]>='A'&&s[j]<='Z')
			{
				tmp[k]=char2int(s[j])+'0';
				k++;
			}
			else if(s[j]>='0'&&s[j]<='9')
				{
					tmp[k]=s[j];
					k++;
				}
			else continue;
		}
		node nd=createNode(tmp);
		//if(!binInsert(nodeVec,0,num,nd))num++;
		binInsert(nodeVec,nd);
		/*
		printf("input is \n %s %d\n",nd.str,nd.count);
		//dump /doeVec
		int l;
		printf("dump nodeVec\n\n");
		for(l=0;l<num;l++)
		{
			printf("nodeVec[%d] %s %d\n",l,nodeVec[l].str,nodeVec[l].count);
		}
		*/
	}
	bool has=false;
	//if(num==0)printf("No duplicates.\n");
	//else
	//{
	vector<node>::iterator it;
		for(it=nodeVec.begin();it!=nodeVec.end();it++)
		{
			//printf("test i %d\n",i);
			if(it->count>1)
			{
				has=true;
				printStr(it->str);
				printf(" %d\n",it->count);
			}
		}
	//}
	if(has==false)printf("No duplicates.\n");
	return 0;
}
