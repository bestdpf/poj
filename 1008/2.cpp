#include"stdio.h"
#include<string>
#include<map>
using namespace std;

int HMonth2num(string str)
{
	map<string,int>tab;
	tab["pop"]=0;
	tab["no"]=1;
	tab["zip"]=2;
	tab["zotz"]=3;
	tab["tzec"]=4;
	tab["xul"]=5;
	tab["yoxkin"]=6;
	tab["mol"]=7;
	tab["chen"]=8;
	tab["yax"]=9;
	tab["zac"]=10;
	tab["ceh"]=11;
	tab["mac"]=12;
	tab["kankin"]=13;
	tab["muan"]=14;
	tab["pax"]=15;
	tab["koyab"]=16;
	tab["cumhu"]=17;
	tab["uayet"]=18;
	return tab[str];
/*	
	switch(str)
	{
	case "pop": return 0;
	case "no" : return 1;
	case "zip": return 2;
	case "zotz": return 3;
	case "tzec": return 4;
	case "xul": return 5;
	case "yoxkin": return 6;
	case "mol": return 7;
	case "chen": return 8;
	case "yax": return 9;
	case "zac": return 10;
	case "ceh" : return 11;
	case "mac" : return 12;
	case "kankin" : return 13;
	case "muan" : return 14;
	case "pax" : return 15;
	case "koyab" : return 16;
	case "cumhu" : return 17;
	case "uayet" : return 18;
	default: return -1;
	}
*/
}
string TNum2str (int day)
{
	switch(day)
	{
	case 0: return string("imix");
	case 1: return string("ik");
	case 2: return string("akbal");
	case 3: return string("kan");
	case 4: return string("chicchan");
	case 5: return string("cimi");
	case 6: return string("manik");
	case 7: return string("lamat");
	case 8: return string("muluk");
	case 9: return string("ok");
	case 10: return string("chuen");
	case 11: return string("eb");
	case 12: return string("ben");
	case 13: return string("ix");
	case 14: return string("mem");
	case 15: return string("cib");
	case 16: return string("caban");
	case 17: return string("eznab");
	case 18: return string("canac");
	case 19: return string("ahau");
	}
}
int main(int argc,char* argv[])
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	int i;
	int day,yr;
	string HMonth;
	int TDay;
	int Tyr;
	string TDayStr;
	int count,HMonthNum;
	char tmp[10];
	for(i=0;i<n;i++)
	{
		scanf("%d. %s %d",&day,tmp,&yr);
		HMonth=string(tmp);
		HMonthNum=HMonth2num(HMonth);
		count=yr*365+20*HMonthNum+day;
		TDay=count%13+1;
		Tyr=count/260;
		TDayStr=TNum2str(count%20);
		printf("%d %s %d\n",TDay,TDayStr.c_str(),Tyr);
	}
	return 0;
}
