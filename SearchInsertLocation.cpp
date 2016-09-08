#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,target;
	cin>>n;
	int*a=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cin>>target;
	for (int i = 0; i < n; ++i)
	{
		if (target<=a[i])
		{
			cout<<i<<endl;
			break;
		}
		if(i==n-1){
			cout<<i+1<<endl;
		}
	}
	return 0;
}