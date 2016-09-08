#include <iostream>
using namespace std;
/*找出数组中唯一的重复元素
1-1000放在含有1001个元素的数组中，只有唯一的一个元素值重复，其它均只出现一次。
每个数组元素只能访问一次，设计一个算法，将它找出来；不用辅助存储空间，能否设计一个算法实现？*/
//解答：把1001个元素加起来，只要看这个和比1+2+。。。+1001的和少多少，就知道哪个元素被用了两次，我好聪明！

/*一个数组里，数都是两两出现的，但是有三个数是唯一出现的，找出这三个数*/
//解答：对数组排序后从前往后遍历，把一个数与后一个数作比较即可得出3个不重复的数。时间复杂度为O（NlogN）

/*给定一整型数组，若数组中某个下标值大的元素值小于某个下标值比它小的元素值，称这是一个反序。
即：数组a[]; 对于i < j 且 a[i] > a[j],则称这是一个反序。
给定一个数组，要求写一个函数，计算出这个数组里所有反序的个数。*/
void Inversion(int a[],int n){
	int inversionNum=0;
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = i+1; j< n; ++j)
		{
			if (a[i]>a[j])
			{
				inversionNum++;
			}
		}
	}
    cout<<inversionNum<<endl;
}
/*有两个序列A和B,A=(a1,a2,...,ak),B=(b1,b2,...,bk)，A和B都按升序排列。对于1<=i,j<=k，求k个最小
的（ai+bj）。要求算法尽量高效。*/
void sumK(int a[],int b[],int n,int){
int c[k]={0};
int count=0;
int m;
int i=0,j=0;
for (m=0; m*(m+1)/2<k; ++m);
while (i < (m-1)*m&&j<m)
{
	c[i++]=a[i++]+b[i];
}
}

int main(int argc, char const *argv[])
{
	int a[]={1,4,7,9,11,31,42,53,99};
	int b[]={2,3,5,8,14,34,52,76,88};
	
	return 0;
}