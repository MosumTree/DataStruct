#include <iostream>
using namespace std;
//2.定义栈的数据结构，要求添加一个 min 函数，能够得到栈的最小元素。要求函数 min、push 以及 pop 的时间复杂度都是 O(1)。
//题目本意应该是熟悉栈的数据结构，至于这个min函数感觉没什么必要。个人感觉只要在栈类中声明一个私有的min变量，每次push时都与之比较覆盖，最后min函数返回min变量即可
template <class Type>class minStack
{
private:
	Type *data;
	int max_size,top_index;
public:
	minStack(int length_input){
		data = new Type[length_input];
		max_size = length_input;
		top_index = -1;
	}
	~minStack(){
		delete []data;
	}
	bool push(const Type &element){
		if (top_index >= max_size)
		{
			return false;
		}
		top_index++;
		data[top_index] = element;
		return true;
	}
	bool pop(){
		if (top_index < 0)
		{
			return false;			/* code */
		}
		top_index--;
		return true;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}