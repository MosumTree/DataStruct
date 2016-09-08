#include <iostream>
#include <math.h>
using namespace std;
class Heap
{
private:
	double *data;
	int size;
public:
	Heap(int heap_length){
		size=0;
		data=new double[heap_length];
	};
	~Heap(){
		delete []data;
	};
	int getSize(){
		return size;
	}
	//插入堆元素
	void push(double value){
		data[size]=value;
		int current=size;
		int father=(current-1)/2;
		while (data[current]>data[father])//这里注意要不停循环
		{
			swap(data[current],data[father]);
			current=father;
			father=(current-1)/2;
		}
		size++;
	}
	//返回堆顶元素
	double top(){
		return data[0];
	}

	//输出堆
	void output(){
		for (int i = 0; i < size; ++i)
		{
			cout<<data[i]<<"  ";
		}
		cout<<endl;
	}
	//交换后的更新操作
    void update(int pos,int n){
    	int lchild,rchild;
    	lchild=2*pos+1;
    	rchild=2*pos+2;
    	int max_value=pos;
    	if (lchild<n&&data[lchild] > data[max_value])//注意左右孩子需要小于数组大小
    	{
    		max_value = lchild;
    	}
    	if (rchild<n&&data[rchild] > data[max_value])
    	{
    		max_value = rchild;
    	}
    	if (max_value != pos)
    	{
    		swap(data[pos],data[max_value]);
    		update(max_value,n);
    	}

    }
    //删除堆顶元素
	void pop(){
		swap(data[0],data[size-1]);
		size--;
		update(0,size);
	}
	//堆排序
	void heap_sort(){
    for(int i = size-1;i >= 1;i--){
    swap(data[i],data[0]);
        update(0,i);
    }
    }
	
};
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *ball=new int[n];
	int ballquality;
	for (int i = 0; i < n; ++i)
	{
		cin>>ballquality;
		ball[i] = ballquality;
	}
	Heap heap(100);
	for (int i = 0; i < n; ++i)
	{
		heap.push(ball[i]);
	}
	double first,second,result;
	double final=0;
	while(heap.getSize() > 1){
		first = heap.top();
		heap.pop();
		second = heap.top();
		heap.pop();
		result = pow(first*second*second,0.333333);
		heap.push(result);
	}
	cout.precision(12);
	cout<<result<<endl;

}