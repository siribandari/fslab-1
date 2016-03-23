//============================================================================
// Name        : cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>00
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
class coseq
{
public:
	string l1[100],l2[100];
    int count1,count2;
    void load();
    void sort();
    void match();
};
void coseq::load()
{
	fstream fp1,fp2;
	string name;
	int i;
	count1=-1;
	count2=-1;
	fp1.open("/home/batch-b2/file1.txt",ios::in);
	cout<<fp1;
	if(!fp1)
	cout<<"file cannot be  opened\n";
	while(fp1)
	{
		name.erase();
		getline(fp1,name);
		l1[++count1]=name;
	}
	fp1.close();
	cout<<"name in first file\n";
	for(i=0;i<count1;i++)
	{
		cout<<l1[i]<<"\n";
	}
	fp2.open("file2.txt",ios::in);
	while(fp2)
	{
	name.erase();
	getline(fp2,name);
	l2[++count2]=name;
	}
	fp2.close();
	cout<<"name in second file\n";
	for(i=0;i<count2;i++)
	{
	cout<<l2[i]<<"\n";
	}
}
void coseq::sort()
{
	int i,j;
	string temp;
	for(i=0;i<=count1;i++)
	{
		for(j=0;j<=count1;j++)
		{
			if(l1[i]>l1[j])
		{
			temp=l1[i];
			l1[i]=l1[j];
			l1[j]=temp;
		}
	}
}
	for(i=0;i<=count2;i++)
		{
			for(j=0;j<=count2;j++)
			{
				if(l2[i]>l2[j])
			{
				temp=l2[i];
				l2[i]=l2[j];
				l2[j]=temp;

			}
			}
		}
	cout<<"\n after sorting name of 1st file";
	cout<<l1[i]<<"\n";
	for(i=0;i<=count2;i++)
		cout<<l1[i]<<"\n";
}
void coseq::match()
{
	int i=0,j=0;

	while(i<=count1 && j<=count2)
	{
	if(l1[i]==l2[j])
	{
		cout<<l1[i]<<"\n";
		i++;
		j++;
	}
	if(l1[i]<l2[j])
	i++;
	if(l1[i]>l2[j])
	j++;
	}
}
int main()
{
	coseq c;
	c.load();
	c.sort();
	cout<<"comon names are\n";
	c.match();
	return 0;
}
