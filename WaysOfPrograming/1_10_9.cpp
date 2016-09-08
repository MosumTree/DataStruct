#include <iostream>
#include <string.h>
using namespace std;
// char *str = "AbcABca";
// 写出一个函数，查找出每个字符的个数，区分大小写，要求时间复杂度是n（提示用ASCII码）
//65~90:A~Z    97~122:a~z
void number(char* a,int n){//本函数时间复杂度3n，应该算是O(n)
int b[52]={};
for (int i = 0; i < 52; ++i)
{
	b[i]=0;
}
for (int i = 0; i < n; ++i)
{
	if ((int)a[i]<=90&&(int)a[i]>=65)
	{
		b[(int)a[i]-65]++;
	}
	if ((int)a[i]<=122&&(int)a[i]>=97)
	{
		b[(int)a[i]-71]++;
	}
}
for (int i = 0; i < 52; ++i)
{
	if (b[i]!=0&&i>=0&&i<=25)
	{
		cout<<(char)(i+65)<<":"<<b[i]<<endl;
	}
	if (b[i]!=0&&i>=26&&i<=51)
	{
		cout<<(char)(i+71)<<":"<<b[i]<<endl;
	}
}
}
int main(int argc, char const *argv[])
{
	char *c="AbcABcaasKVuuyfyRRTCyoKn";
	cout<<strlen(c)<<endl;
	number(c,strlen(c));
	return 0;
}