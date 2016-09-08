#include <iostream>
using namespace std;
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
// 有两个序列A和B,A=(a1,a2,...,ak),B=(b1,b2,...,bk)，A和B都按升序排列。对于1<=i,j<=k，求k个最小
// 的（ai+bj）。要求算法尽量高效
	int b[10]={1,3,5,7,9,34,57,85,98,99};
	int c[10]={2,5,8,9,23,65,79,123,124,266};
	return 0;
}