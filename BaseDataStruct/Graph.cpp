#include <iostream>
#include <cstring>
using namespace std;

class LinkedListNode {
public:
    int vertex;
    LinkedListNode *next;

    LinkedListNode(int vertex_input) {
        vertex = vertex_input;
        next = NULL;
    }
};

class LinkedList {
public:
    LinkedListNode *head;

    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while (head != NULL) {
            LinkedListNode *delete_node = head;
            head = head->next;
            delete delete_node;
        }
    }

    void insert(int vertex) {
        LinkedListNode *node = new LinkedListNode(vertex);
        node->next = head;
        head = node;
    }
};
class MatGraph
{
private:
	int** mat;
	int n;
public:
	MatGraph(int input_n){
		n = input_n;
		mat = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			mat[i] = new int[n];
			memset(mat[i],0,sizeof(int) * n);//全部初始化为0
		}
	}
	~MatGraph(){
		for (int i = 0; i < n; ++i)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}
	void insert(int x,int y){
		mat[x][y]=1;
	}
	void output(){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};

class FormGraph
{
private:
	LinkedList* edges;
	int n;
public:
	FormGraph(int input_n){
		n = input_n;
		edges = new LinkedList[n];
	}
	~FormGraph(){
		delete[] edges;
	}
	void insert(int x,int y){
		edges[x].insert(y);
	}
	void output(){
		for (int i = 0; i < n; ++i)
		{
			cout<<i<<":";
			for (LinkedListNode* j=edges[i].head;j != NULL;j = j->next)
			{
				cout<<j->vertex<<" ";
			}
			cout<<endl;
		}
	}
	
};
int main(int argc, char const *argv[])
{
	FormGraph formg(5);
	formg.insert(1,2);
	formg.output();
	return 0;
}