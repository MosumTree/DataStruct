// 第三章关于栈的练习题，魔法机,判断按顺序入栈的数字能否根据要求顺序出栈
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <class Type>class Stack
{
private:
	Type* urls;
	int max_size,top_index;
public:
	Stack(int length_input){
     urls=new Type[length_input];
     max_size=length_input;
     top_index=-1;
	}
	~Stack(){
	delete[] urls;}

	bool push(const Type &element){//入栈函数：参数前加引用，节省内存
		if(top_index>=max_size-1){
			return false;
		}
		top_index++;
		urls[top_index]=element;
		return true;
	}
	bool pop(){//出栈函数
		if (top_index<0)
		{
			return false;
		}
		top_index--;
		return true;
	}
	Type top(){
		assert(top_index>=0);
		return urls[top_index];
	}
	bool empty(){
		if (top_index<0)
		{
			return true;
		}
		else{
			return false;
		}
	}
};
int main(int argc, char const *argv[])
{
	int N,a0;
	cin>>N;
	int* a=new int[N];
    Stack<int> stack(N);
	for (int i = 0; i < N; ++i)
	{
		cin>>a0;
		a[i]=a0;
	}
	int n=0,judge=1;
	for (int i = 0; i < N; ++i)
	{
		//n=i;
		while(n<N&&n+1<=a[i]&&judge)
		{
			stack.push(n+1);
			if(n+1==N)
				judge=0;
			n++;
		}
		if (stack.top()==a[i])
		{
			//cout<<stack.top()<<"  ";
			stack.pop();
		}
		else{
		    cout<<"NO";
		    return 0;
	    }
	}
	cout<<"YES";
	return 0;
}