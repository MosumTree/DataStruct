/*有一个奇怪的国家，里面的国民对于事情的态度永远只有两面。当两个人遇到一起讨
论一个事情的时候——两个持赞同观点的人遇到一起后会对这个事情都继续赞同；一个持
赞同观点的人遇到一个持不赞同观点的人的时候，两人都会不再继续赞同；两个持不赞
同观点的人遇到一起讨论后反而会对这个事情开始赞同。
输入包括两行，每行包括N个数字（1≤N≤50），分别表示两个人对于N个事情对应的看
法——0表示不赞同、1表示赞同。
输出包括一行，包括N个数字，表示两人相遇后，对于这N件事情的最终看法。*/
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string a,b;
	int a0,b0;
	cin>>a>>b;
	int n=a.size();
	int c[n]={};
	for (int i = 0; i < n; ++i)
	{
        a0=(int)(a[i]-'0');
        b0=(int)(b[i]-'0');
		if (a0==b0)
		{
			c[i]=1;
		}
		else
			c[i]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<c[i];
	}
	return 0;
}