#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int N=1005;
int n;

int p1,p2;//as the input.

#define pr pair<int,int>

struct{
	int floors;
	//0 means just one floor;
	//1 or more means more than one floor in the same number;
	deque<pr> list;
}info[N*3];

struct{
	int floors;
	//0 means just one floor;
	//1 or more means more than one floor in the same number;
	deque<pr> list;
}ans[N*3];

deque<pr> tmpanstop;
deque<pr> tmpansmid;
deque<pr> tmpansbot;
deque<pr> zero;
int i;

deque<pr> combine(deque<pr> a,deque<pr> b){//combine b to a
	static deque<pr> ret;
	static pr tmp;
	int i0=-1,i1=-1,ip0=0,ip1=0;
	ret.clear();
	while(1){
		if(0==ip0){
			i0++;
			if(i0>=a.size())break;
			ip0=a[i0].second;
		}else if(0==ip1){
			i1++;
			if(i1>=b.size())break;
			ip1=b[i1].second;
		}else{
			tmp.first=max(a[i0].first,b[i1].first);
			tmp.second=min(ip0,ip1);
			ip0-=tmp.second;ip1-=tmp.second;
			ret.push_back(tmp);
		}
	}
	return ret;
}

deque<pr> compare1(int sft,int i,int pushzero){
	//push:1 to add a zero at the front, and -1 to add a zero at the end
	deque<pr> ret;
	pr tmp;
	int m;
	//compare info i with info i-1
	if(sft==-1)
		info[i].list[0].second--;
	else if(sft==1){
		info[i-1].list[0].second--;
	}

	int i0=-1,i1=-1,ip0=0,ip1=0;
	while(1){
		if(0==ip0){
			i0++;
			if(i0>=(int)info[i-1].list.size())
				break;
			ip0=info[i-1].list[i0].second;
		}else if(0==ip1){
			i1++;
			if(i1>=(int)info[i].list.size())
				break;
			ip1=info[i].list[i1].second;
		}else{
			m=min(ip0,ip1);
			ip0-=m;ip1-=m;
			tmp.first=abs(info[i-1].list[i0].first-info[i].list[i1].first);
			tmp.second=m;
			ret.push_back(tmp);
		}
	}

	if(pushzero>0){
		tmp.first=0;tmp.second=1;
		ret.push_front(tmp);
	}else if(pushzero<0){
		tmp.first=0;tmp.second=1;
		ret.push_back(tmp);
	}

	if(sft==-1)
		info[i].list[0].second++;
	else if(sft==1)
		info[i-1].list[0].second++;

	return ret;
}

deque<pr> compare2(int i){
	static pr tmp;
	deque<pr> ret1,ret2;
	for(int j=0;j<info[i].list.size();j++){
		if(j==0)
			tmp.first=0,tmp.second=info[i].list[j].second,ret1.push_back(tmp);
		else{
			tmp.first=abs(info[i].list[j].first-info[i].list[j-1].first),tmp.second=1,ret1.push_back(tmp);
			tmp.first=0,tmp.second=info[i].list[j].second-1;
			ret1.push_back(tmp);
		}
	}
	ret2=ret1;
	ret2.front().second--;
	ret2.back().second++;
	ret1=combine(ret1,ret2);

	return ret1;
}

int main(){
	int width;
	int indexinfo=-1;
	int indexans=0;
	int j;

	while(1){
		scanf("%d",&width);
		printf("%d\n",width);
		if(width==0)
			break;
		indexinfo=-1;
		indexans=0;
		pr tmp;

		int nowpos=width;

		tmp.first=0;tmp.second=width;
		zero.clear();zero.push_back(tmp);

		while(1){
			scanf("%d%d",&p1,&p2);
			if(p1==p2&&p2==0)
				break;

			while(p2!=0){
				if(nowpos==width){
					nowpos=0;
					indexinfo++;
					info[indexinfo].floors=p2/width;
					info[indexinfo].list.clear();
					if(p2>=width){
						//we can store more than 1 floor in an struct info.
						tmp.first=p1;
						tmp.second=width;
						info[indexinfo].list.push_back(tmp);
						p2%=width;
						nowpos=width;
					}else{
						tmp.first=p1;
						tmp.second=p2;
						info[indexinfo].list.push_back(tmp);
						nowpos+=p2;
						p2=0;
					}
				}else{
					if(nowpos+p2>width){
						tmp.first=p1;
						tmp.second=width-nowpos;
						p2-=width-nowpos;
						nowpos=width;
						info[indexinfo].list.push_back(tmp);
					}else{
						tmp.first=p1;
						tmp.second=p2;
						nowpos+=p2;
						p2=0;
						info[indexinfo].list.push_back(tmp);
					}
				}
			}
		}//Input finished

		for(i=0;i<=indexinfo;i++){
			if(i==0)
				tmpanstop=zero;
			else{
				tmpanstop=compare1(-1,i,1);
				tmpanstop=combine(compare1(0,i,0),tmpanstop);
				tmpanstop=combine(compare1(1,i,-1),tmpanstop);
			}

			if(info[i].floors){
				tmpansmid=zero;
			}else{
				tmpansmid=compare2(i);
			}

			if(i==indexinfo)
				tmpansbot=zero;
			else{
				tmpansbot=compare1(-1,i+1,-1);
				tmpansbot=combine(compare1(0,i+1,0),tmpansbot);
				tmpansbot=combine(compare1(1,i+1,1),tmpansbot);
			}

			if(info[i].floors<=1){
				tmpansbot=combine(tmpansbot,tmpansmid);
				tmpansbot=combine(tmpansbot,tmpanstop);
				ans[indexans].floors=0;
				ans[indexans].list=tmpansbot;
				indexans++;
			}else{
				ans[indexans].floors=0;
				ans[indexans].list=tmpanstop;
				indexans++;

				if(info[i].floors>2){
					ans[indexans].floors=info[i].floors-2;
					ans[indexans].list=zero;
					indexans++;
				}

				ans[indexans].floors=0;
				ans[indexans].list=tmpansbot;
				indexans++;
			}
		}

		tmp.first=ans[0].list[0].first;
		tmp.second=0;

		for(i=0;i<indexans;i++){
			if((tmp.first!=ans[i].list[0].first)&&(tmp.second!=0)){
				printf("%d %d\n",tmp.first,tmp.second);
				tmp.second=0;
			}

				if(ans[i].floors>=1){
					tmp.first=ans[i].list[0].first;
					tmp.second+=ans[i].floors*width;
				}else{
					for(j=0;j<ans[i].list.size();j++){
						if((tmp.first!=ans[i].list[j].first)&&(tmp.second!=0)){
							printf("%d %d\n",tmp.first,tmp.second);
							tmp.second=0;
						}
						tmp.first=ans[i].list[j].first;
						tmp.second+=ans[i].list[j].second;
					}
				}
		}
		if(tmp.second>0)
			printf("%d %d\n",tmp.first,tmp.second);
		printf("%d %d\n",0,0);
	}
	return 0;
}
