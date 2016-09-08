#include <iostream>
#include <string.h>
using namespace std;
//结点类
class Node{
public:
	int data;
	Node* lchild,*rchild;
    Node(int _data){
    	data=_data;
    	lchild=NULL;
    	rchild=NULL;
    }
    ~Node(){
    	if (lchild!=NULL)
    	{
    		delete lchild;
    	}
    	if (rchild!=NULL)
    	{
    		delete rchild;
    	}
    }
    //前序遍历
    void preorder(){
    	cout<<data<<" ";
    	if (lchild!=NULL)
    	{
    		lchild->preorder();
    	}
    	if (rchild!=NULL)
    	{
    		rchild->preorder();
    	}
    }
    //中序遍历
    void inorder(){
    	if (lchild!=NULL)
    	{
    		lchild->inorder();
    	}
    	cout<<data<<" ";
    	if (rchild!=NULL)
    	{
    		rchild->inorder();
    	}
    }
    //后序遍历
    void postorder(){
    	if (lchild!=NULL)
    	{
    		lchild->postorder();
    	}
    	if (rchild!=NULL)
    	{
    		rchild->postorder();
    	}
    	cout<<(char)data;
    }
    //已知前序中序求后序
    Node* build(const string& pre_str,const string& in_str,int len){
       Node*p=new Node(pre_str[0]-'0'+48);
       int pos=in_str.find(pre_str[0]);
       if (pos>0)
       {
       	p->lchild=build(pre_str.substr(1,pos),in_str.substr(0,pos),pos);//substr的第二个参数表示长度，不是结束位置！！！
       }
       if (len-pos-1>0)
       {
       	p->rchild=build(pre_str.substr(pos+1),in_str.substr(pos+1),len-pos-1);
       }
       return p;
    }
    //构建镜子中的二叉树
    Node* mirrorBuild(const string& pre_str,const string& in_str,int len){
       Node*p=new Node(pre_str[0]-'0'+48);
       int pos=in_str.find(pre_str[0]);
       if (pos>0)
       {
       	p->rchild=build(pre_str.substr(1,pos),in_str.substr(0,pos),pos);//substr的第二个参数表示长度，不是结束位置！！！
       }
       if (len-pos-1>0)
       {
       	p->lchild=build(pre_str.substr(pos+1),in_str.substr(pos+1),len-pos-1);
       }
       return p;
    }
};
//二叉树类
class BinaryTree
{
private:
	Node* root;
public:
	BinaryTree(){
    root=NULL;
	};
	void build_demo(){
		root=new Node(1);
		root->lchild=new Node(2);
		root->rchild=new Node(3);
		root->lchild->lchild=new Node(4);
		root->lchild->rchild=new Node(5);
		root->rchild->rchild=new Node(6);
	}
	~BinaryTree(){
		if (root!=NULL)
		{
			delete root;
		}
	}
	BinaryTree(const string& pre_str,const string& in_str,int len){
		root=root->build(pre_str,in_str,len);
	}
	void mirrorBuild(const string& pre_str,const string& in_str,int len){
		root=root->mirrorBuild(pre_str,in_str,len);
	};
	void MirroRecursively(Node *pNode)
    {
	if(NULL == pNode)
		return;
	if(NULL == pNode->lchild && NULL == pNode->rchild)
		return;
	
	Node *pTemp = pNode->lchild;
	pNode->lchild = pNode->rchild;
	pNode->rchild = pTemp;
	
	if(pNode->lchild)
		MirroRecursively(pNode->lchild);
	if(pNode->rchild)
		MirroRecursively(pNode->rchild);
    }
	void preorder(){
		root->preorder();
	}
	void inorder(){
		root->inorder();
	}
	void postorder(){
		root->postorder();
	}
	Node* getRoot(){
		return root;
	}
};

int main(int argc, char const *argv[])
{
	/*BinaryTree binarytree;
	binarytree.build_demo();
	binarytree.preorder();
	cout<<endl;
	binarytree.inorder();
	cout<<endl;
	binarytree.postorder();
	cout<<endl;*/
	string pre_str;
    string in_str;
    cin>>pre_str;
    cin>>in_str;
    BinaryTree binarytree(pre_str,in_str,in_str.length());
    binarytree.postorder();
    cout<<endl;
    binarytree.MirroRecursively(binarytree.getRoot());
    binarytree.postorder();
    cout<<endl;
  /*  BinaryTree mirrorBinarytree;
    mirrorBinarytree.mirrorBuild(pre_str,in_str,in_str.length());
    mirrorBinarytree.postorder();*/
    cout<<endl;
	return 0;
}