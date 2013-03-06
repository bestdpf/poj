#include<iostream>
#include<algorithm>
#include<functional>
//#include"bits/hashtable.h"
#include<tr1_impl/hashtable>
#include<string>
using namespace stdext;
using namespace std;

int main(int argc,char*argv[])
{
	hash<char*>H;
	string a="haha";
	cout<<H(a)<<endl;
	return 0;
}
