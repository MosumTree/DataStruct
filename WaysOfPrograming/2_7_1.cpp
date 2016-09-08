#include <iostream>
using namespace std;
/*现有n个红白蓝三种不同颜色的小球，乱序排列在一起，请通过两两交换任意两个球，使得从左至右，依次
是一些红球、一些白球、一些蓝球。*/
void threeColorSort(int a[],int n){
int begin=0,current=1,end=n-1;
while (current<=end)
{
	if (a[current]==0)
	{
		swap(a[begin],a[current]);
		current++;
		begin++;
		continue;
	}
	if (a[current]==1)
	{
		current++;
		continue;
	}
	if (a[current]==2)
	{
		swap(a[current],a[end]);
		end--;
		continue;
	}
}
for (int i = 0; i < n; ++i)
{
	cout<<a[i]<<"  ";
}
}
int main(int argc, char const *argv[])
{
	int a[13]={1,2,0,1,0,0,1,1,2,0,1,2,1};
	threeColorSort(a,13);
	return 0;
}