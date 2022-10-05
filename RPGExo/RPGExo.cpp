#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	int data;
	Node* next = nullptr;
	Node(int _data, Node* _next = nullptr)
	{
		data = _data;
		next = _next;
	}
};

class List
{
private:
	Node* head = nullptr;

	

public:
	void AddFirst(int _data)
	{
		if (Contains(_data)) return;
		if (head == nullptr)
		{
			head = new Node(_data);
		}
		else {
			Node* _newNode = new Node(_data, head);
			head = _newNode;
		}
	}
	void AddLast(int _data)
	{
		if (Contains(_data)) return;
		if (head->next == nullptr)
			head->next = new Node(_data);
		else
		{
			Node* node = head;
			while (node->next != nullptr)			
				node = node->next;			
			node->next = new Node(_data);
		}
	}
	void Clear()
	{
		delete head;
	}
	void AddAfter(int _data, int _after)
	{
		if (Contains(_data)) return;
		Node* node = head;
		while (node->data != _after)
		{
			node = node->next;
		}
		node->next = new Node(_data, node->next);

	}
	void AddBefore(int _data, int _before)
	{
		if (Contains(_data)) return;
		if (_before == head->data)
		{
			AddFirst(_data);
			return;
		}
		FindBefore(_before)->next = new Node(_data, FindBefore(_before)->next);
	}
	void Remove(int _data)
	{
		if (!Contains(_data)) return;
		if (_data == head->data)
			head = head->next;
		else
		{
			Node* before = FindBefore(_data);
			before->next = before->next->next;
		}
	}
	
	void RemoveFirst()
	{
		head = head->next;
	}
	void RemoveLast()
	{
		Node* n = head;
		while (n->next != nullptr)		
			n = n->next;
		FindBefore(n->data)->next = nullptr;
	}
	bool Contains(int _data)
	{
		bool found = false;
		Node* node = head;
		while (!found) {
			if (node == nullptr) break;
			found = node->data == _data;
			node = node->next;
		}
		return found;
	}
	void Display()
	{
		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
	}
	Node* FindBefore(int _data)
	{
		Node* node = head;
		int count = 0;
		while (node->data != _data)
		{
			node = node->next;
			count++;
		}
		int num = 0;
		node = head;
		while (num != (count - 1))
		{
			num++;
			node = node->next;
		}
		return node;
	}
};

int main()
{	
	List list = List();
		
	list.AddFirst(0);
	list.AddFirst(1);	
	list.AddLast(5);
	list.AddAfter(2, 0);
	list.AddBefore(3, 5);
	list.Remove(5);
	list.RemoveLast();
	list.RemoveFirst();
	list.RemoveLast();
	list.Display();
	list.Clear();
	cout << endl;
	

	/*
	vector<int> tab = vector<int>();
	tab.push_back();
	tab.emplace_back();
	tab.size();
	tab.erase(tab.begin() + 5);
	tab[0] = 5;*/
}
