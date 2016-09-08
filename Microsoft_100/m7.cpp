#include <iostream>
using namespace std;
/*
第 7 题（链表）
微软亚院之编程判断俩个链表是否相交
给出俩个单向链表的头指针，比如 h1，h2，判断这俩个链表是否相交。
为了简化问题，我们假设俩个链表均不带环。
问题扩展：
1.如果链表可能有环列?
2.如果需要求出俩个链表相交的第一个节点列?
*/

/*
1.问题分析

　　看看两个链表相交到底是怎么回事吧，有这样的的几个事实：（假设链表中不存在环）

　　（1）一旦两个链表相交，那么两个链表中的节点一定有相同地址。

　　（2）一旦两个链表相交，那么两个链表从相交节点开始到尾节点一定都是相同的节点。

　　分析出来了问题的本质，那么思路也就自然有了。
*/

class Node{
private:
	int data;
	Node *next;
public:
	Node(int _data){
		data = _data;
		next = NULL;
	}
};

bool isJointSimple(Node*n1,Node*n2){
	while(n1->next!=NULL){
		n1=n1->next;
	}
	while(n2->next!=NULL){
		n2=n2->next;
	}
	if (n1==n2)
	{
		return true;
	}
	else{
		return false;
	}
}
bool isJoint(Node*n1,Node*n2){
	int a=hasRing(n1);
	int b=hasRing(n2);
	if (a+b==0)
	{
		return isJointSimple(n1,n2);
	}
	if (a+b==1)
	{
		return false;
	}
	if (a+b==2)
	{
		Node* temp=n1;
		while(true){
			if (temp==n2||temp->next==n2)
			{
				return true;
			}
			temp=temp->next->next;
			n1=n1->next;
			if (n1==temp)
			{
				return false;
			}
		}
	}
}
int hasRing(Node *n){
	Node*p1=n,*p2=n;
	while(p2!=NULL&&p2->next!=NULL){
		p1=p1->next;
		p2=p2->next->next;
		if (p1==p2)
		{
			return 1;
		}
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}