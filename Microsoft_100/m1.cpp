#include <iostream>
using namespace std;
//1.输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。要求不能创建任何新的结点，只调整指针的指向
/*
10
/ \
6 14
/ \ / \
4 8 12 16
转换成双向链表
4=6=8=10=12=14=16。
*/
class Node
{
public:
	int data;
	Node *lchild,*rchild;
	Node(int _data){
		data = _data;
		lchild = NULL;
		rchild = NULL;
	}
	~Node(){
		if (lchild != lchild)
		{
			delete lchild;
		}
		if (rchild != rchild)
		{
			delete rchild;
		}
	}
	
};
class BinarryTree{
	private:
		Node *root;
	public:
		BinarryTree(){
			root = NULL;
		}
		~BinarryTree(){
			if (root != NULL)
			{
				delete root;
			}
		}
		void build_demo(){
			root = new Node(10);
			root->lchild = new Node(6);
			root->rchild = new Node(14);
			root->lchild->lchild = new Node(4);
			root->lchild->rchild = new Node(8);
			root->rchild->lchild = new Node(12);
			root->rchild->rchild = new Node(16);
		}
		Node *getList(){
			Node *head = NULL,*tail = NULL;
			help(head,tail,root);
			return head;
		}
		void output(){
			if (root = NULL)
			{
				cout<<"empty!"<<endl;
			}
			cout<<root->data<<" AA";
			
		}
		void help(Node *head,Node *tail,Node *root){
			Node *lt = NULL,*rh = NULL;
			if (root == NULL)
			{
				head = NULL;
				tail = NULL;
				return;
			}
			help(head,lt,root->lchild);
			help(rh,tail,root->rchild);
			if (lt != NULL)
			{
				lt->rchild = root;
				root->lchild = lt;				
			}
			else{
				head = root;
			}
			if (rh != NULL)
			{
				root->rchild = rh;
				rh->lchild = root;
			}
			else{
				tail = root;
			}
		}

};

int main(int argc, char const *argv[])
{
	BinarryTree binarrytree;
	binarrytree.build_demo();
	binarrytree.output();
	Node *head = binarrytree.getList();
	if (head == NULL)
	{
		cout<<"The Tree is empty!"<<endl;
	}
	while(head != NULL){
		cout<<head->data<<" ";
		head = head->lchild;
	}
	cout<<endl;
	return 0;
}