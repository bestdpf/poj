#include"stdio.h"
#include"stdlib.h"
#include"string.h"
//#include"stdbool.h"
#define bool int
#define true 1
#define false 0
#define MAX 100002
typedef struct nodeD
{
	char str[8];
	int count;
} node;
node nodeVec[MAX];
//include left, but not include right
bool binInsert(node* nVec,int left, int right,node nd)
{
	//printf("binInsert start: %d\n\n\n");
	int mid=0;
	int right_back=right;
	while(left<right)
	{
		//printf("left: %d right: %d\n",left,right);
		mid=(left+right)/2;
		//printf("mid.str vs. nd.str: %s  vs %s\n",nVec[mid].str,nd.str);
		
		if(atoi(nVec[mid].str)<atoi(nd.str))
		{
			left=mid+1;
		//	printf("nd.str i bigger\n");
		}
		else if(atoi(nVec[mid].str)>atoi(nd.str))
		{
			right=mid;
		//	printf("nd.str is little\n");
		}
		else
		{
		//	printf("success! mid=%d\n",mid);
			nVec[mid].count++;
			return true;
		}
	}
	int i;
	for(i=right_back;i>left;i--)
	{
		nVec[i]=nVec[i-1];
	}
	nVec[left]=nd;
	//printf("fail! mid=%d\n",mid);
	return false;
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
	char s[100];
	char tmp[8];
	//node nodeVec[MAX];
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
	}
	bool has=false;

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

	if(has==false)printf("No duplicates.\n");
	return 0;
}
