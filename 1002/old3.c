#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MAX 100002
#define bool int
#define true 1
#define false 0
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
bool binInsert(node* nVec,int left, int right,node nd)
{
	//printf("binInsert start: %d\n\n\n");
	int mid;
	int pos=0;
	int right_back=right;
	while(left<=right)
	{
		if(left==right)
		{
			if(right_back==right)//init situation
			{
				//printf("goto end\n");
				pos=right_back;//go to invad pos (right_back)
				break;
			}
			if(atoi(nVec[left].str)<atoi(nd.str))
			{
				//printf("equal nd big pos: %d\n",left+1);
				pos=left+1;
				break;
			}
			else if(atoi(nVec[left].str)==atoi(nd.str))
			{
				//printf("equal an equal \n");
				nVec[left].count++;
				return true;
			}
			else
			{
			//	//printf("equal little pos: %d",left);
				pos=left;
				break;
			}		
		}
		else
		{
		//printf("left: %d right: %d\n",left,right);
		mid=(left+right)/2;
		//printf("mid.str vs. nd.str: %s  vs %s\n",nVec[mid].str,nd.str);
		//if(strlen(nVec[mid].str)==0)break;
		if(atoi(nVec[mid].str)<atoi(nd.str))
		{
			left=mid+1;
		//	pos=left;
		//	printf("nd.str i bigger\n");
		}
		else if(atoi(nVec[mid].str)>atoi(nd.str))
		{
			right=mid;
		//	pos=right;
		//	printf("nd.str is little\n");
		}
		else
		{
		//	printf("success! mid=%d\n",mid);
			nVec[mid].count++;
			return true;
		}
	}
	}
	//if(pos<0)pos=0;
	int i;
	for(i=right_back;i>pos;i--)
	{
		nVec[i]=nVec[i-1];
	}
	nVec[pos]=nd;
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
		if(i==2)printf("-");
	}	
	return;
}
int main(int argc,char* argv[])
{
	int n;
	scanf("%d",&n);
	int i;
	char s[128];
	char tmp[8];
	node nodeVec[MAX];
	int num=0;
	node nd;
	nd.count=1;
	for(i=0;i<n;i++)
	{
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
		strcpy(nd.str,tmp);
		if(!binInsert(nodeVec,0,num,nd))num++;
		/*
		//dump node
		printf("\n\n\n");
		int q;
		for(q=0;q<num;q++)
		{
			printf("%s %d\n",nodeVec[q].str,nodeVec[q].count);		
		}
		*/
	}
		/*
	printf("final\n\n\n");
		*/
	bool has=false;
	//if(num==0)printf("No duplicates.\n");
	//else
	//{
		for(i=0;i<num;i++)
		{
			//printf("test i %d\n",i);
			if(nodeVec[i].count>1)
			{
				has=true;
				printStr(nodeVec[i].str);
				printf(" %d\n",nodeVec[i].count);
			}
		}
	//}
	if(has==false)printf("No duplicates.\n");
	return 0;
}
