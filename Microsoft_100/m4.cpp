/*
4.在二元树中找出和为某一值的所有路径
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
例如输入整数 22 和如下二元树
10
/ \
5 12
/ \
4 7
*/

/*
发表一下感言，这个关于二叉树的问题是我第一个做出来的有关链表方面的编程题，它具有里程碑式的意义，实现了从无到有的历史性跨越，
极大的增强了我编码的信心，答案中确实用了堆栈与递归的思想，但是我没仔细看，大致了解是对左右字数的递归找路径，经过一番调试，
竟然解决了，好开心，
纪念一下！
*/
#include <iostream>
#include <queue>
using namespace std;
class Node
{	
public:
	int data;
	Node *lchild;
	Node *rchild;
	Node *parent;
	Node(int _data,Node* _father=NULL){
		data = _data;
		lchild=NULL;
    	rchild=NULL;
    	parent=_father;
	}
	~Node(){
		if (lchild != NULL)
		{
			delete lchild;
		}
		if (rchild != NULL)
		{
			delete rchild;
		}
	}
	void preorder(){
		cout<<data<<" ";
		if (lchild != NULL)
		{
			lchild -> preorder();/* code */
		}
		if (rchild != NULL)
		{
			rchild -> preorder();
		}
	}
	void inorder(){
		if (lchild != NULL)
		{
			lchild -> inorder();/* code */
		}
		cout<<data<<" ";
		if (rchild != NULL)
		{
			rchild -> inorder();
		}
	}
	void postorder(){
		if (lchild != NULL)
		{
			lchild -> postorder();/* code */
		}
		cout<<data<<" ";
		if (rchild != NULL)
		{
			rchild -> postorder();
		}
	}
	void insert(int value){
		if (value > data)
		{
			if (rchild == NULL)
			{
				rchild = new Node(value);
			}
			else{
			rchild->insert(value);
			}
		}
		else if (value == data)
		{
			return;
		}
		if (value < data)
		{
			if (lchild == NULL)
			{
				lchild = new Node(value);
			}
			else{
			lchild->insert(value);
			}
		}
	}
};
	
class BinarySearchTree
{
private:
	Node *root;
public:
	BinarySearchTree(){
		root = NULL;
	}
	~BinarySearchTree(){
		if (root != NULL)
		{
			delete root;
		}
	}
	void insert(int value){
		if (root == NULL)
		{
			root = new Node(value);
		}
		else{
			root -> insert(value);
		}
	}
	void preorder(){
		root -> preorder();
	}
	void inorder(){
		root -> inorder();
	}
	void postorder(){
		root -> postorder();
	}
	Node * getroot(){
		return root;
	}
	
};
void findpath(Node *rootNode,int curtotal,queue<int> q,int sum){
	if (rootNode == NULL)
	{
		return;
	}
	else{
		curtotal+=rootNode->data;
		q.push(rootNode->data);
		if (curtotal == sum)
		{
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				cout<<q.front()<<" ";
				q.pop();
			}
			cout<<endl;
		}
		else if(curtotal <sum){
			findpath(rootNode->lchild,curtotal,q,sum);
			findpath(rootNode->rchild,curtotal,q,sum);
		}
		else{
			return;
		}
	}
}
int main(int argc, char const *argv[])
{
	BinarySearchTree bst;
	bst.insert(10);
	bst.insert(5);
	bst.insert(12);
	bst.insert(4);
	bst.insert(7);
	bst.insert(3);
	Node *rootNode= bst.getroot();
	int currenttoatl=0;
	queue<int> q;
	findpath(rootNode,currenttoatl,q,22);
	return 0;
}