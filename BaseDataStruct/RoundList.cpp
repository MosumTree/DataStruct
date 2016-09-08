/*
数据结构课程第一章：链表（循环链表,解决约瑟夫环问题）
*/
#include<iostream>
using namespace std;
class Node//声明一个结点所要具有的属性：数据，指向下一个结点的指针
{
public:
	int data;
	Node* next;
	 Node(int _data){
     data=_data;
     next=NULL;
	 }
	~ Node();
};
class LinkList//声明链表：有表头，
{
private:
	Node* head;
public:
	LinkList(){
		head=NULL;
	}
	~LinkList();
	void insert(Node* node,int index){//插入结点函数，参数明确要插入的结点和插入的位置
       if (head==NULL)//空指针：插入结点作为表头
       {
       	head=node;
        head->next=head;//指向自身
       	return;
       }
       if (index==0)//插入位置为表首：新结点指针指向表头，表头赋值为新结点
       {
       	node->next=head->next;//循环链表中默认头结点为表尾，头结点下一节点为表首
        head->next=node;
       	return;
       }     
       /*常规情况：声明当前结点。初始值为表头，计数变量用于找插入位置
        *从表头开始遍历，当前结点不为末尾结点且循环次数不超过插入位置，继续
        *找到所要插入位置，新结点的下一结点为当前结点的下一结点，当前结点指针指向新结点
        */
       Node* current_node=head->next;
       int count=0;
       while(current_node->next!=NULL&&count<index-1){
       	current_node=current_node->next;
       	count++;
       }
       if (count==index-1)
       {
       	node->next=current_node->next;//用图表示方便理解
        current_node->next=node;
       }
       if(node==head->next){
        head=node;//如果插入节点在头结点后成为循环链表最后一个结点，那新结点成为头结点
        }
	}
  void output_josephus(int m){
    Node* current_node=head;
    while(current_node->next!=current_node){
      for (int i = 1; i < m; ++i)
      {
        current_node=current_node->next;//index=m-1
      }
      cout<<current_node->next->data<<" ";
      Node* delete_node=current_node->next;//存储被删结点（当前结点为被删结点前一结点）
      current_node->next=delete_node->next;//当前结点下一结点指向被删结点下一结点
      delete delete_node;//释放内存
    }
    cout<<current_node->data<<endl;
    delete current_node;
   }
};
int  main(int argc, char const *argv[])
{
	LinkList linklist;
  int n,m;//约瑟夫问题中的人数n和计数值m（数到m时退出1人）
  cin>>n>>m;
  for (int i = 0; i < n; ++i)
  {
    Node* node=new Node(i);
    linklist.insert(node,i-1);
  }
  linklist.output_josephus(m);
	/* code */
	return 0;
}