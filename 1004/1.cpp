#include"iostream"
#include"iomanip"
using namespace std;
int n=12;

int main(int argc,char*argv[])
{
	int i;
	long long int sum=0;
	double tmp;
	long long int d;
	for(i=0;i<n;i++)
	{
		cin>>tmp;
		d=int(tmp*100+0.000001);
		sum+=d;	
	}
	sum/=12;
	cout<<"$"<<sum/100<<"."<<sum%100<<endl;
	return 0;
}
