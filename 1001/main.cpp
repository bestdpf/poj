#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define LEN 500 
#define MAX 10000
//bigNum struct
typedef struct bigNumD{
	int num[LEN];
	int pos;//point position
	int len;//bit num
}bigNum;
//declaration
bigNum product(bigNum a,int b);
bigNum initNum(bigNum a);
bigNum str2bigNum(char* str);
bigNum product(bigNum a,bigNum b);
bigNum add(bigNum a,bigNum b);
bigNum normalize(bigNum c);
bigNum shiftL(bigNum a, int n);
bigNum moveL(bigNum a, int n);
void dumpNum(bigNum a);
bigNum delHeadZero(bigNum a);
//init bigNum
bigNum initNum(bigNum a)
{
	int i;
	for(i=0;i<LEN;i++)
	{
		a.num[i]=0;
	}
	a.pos=0;
	a.len=0;
	return a;
}
//str2bigNum
bigNum str2bigNum(char* str )
{
	bigNum a;
	a=initNum(a);
	a.len=strlen(str);	
	char tmp;
	int i;
	bool hasPoint=false;
	for(i=0;i<strlen(str);i++)
	{
		tmp=str[i];
		if(tmp=='.')
		{
		hasPoint=true;
		a.len--;
		a.pos=i-1;
		}
		else
		{
			a.num[i]=tmp-'0';
		}
	}
	if(hasPoint)//remove the point
	{
		for(i=a.pos+1;i<a.len+1;i++)a.num[i]=a.num[i+1];
		a.num[a.len+1]=0;
	}
	else
	{//no point pos is just the length-1
	a.pos=a.len-1;
	}
	//a.len=a.len<a.pos?a.len:a.pos;//a.len=max()
	//printf("%d %d \n",a.pos,a.len);
	return normalize(a);
}

bigNum product(bigNum a, bigNum b)
{
	a=normalize(a);
	b=normalize(b);
	int i;
	bigNum c;
	c=product(a,b.num[0]);
	for(i=1;i<b.len;i++)
	{
		c=shiftL(c,1);
		c=add(c,product(a,b.num[i]));
	}
	//c.len-=b.len-1-b.pos;
	c.pos-=b.len-1-b.pos;
	c=normalize(c);
	return c;
}

bigNum delHeadZero(bigNum a)
{
	int headNull=0;
	while(a.num[headNull]==0&&headNull<=a.pos)headNull++;
	int i;
	if(headNull>0)
	{
		a.len-=headNull;
		a.pos-=headNull;
		for(i=0;i<a.len;i++)
		{
			a.num[i]=a.num[i+headNull];
		}
	}
	if(a.pos<0)//add zeros head
	{
		a=moveL(a,-a.pos);
	}
	return a;
}
bigNum add(bigNum a,bigNum b)
{
	a=normalize(a);
	b=normalize(b);
	bigNum c;
	c=initNum(c);
	bigNum leftMin=a.pos<b.pos?a:b;
	bigNum leftMax=a.pos<b.pos?b:a;
	bigNum rightMin=(a.len-a.pos)<(b.len-b.pos)?a:b;	
	bigNum rightMax=(a.len-a.pos)<(b.len-b.pos)?b:a;
	c.pos=leftMax.pos;
	c.len=leftMax.pos+rightMax.len-rightMax.pos;
	int i,j;
	for(i=leftMin.pos,j=leftMax.pos;i>=0;i--,j--)
	{
		c.num[j]=leftMax.num[j]+leftMin.num[i];
	}
	for(i=0;i<leftMax.pos-leftMin.pos;i++)//copy the left left ones;
	{
		c.num[i]=leftMax.num[i];
	}
	for(i=leftMax.pos+1,j=leftMin.pos+1;i<leftMax.pos+rightMin.len-rightMin.pos;i++,j++)
	{
		c.num[i]=leftMax.num[i]+leftMin.num[j];
	}
	for(;i<leftMax.pos+rightMax.len-rightMax.pos;i++)//copy the right left ones
	{
		c.num[i]=rightMax.num[i];
	}
	//check if bigger than 9
	//printf("result before normalize len: %d pos: %d\t",c.len,c.pos);
	//dumpNum(c);
	//printf("\n");
	c=normalize(c);
	//printf("test add input a.len: %d a.pos %d b.len %d b.pos %d\n",a.len,a.pos,b.len,b.pos);
	//dumpNum(a);
	//printf("\t");
	//dumpNum(b);
	//printf("result len: %d  pos: %d  is: ",c.len,c.pos);
	//dumpNum(c);
	//printf("\n");
	return c;	
}

bigNum normalize(bigNum c)
{
	int i;
	for(i=c.len-1;i>0;i--)//change the bad value to the first bit
        {
                if(c.num[i]>9)
                {
                        c.num[i-1]+=c.num[i]/10;
                        c.num[i]%=10;
                }
        }
	while(c.num[0]>9)
	{
		c=moveL(c,1);
		c.num[0]=c.num[1]/10;
		c.num[1]%=10;
	}
	c=delHeadZero(c);
        return c;     
}

bigNum product(bigNum a, int b)
{	a=normalize(a);
	int i;
	for(i=0;i<a.len;i++)
	{
	a.num[i]*=b;
	}
	a=normalize(a);
	/*
	while(a.num[i]>=10)
	{
		a=moveL(a,1);
		a.num[i]+=a.num[i+1]/10;
		a.num[i+1]%=10;
	}*/
	return a;
	/*
	for(;i>=0;i--)
	{
		if(a.num[i]>10)
		{
		
		a.num[i]/=10;
	
		a.num[i-1]
		}
		
	}
	*/
}
//add n zero bits at the end , the value is  changed 
bigNum shiftL(bigNum a,int n)
{
	a.len+=n;
	a.pos+=n;
	a=normalize(a);
	return a;
}
//also shift, but value is not changed! 
bigNum moveL(bigNum a,int n)
{
	int i;
	for(i=a.len-1;i>=0;i--)
	{
		a.num[i+n]=a.num[i];
	}
	for(i=0;i<n;i++)
	{
		a.num[i]=0;
	}
	a.len+=n;
	a.pos+=n;
	return a;
}
void dumpNum(bigNum a)
{
	
//	printf("no analysis: pos %d len %d ",a.pos,a.len);
	if(a.pos>a.len-1)
	{//add zeros at end 
		a.len=a.pos+1;
	}
	else if(a.pos<0)
		{//add zeros at head
		a=moveL(a,-a.pos);	
		}	
	int headNull=0;
	int i;
//	for(i=0;i<a.len;i++)printf("%d",a.num[i]);
//	printf("\n");
	for(i=0;i<=a.pos;i++)
	{
		if(a.num[i]==0)headNull++;
		else break;
	}
	
	/*
	bool headZero=true;
	int i;
	for(i=0;i<=a.pos;i++)
	{
		if(a.num[i]!=0)
		{
			headZero=false;
			break;
		}
		//for(;i<a.len;i++)printf(".%d",a.num[i]);
	}
	*/
	int endShort=0;
	if(a.pos<a.len)
	{
		endShort=0;
		int j=a.len;
		while(a.num[--j]==0&&j>a.pos)endShort++;
	}
		int start=headNull;
		//if(start>a.pos&&a.pos<a.len-1)printf(".");//0000.xxx method
	//	printf("start %d,a.len %d, endShort %d\n",start,a.len,endShort);
		for(i=start;i<a.len-endShort;i++)
		{
			if(i==a.pos+1)printf(".");
			printf("%d",a.num[i]);
		}
}

int main(int argc,char* argv[])
{
	char s[100];
	int n;
	bigNum a;
	a=initNum(a);
	bigNum c;
	while(scanf("%s%d",s,&n)!=EOF)
	{
		a=str2bigNum(s);
		c=a;
		/*
		//printf("a.len %d a.pos %d\n",a.len, a.pos);
		dumpNum(a);
		printf("\t");
		dumpNum(a);
		*/
		//printf("test n: %d \n",n);
		for(;n>1;n--)a=product(a,c);
		//printf("orginal is : ");
		dumpNum(a);
		printf("\n");
	}
	
	return 0;
}
