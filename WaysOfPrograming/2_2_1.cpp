#include <iostream>
using namespace std;
void quickSort(int a[],int left,int right){
	int pivot=a[left];
	int low=left;
	int high=right;
	if(low>high){
		return;
	}
	while(low<high){
		while(low<high&&a[high]>pivot){
            high--;
		}
		if (low<high)
		{
			a[low++]=a[high];//此时第一个数被覆盖掉了，但是保存在pivot中
		}
		while(low<high&&a[low]<pivot)
		{
			low++;
		}
		if (low<high)
		{
			a[high--]=a[low];
		}  
	}
	a[low]=pivot;//把pivot放在小的组中
	quickSort(a,left,low-1);
	quickSort(a,low+1,right);
}
void findTwoNum(int a[],int n,int k){
	quickSort(a,0,n-1);
	int begin=0;
	int end=n-1;
while(true)
{
	if (begin>=end)
	{
		break;
	}
	if (a[begin]+a[end]>k)
	{
		end--;
	}
	if (a[begin]+a[end]<k)
	{
		begin++;
	}
	if (a[begin]+a[end]==k)
	{
		cout<<"a["<<begin<<"]="<<a[begin]<<" "<<"a["<<end<<"]="<<a[end]<<endl;
		cout<<"a["<<begin<<"]+a["<<end<<"]="<<k<<endl;
		begin++;
	}
}
}
int main(int argc, char const *argv[])
{
	int a[]={11,2,4,15,8,1,7};
	quickSort(a,0,6);
	for (int i = 0; i < 7; ++i)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	findTwoNum(a,7,15);
	return 0;
}