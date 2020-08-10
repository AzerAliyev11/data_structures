#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<cmath>
#include<numeric>
#include<exception>
#include<stack>
#include<string>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

void printlist(Node *n)
{
	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void push_front(Node** head_ref, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	new_node->next = *head_ref;
	*head_ref = new_node;
}

void pop_front(Node** head_ref)
{
		Node *temp = new Node();
		temp = *head_ref;

		if (*head_ref == NULL)
		{
			throw 20;
		}

		*head_ref = temp->next;
		delete temp;
}

void push_back(Node** head_ref, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	Node *last = *head_ref;

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

void pop_back(Node **head_ref)
{
	Node *last = *head_ref;

	if (*head_ref == NULL)
	{
		throw 20;
	}

	while (last->next->next != NULL)
	{
		last = last->next;
	}

	delete last->next;

	last->next = NULL;
	return;
}

void InsertAfter(Node **head_ref, int new_data, int node_num)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	Node *last = *head_ref;

	for (int i = 0; i < node_num - 1; i++)
	{
		last = last->next;
		if (last == NULL)
		{
			return;
		}
	}

	if (last == *head_ref)
	{
		new_node->next = last;
		*head_ref = new_node;
		return;
	}

	new_node->next = last->next;
	last->next = new_node;
	return;
}

void append(Node** head_ref, int new_data)
{
	Node *new_node = new Node();
	Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	return;
}

class MyStack
{
public:
	MyStack();
	void push(int);
	void pop();
	int max_el();
	int top_el();
private:
	int top;
	int *arr;
	int *max_arr;
	int max_top;
};

MyStack::MyStack()
{
	top = -1;
	arr = new int[n];
	max_arr = new int[n];
	max_top = -1;
}

void MyStack::push(int a)
{
	top++;
	arr[top] = a;
	if (top == 0)
	{
		max_top++;
		max_arr[max_top] = a;
	}
	else
	{
		if (max_arr[max_top] < a)
		{
			max_top++;
			max_arr[max_top] = a;
		}
	}
}

int MyStack::top_el()
{
	return arr[top];
}

void MyStack::pop()
{
	if (arr[top]==max_arr[max_top])
	{
		max_top--;
	}
	top--;
}

int MyStack::max_el()
{
	return max_arr[max_top];
}


int main()
{
	
}