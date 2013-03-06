#include<iostream>
#include<list>
#include<iterator>
using namespace std;
typedef struct nodeD{
	int a;
}node;
int main()
{
	list<node> vec;
	node x1,x2,x3;
	x1.a=1;
	x2.a=2;
	x3.a=3;
	vec.push_back(x1);
	vec.push_back(x2);
	vec.push_back(x3);
	list<node>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
	{
		it->a++;
	}
	list<node>::iterator it2;
	for(it2=vec.begin();it2!=vec.end();it2++)
	{
		cout<<it2->a<<endl;
	}
	
	return 0;
}
