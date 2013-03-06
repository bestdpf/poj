//#include<iostream>
#include"stdio.h"
#include"time.h"
#include<iterator>
#include<map>
#include<vector>
#include<string>
//#include<hash_map>
//#include<cstring>
#include<algorithm>
#include<utility>
#include<list>
#include"string.h"
char s[100];
char sd[8];
//string tmp;
using namespace std;

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

void printStr(const char* s)
{
	unsigned int i;
	for(i=0;i<strlen(s);i++)
	{
		printf("%c",s[i]);
		if(i==2)printf("-");
	}
	return;
}

int main(int argc,char* argv[])
{
	long time1=clock();
	//map<string,int> retMap;	
	//vector<string,int>retVec;
	list<pair<string,int> >retList;
	list<pair<string,int> > finalVec;
	//int full=0;
	int n;
	scanf("%d",&n);
	int i;
	string tmp;
//	char s[100];
//	char sd[8];	
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		int j;
		int count=0;
		for(j=0;j<strlen(s);j++)
		{
			if(s[j]>='A'&&s[j]<='Z')s[j]=char2int(s[j])+'0';
			if(s[j]!='-')sd[count++]=s[j];
		}
		tmp=string(sd);
		//printf("%s\n",tmp.c_str());
		//printf(retMap.find(tmp)==retMap.end()?"fail\n":"success\n");
		list<pair<string,int> >::iterator lstit;
		for(lstit=retList.begin();lstit!=retList.end();lstit++)
		{
			if(lstit->first==tmp)
			{
				lstit->second++;
				break;
			}
		}
		if(lstit==retList.end())retList.push_back(make_pair(tmp,1));
		//if(retMap.find(tmp)==retMap.end())
		//{
		//	retMap.insert(make_pair<string,int>(tmp,1));
		//}
		//else retMap[tmp]++;
	}
	long time2=clock();
	//map<string,int>finalMap;
	list<pair<string,int> >::iterator it;
	for(it=retList.begin();it!=retList.end();it++)
	{
		//printStr(it->first.c_str());
		//printf(" %d\n\n\n",it->second);
		if(it->second>1)
		{
		finalVec.push_back(*it);
		//full++;
		}
	}
	long time3=clock();
	list<pair<string,int> >::iterator it2;
//	make_heap(finalVec.begin(),finalVec.end());
	//sort(finalVec.begin(),finalVec.end());
	finalVec.sort();
	//vector<string>::iterator it2;
	if(finalVec.size()==0)printf("No duplicates.\n");
	else	
	{
		for(it2=finalVec.begin();it2!=finalVec.end();it2++)
			{
			printStr(it2->first.c_str());
			printf(" %d\n",it2->second);
			}
	}
	long time4=clock();
	printf("%d %d %d %d\n",time1,time2,time3,time4);
	return 0;
}
