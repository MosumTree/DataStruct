/*
数据结构课程第一章：链表（单链表）
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node //声明一个结点所要具有的属性：数据，指向下一个结点的指针
{
  public:
    int data;
    Node *next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};
class LinkList //声明链表：有表头，
{
  private:
    Node *head;

  public:
    LinkList()
    {
        head = NULL;
    }
    void insert(Node *node, int index)
    {                     //插入结点函数，参数明确要插入的结点和插入的位置
        if (head == NULL) //空指针：插入结点作为表头
        {
            head = node;
            return;
        }
        if (index == 0) //插入位置为表首：新结点指针指向表头，表头赋值为新结点
        {
            node->next = head;
            head = node;
            return;
        }
        /*常规情况：声明当前结点。初始值为表头，计数变量用于找插入位置
        *从表头开始遍历，当前结点不为末尾结点且循环次数不超过插入位置，继续
        *找到所要插入位置，新结点的下一结点为当前结点的下一结点，当前结点指针指向新结点
        */
        Node *current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1)
        {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1)
        {
            node->next = current_node->next; //用图表示方便理解
            current_node->next = node;
        }
    }
    void output()
    { //遍历结点函数，输出所有结点数据域
        if (head == NULL)
        {
            return;
        }
        Node *current_node = head;
        while (current_node != NULL)
        {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    void delete_node(int index)
    { //删除结点函数,参数表示删除第几个结点
        if (head == NULL)
        {
            return;
        }
        Node *current_node = head;
        int count = 0;
        if (index == 0)
        {
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index - 1)
        {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1 && current_node->next != NULL)
        {
            Node *delete_node = current_node->next; //当前结点下一结点即是要删除的结点
            current_node->next = delete_node->next; //当前结点的下一结点改为被删结点的下一结点
            delete delete_node;
        }
    }
    void reverse()
    { //链表反转函数
        if (head == NULL)
        {
            return;
        }
        Node *next_node, *current_node;
        current_node = head->next; //当前结点初始化为第2个结点
        head->next = NULL;         //把头结点与链表断开
        while (current_node != NULL)
        {
            next_node = current_node->next; //保存当前结点下个结点
            current_node->next = head;      //头结点成为当前结点下一结点，当前结点成为头结点
            head = current_node;
            current_node = next_node; //当前结点成为第3个结点（结合步骤画图更易理解）
        }
    }

    /* data */
};
vector<int> printListFromTailToHead(Node *head)
{
    stack<Node *> s;
    while (head != NULL)
    {
        s.push(head);
        head = head->next;
    }
    vector<int> a;
    while (!s.empty())
    {
        a.push_back(s.top()->data);
        s.pop();
    }
    return a;
}
int main(int argc, char const *argv[])
{
    /*	LinkList linklist;
	for (int i = 1; i <=10; ++i)//插入值为1~10的结点
	{
		Node* node=new Node(i);//声明一个新结点，数据值为i
		linklist.insert(node,i-1);//将刚声明的结点按顺序插入插入
	}
	linklist.output();
	linklist.delete_node(5);
	linklist.output();
  linklist.reverse();
  linklist.output();*/
    /* code */
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    /*while(node1!=NULL){
    cout<<node1->data<<"   ";
    node1=node1->next;
  }*/
    vector<int> a = printListFromTailToHead(node1);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << "   ";
    }
    return 0;
}