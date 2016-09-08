#include <stdio.h> 
#include <string>
#include <iostream>
#include <vector>
#define HASH_TABLE_SIZE 101 // 哈希表的大小应是个质数 
using namespace std;
int a[10000000000];
bool StringContain(string &a,string &b)
{
	int hash = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		hash |= (1 << (a[i] - 'A'));
	}
	if (a.length()==b.length())
	{
		for (int i = 0; i < b.length(); ++i)
		{
			if ((hash & (1 << (b[i] - 'A'))) == 0)
			{
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
	return false;

}

int main () 
{ 
	int num;
	cin>>num;
	string *str=new string[num];
	int *number=new int[num];
	for (int i = 0; i < num; ++i)
	{
		number[i]=0;
	}
	std::vector<string> v;
	vector<int> n;
	for (int i = 0; i < num; ++i)
	{
		cin>>str[i];
		if(i==0){
			v.push_back(str[i]);
			n.push_back(0);
			continue;
		}
		for (int j = 0; j <v.size(); ++j)
		{
			if(StringContain(str[i],v[j])){
				n[j]+=1;
				number[i]=n[j];
				break;
			}
			if (j==v.size()-1)
			{
				v.push_back(str[i]);
				n.push_back(0);
				number[i]=0;
				break;
			}		
		}
	}
	for (int i = 0; i < num; ++i)
	{
		cout<<number[i]<<endl;	
	}


} 