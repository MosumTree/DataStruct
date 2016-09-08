#include <iostream>
#include <assert>
using namespace std;
//数据结构第二章：队列
class Queue
{

private:
	int *data;//?
	int head,tail,length;
public:
	Queue(int length_input){
		data=new int[length_input];
		length=length_input;
		head=0;
		tail=-1;
	}
	~Queue(){
		delete[] data;
	}
	void push(int element){//元素加入队列函数
		if (tail+1<length)
		{
			tail+=1;
			data[tail]=element;
		}
	}
	void output(){//输出队列元素
		for (int i = head; i <=tail; ++i)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	int front(){//输出队列首元素
		assert(head<tail);//断言宏，满足括号内条件，终止程序
		return data[head];
	}
	void pop(){//删除队列首元素
		assert(head<=tail);
		head+=1;
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