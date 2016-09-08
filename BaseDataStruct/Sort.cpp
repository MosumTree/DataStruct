#include <iostream>
#include <vector>
using namespace std;
/*
桶排序
堆排序
插入排序
选择排序
冒泡排序
快速排序
归并排序
希尔排序
*/
void bubble_sort(int a[],int n){
	for (int i = 0; i < n-1; ++i)//循环比较n-1遍，这个循环和下标无关
	{
		for (int j = 0; j < n-i-1; ++j)//每次比较都从首元素开始
		{
			if (a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
}
vector<int> insert_sort(int a[],int n){
	vector<int> v;
	v.push_back(a[0]);
	vector<int>::iterator the_iterator;
	the_iterator=v.begin();
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < v.size(); ++j)
		{
			if (a[i]<=v[j])
			{
				v.insert(the_iterator+j,1,a[i]);//不知道为啥每次执行完插入都要更新迭代器位置
				the_iterator=v.begin();
				break;
			}
			if(j==v.size()-1){
				v.push_back(a[i]);
		        the_iterator=v.begin();
				break;
			}
		}
		
	}
	return v;
}
void select_sort(int a[],int n){
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (a[j]<a[i])
			{
				swap(a[j],a[i]);
			}
		}
	}
}

void quick_sort(int a[],int left,int right){
	int m,n,pivot;
	m=left;
	n=right;
	pivot=left;
	while (m<n&&m<right&&n>left)
	{
		while (a[m]<=a[pivot] && m<right)
		{
			m++;
		}
		while (a[n]>a[pivot] && n>left)
		{
			n--;
		}
		swap(a[m],a[n]);
		m++;n--;
	}
	swap(a[pivot],a[m]);
	quick_sort(a,left,m-1);
	quick_sort(a,m+1,right);
}
int main(int argc, char const *argv[])
{
	int a[10]={3,8,7,6,0,9,5,4,2,1};

	//bubble_sort(a,10);
	//std::vector<int> v=insert_sort(a,10);
	//select_sort(a,10);
	quick_sort(a,0,9);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}