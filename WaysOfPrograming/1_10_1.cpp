#include <iostream>
#include <string>
using namespace std;

const int n[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,61, 67, 71, 73, 79, 83, 89, 97,101};

int loc=0;
int c=1;
int maxlength=1;
//在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b
char onlyone(string &a){
	int mult=1;
	for (int i = 0; i<a.length(); ++i)
	{
		mult*=n[(a[i]-'a')];
	}
	for (int i = 0; i<a.length(); ++i)
	{
		if(!(mult%(n[(a[i]-'a')]*n[(a[i]-'a')])==0))
			return a[i];
	}
	return 0;
}
//输入一个字符串，输出该字符串中对称的子字符串的最大长度。比如输入字符串“google”，由于该字符
//串里最长的对称子字符串是“goog”，因此输出4
int longestSymmetrical(string &a){
int max=0;
int c,j;
if (a.length()<1)
{
	return 0;
}
for (int i = 0; i<a.length(); ++i)
{
	for (j = 0; (i-j>=0)&&(j+i<a.length()); ++j)
	{
		if (a[i-j]!=a[i+j])
		{
			break;
		}
		c=2*j+1;
	}
	if (c>max)
	{
		max=c;
	}
	for (j = 0; (i-j>=0)&&(j+i+1<a.length()); ++j)
	{
		if (a[i-j]!=a[i+j+1])
		{
			break;
		}
		c=2*j+2;
	}
	if (c>max)
	{
		max=c;
	}
	
}
return max;
}
//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
void deleteSame(string &a,string &b){
    int mult=1;
	for (int i = 0; i<b.length(); ++i)
	{
		mult*=n[(b[i]-'a')];
	}
	for (int i = 0; i<a.length(); ++i)
	{
		int judge=0;
		if((int)a[i]==0||(int)a[i]==32||(int)a[i]==46){
			continue;
		}
		if (a[i]>=65&&a[i]<=90)
		{
			a[i]+=32;
			judge=1;
		}
		if(mult%(n[(a[i]-'a')])==0){
			for(int m=i;m<a.length()-1;m++)
				a[m]=a[m+1];
			a.erase(a.length()-1,1);
		}
		if (judge==1)
		{
			a[i]-=32;
		}
	}
	cout<<a<<endl;
}
// 用递归算法写一个函数，求字符串最长连续字符的长度，比如aaaabbcc的长度为4，aabb的长度为2，ab
// 的长度为1。
int longestConstant(string &a){
if (loc==a.length()-1)
{
	return  maxlength;
}
if (a[loc]==a[loc+1])
{
	c+=1;
	if (c>maxlength)
	{
		maxlength=c;
	}
	loc++;
	longestConstant(a);
}
else{
	c=1;
	loc++;
	longestConstant(a);
}
}
int main(int argc, char const *argv[])
{
	string a="abaccdebffd";
	string b="googleelg";
	cout<<onlyone(a)<<endl;
	cout<<longestSymmetrical(b)<<endl;
	string c="They are students.";
	string d="aeiou";
	deleteSame(c,d);

	string e="aaaabbccccc";
	cout<<longestConstant(e)<<endl;

}