#include <iostream>
#include <string>
#include <cassert>
using namespace std;
/*单调栈与单调队列很相似。首先栈是后进先出的，单调性指的是严格的递增或者递减。
单调栈有以下两个性质：
1、若是单调递增栈，则从栈顶到栈底的元素是严格递增的。若是单调递减栈，则从栈顶到栈底的元素是严格递减的。
2、越靠近栈顶的元素越后进栈。
单调栈与单调队列不同的地方在于栈只能在栈顶操作，因此一般在应用单调栈的地方不限定它的大小，否则会造成元素无法进栈。
元素进栈过程：对于单调递增栈，若当前进栈元素为e，从栈顶开始遍历元素，把小于e或者等于e的元素弹出栈，直接遇到一个大于e的元素或者栈为空为止，然后再把e压入栈中。对于单调递减栈，则每次弹出的是大于e或者等于e的元素。
一个单调递增栈的例子：
进栈元素分别为3，4，2，6，4，5，2，3
3进栈：（3）
3出栈，4进栈：（4）
2进栈：（4，2）
2出栈，4出栈，6进栈：（6）
4进栈：（6，4）
4出栈，5进栈：（6，5）
2进栈：（6，5，2）
2出栈，3进栈：（6，5，3）
以上左端为栈底，右端为栈顶。*/
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
bool precede(char a, char b) {//判断优先级，a高返回true
    if (a == '*') {
        return true;
    } else {
        return false;
    }
}
int operate(char theta, int a, int b) {//求值
    if (theta == '+') {
        return a + b;
    } else {
        return a * b;
    }
}
void calc(Stack<int> &numbers, Stack<char> &operators) {//弹出两个操作数和栈顶运算符运算
	int a=numbers.top();
	numbers.pop();
	int b=numbers.top();
	numbers.pop();
	numbers.push(operate(operators.top(),a,b));
	operators.pop();

}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	Stack<string> stack(n);
	for (int i = 1; i < m; ++i)
	{
		int opr;
		cin>>opr;
		if (opr==0)
		{
			string element;
			cin>>element;
			if(stack.push(element)){
				cout<<"push success!"<<endl;
			}
			else{
				cout<<"push failed!"<<endl;
			}
		}
		else if (opr==1)
		{
			if(stack.pop()){
				cout<<"pop success!"<<endl;
			}
			else{
				cout<<"pop failed!"<<endl;
			}
		}
		else if (opr==2)
		{
			cout<<stack.top()<<endl;
		}
		
	}
	/*
	创建数字栈与操作符栈进行表达式求值
	关键在于优先级的理解，当前运算符优先级高于运算符栈栈顶优先级则先弹出2个数字与当前运算符计算后压入数字栈
	int n;
	cin>>n;
	Stack<int> numbers(n);
	Stack<char> operators(n);
	string buffer;
    cin>>buffer;
    int i=0;
    while(i<n){
    	if (isdigit(buffer[i]))
    	{
    		numbers.push(buffer[i]-'0');
    		i++;
    	}
    	else{
    		if (operators.empty()||precede(buffer[i],operators.top()))
    		{
    			operators.push(buffer[i]);
    			i++;
    		}
    		else{
    			calc(numbers,operators);
    		}
    	}

    }
    while(operators.empty()){
     calc(numbers,operators);
   	}
   	cout<<numbers.top()<<endl;
    return 0;*/
}