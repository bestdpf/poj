#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main(int argc,char*argv[])
{
	set<int> a;
	a.insert(1);
	a.insert(1);
	cout<<a.count(1)<<endl;
	return 0;
}
