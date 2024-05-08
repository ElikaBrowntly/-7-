#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
int main()
{
	int n, x, y;
	string operation;
	cin >> n;
	node* head = new node;
	head->next = NULL;
	for (int i = 0; i < n; i++)
	{
		node* p = head;
		cin >> operation;
		if (operation == "insert")
		{
			cin >> x >> y;
			while (p->next!=NULL)
			{
				if (p->next->data==x)
				{
					break;
				}
				p = p->next;
			}
			node* q = p->next;
			p->next = new node;
			p->next->data = y;
			p->next->next = q;
			q = NULL;delete q;
		}
		else
		{
			cin >> x;
			while (p->next != NULL)
			{
				if (p->next->data == x)
				{
					node* q = p->next;
					p->next = p->next->next;
					delete q;break;
				}
				p = p->next;
			}
		}
	}
	if (head->next==NULL)
	{
		cout << "NULL";
	}
	while (head->next!=NULL)
	{
		cout << head->next->data<<" ";
		head = head->next;
	}
	cout << endl;
	return 0;
}