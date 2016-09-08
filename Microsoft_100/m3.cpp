#include <iostream>
using namespace std;
/*
求子数组的最大和（数组）
输入一个整形数组，数组里有正数也有负数。
数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
求所有子数组的和的最大值。要求时间复杂度为 O(n)。
例如输入的数组为 1, -2, 3, 10, -4, 7, 2, -5，和最大的子数组为 3, 10, -4, 7, 2，
因此输出为该子数组的和 18。
*/
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>m;
		a[i] = m;
	}
	int currentsum=0;
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		if ((currentsum+a[i]) < a[i])
		{
			currentsum=a[i];
			if (currentsum>max)
			{
				max=currentsum;
			}
		}
		else{
			currentsum+=a[i];
			if (currentsum>max)
			{
				max=currentsum;
			}
		}
	}
	cout<<"The sum of max subarray is:"<<max<<endl;
	return 0;
}