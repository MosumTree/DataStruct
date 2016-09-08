#include <iostream>
#include <assert>
using namespace std;
//数据结构第二章：队列（循环）
class Queue
{

private:
	int *data;//?
	int head,tail,length,count;
public:
	Queue(int length_input){
		data=new int[length_input];
		length=length_input;
		head=0;
		tail=-1;
		count=0;//用于判断队列是否为空
	}
	~Queue(){
		delete[] data;
	}
	void push(int element){//元素加入队列函数
		if (tail+1<length)
		{
			tail=(tail+1)%length;//比长度多多少，就回到数组首址往下数多少
			data[tail]=element;
		    count++;
		}
	}
	void output(){//输出队列元素
		for (int i = head; i <=tail; ++i)
		{
			if (i>length-1)
			{
				i=i%length;
			}
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	int front(){//输出队列首元素
		assert(count>0);//断言宏，满足括号内条件，终止程序
		return data[head];
	}
	void pop(){//删除队列首元素
		assert(count>0);
		head=(head+1)%length;
		count--;
	}

};
int main() {
	Queue queue(100);
	for (int i = 1; i < =10; ++i)
	{
		queue.push(i);
	}
	queue.output();
	cout<<queue.front<<endl;
	queue.pop();
	queue.output();
    return 0;
}