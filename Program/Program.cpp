#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;
public:
	List()
	{
		size = 0;
		head = nullptr;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
			head->next = newNode;
		}
		else
		{
			newNode->next = head;
			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void print_data()
	{
		if (size == 0)
		{

		}
	}
};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	return 0;
}