#include <iostream>
#include <string.h>
using namespace std;
//结点�?
class Node{
public:
	int data;
	Node* lchild,*rchild,*father;
    Node(int _data,Node* _father=NULL){
    	data=_data;
    	lchild=NULL;
    	rchild=NULL;
    	father=_father;
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
    //已知前序中序求后�?
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
    //插入函数
    void insert(int value){
    	if (value>data)
    	{
    		if (rchild==NULL)
    		{
    			rchild=new Node(value);
    		}
    		else{
    			rchild->insert(value);
    		}
    	}
    	if (value==data)
    	{
    		return;
    	}
    	else{
    		if (lchild==NULL)
    		{
    			lchild=new Node(value);
    		}
    		else{
    			lchild->insert(value);
    		}
    	}
    }
    //查找函数
    Node* search(int value){
    	if (value>data)
    	{
    		if (rchild==NULL)
    		{
    			return NULL;
    		}
    		else{
    			rchild->search(value);
    		}
    	}
    	if (value==data)
    	{
    		return this;
    	}
    	else{
    		if (lchild==NULL)
    		{
    			return NULL;
    		}
    		else{
    			lchild->search(value);
    		}
    	}
    }

    //前驱结点
    Node* predecessor(){
    	Node* temp=lchild;
    	while(temp!=NULL&&temp->rchild!=NULL){
    		temp=temp->predecessor();
    	}
    	return temp;
    }
    //后继结点
    Node* successor(){
    	Node* temp=rchild;
    	while(temp!=NULL&&temp->lchild!=NULL){
    		temp=temp->successor();
    	}
    	return temp;
    }
    //删除度为0�?的结�?
    void remove_node(Node* delete_node){
        Node* temp=NULL;
        if(delete_node->lchild!=NULL){
            temp=delete_node->lchild;
            temp->father=delete_node->father;
            delete_node->lchild=NULL;
        }
        if(delete_node->rchild!=NULL){
            temp=delete_node->rchild;
            temp->father=delete_node->father;
            delete_node->rchild=NULL;
        }
        if(delete_node->father->lchild==delete_node){
            delete_node->father->lchild=temp;
        }
        else{
            delete_node->father->rchild=temp;
        }
        delete delete_node;
    }
    //完整的删除函�?
   bool delete_tree(int value){
        Node* delete_node,* current_node;
        current_node=search(value);
        if(current_node==NULL){
            return false;
        }
        if(current_node->lchild!=NULL){
            delete_node=current_node->predecessor();
        }
        else if(current_node->rchild!=NULL){
            delete_node=current_node->successor();
        }
        else{
        delete_node=current_node;
        }
        current_node->data=delete_node->data;
        remove_node(delete_node);
        return true;
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
	//镜像二叉�?
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
	void insert(int value){
		if (root==NULL)
		{
			root=new Node(value);
		}
		else{
			root->insert(value);
		}
	}
	bool search(int value){
		if (root->search(value)==NULL)
		{
			return false;
		}
		else{
			return true;
		}
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