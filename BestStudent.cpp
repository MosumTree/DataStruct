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
       	return;
       }
       if (index==0)//插入位置为表首：新结点指针指向表头，表头赋值为新结点
       {
       	node->next=head;
       	head=node;
       	return;
       }     
       /*常规情况：声明当前结点。初始值为表头，计数变量用于找插入位置
        *从表头开始遍历，当前结点不为末尾结点且循环次数不超过插入位置，继续
        *找到所要插入位置，新结点的下一结点为当前结点的下一结点，当前结点指针指向新结点
        */
       Node* current_node=head;
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
	}
	void output(int index){//遍历结点函数，输出所有结点数据域
		if (head==NULL)
		{
			return;
		}
		Node* current_node=head;
		if (index==1)
		{
			cout<<head->data;
			return;
		}
		else{
		for (int i = 1; i < index; ++i)
		{
			current_node=current_node->next;
		}
		cout<<current_node->data;
		return;
	}
	}
    void delete_node(int index){//删除结点函数,参数表示删除第几个结点
        if (head==NULL)
		{
			return;
		}
		Node* current_node=head;
        int count=0;
        if(index==0){
        	head=head->next;
        	delete current_node;
        	return;
        }
        while(current_node->next!=NULL&&count<index-1){
       	current_node=current_node->next;
       	count++;
        }
        if (count==index-1&&current_node->next!=NULL)
        {
        	Node* delete_node=current_node->next;//当前结点下一结点即是要删除的结点
        	current_node->next=delete_node->next;//当前结点的下一结点改为被删结点的下一结点
            delete delete_node;
        }
    }
    
};
int main(int argc, char const *argv[])
{
	int N,M,num;
    cin>>N>>M;
    int* numi=new int[M];
    for (int i = 0; i < M; ++i)
    {
    	cin>>num;
    	numi[i]=num;
    }
    LinkList linklist;
    for (int i = 1; i <=N; ++i)
	{
		Node* node=new Node(i);//声明一个新结点，数据值为i
		linklist.insert(node,i-1);//将刚声明的结点按顺序插入
	}
	for (int i = 0; i < M; ++i)
	{
		linklist.delete_node(numi[i]-1);////////参数为前一结点，删除参数的后一个结点
	}
    int best=(N-M)/2+1;
    linklist.output(best);
	return 0;
}