#include<iostream>
#include<algorithm>
#include"stdio.h"
using namespace std;
int carray[100001];
//int digitlength[100001];
int letter[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
char *temp=new char[50];
int main()
{
         int num;
         scanf("%d/n", &num);            //read enter  
         int i;
         //char temp;
         for(i=0;i<num;i++)
         {
                   //char*temp=new char[50]              将这一步放在main外面，时间减了700MS!!!!
                   gets(temp);
                   int pt=0,j=0;
                   char ch;
                   ch=temp[pt++];
                   //bool nonzerofind=0;
                   while(ch!='/0')
                   {
                            if(ch!='-') 
                            {
                                     if(ch>='A'&&ch<='Z')
                                     {       
                                               carray[i] = carray[i]*10+letter[ch-'A'];
                                              
                                     }       
                                     else
                                     {
                                               carray[i]=carray[i]*10+ch-'0';
                                     }
                            }
                            ch=temp[pt++];
                   }       
         }
         sort(carray,carray+num);
         int count=1;
         bool dup=0;
         for(i=1;i<num;i++)
         {
                   if(carray[i]==carray[i-1])  count++;
                   else
                   {
                            if(count>1)
                            {
 
                                     printf("%03d-%04d %d/n", carray[i-1]/10000, carray[i-1]%10000, count); 
                                     dup=1;
                            }
                            count=1;
                   }       
         }
         if(count>1)       
         {
 
                   printf("%03d-%04d %d/n", carray[i-1]/10000, carray[i-1]%10000, count); 
                   dup=1;
        
         }
         if(dup==0)         cout<<"No duplicates."<<endl;
         return 0;
}
