#include <iostream>
using namespace std;
/*
5.查找最小的 k 个元素（数组）
题目：输入 n 个整数，输出其中最小的 k 个。
例如输入 1，2，3，4，5，6，7 和 8 这 8 个数字，则最小的 4 个数字为 1，2，3 和 4。
*/
void QuickSelect(int a[],int k,int left,int right){
int i,j,pivot;
if (right-left+1<k)
{
	cout<<"error!"<<endl;
	return ;
}
pivot=a[left];
i=left;
j=right+1;
//把数组分为小于pivot和大于pivot的两部分
while(true){
    while(a[++i]<pivot);
    while(a[--j]>pivot);
    if (i>j) break;
    swap(a[i],a[j]);
}
swap(a[left],a[j]);//重置枢纽，避免老是比较同一个pivot而陷入死循环
if (j+1-left==k)
{
	for (int m = left; m<=j; ++m)
	{
		cout<<a[m]<<" ";
	}
}
else if (j+1-left>k)
{
	QuickSelect(a,k,left,j);
}
else{
	for(int m=0;m<j+1-left;m++)
	cout<<a[m]<<" ";
	QuickSelect(a,k-(j-left+1),j+1,right);
}
}
int main(int argc, char const *argv[])
{
	int a[]={89,1,23,12,6,2,7,8,9,13,2,3};
	QuickSelect(a,5,0,11);
	return 0;
}