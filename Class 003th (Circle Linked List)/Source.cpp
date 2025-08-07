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

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		size++;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			if (head->next == head || size == 1)
			{
				head = nullptr;
			}
			else
			{
				Node* deleteNode = head->next;
				head->next = deleteNode->next;

				delete deleteNode;
			}
			size--;
		}
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* currentNode = head;
			Node* deleteNode = head;

			if (head->next == head)
			{
				head == nullptr;
			}
			else
			{
				for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;
				head = currentNode;
			}

			delete deleteNode;
			size--;
		}
	}

	void print_data()
	{
		if (size == 0)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* currentNode = head->next;

			for (int i = 0; i < size; i++)
			{
				cout << "List [" << i << "] : " << currentNode->data << endl;
				currentNode = currentNode->next;
			}
		}
	}

	void remove(T data)
	{
		Node* currentNode = head;
		Node* previousNode = nullptr;

		int count = size;

		if (currentNode == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (currentNode->data == data)
				{
					if (currentNode == head)
					{
						currentNode = currentNode->next;
						pop_back();
					}
					else if (currentNode == head->next)
					{
						currentNode = currentNode->next;
						pop_front();
					}
					else
					{
						if (previousNode != nullptr)
						{
							previousNode->next = currentNode->next;
							delete currentNode;
							currentNode = previousNode->next;
						}
						size--;
					}
				}
				else
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}
		}
	}

	bool empty()
	{
		return (head == nullptr);
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(5);

	list.push_front(5);
	list.push_front(3);
	list.push_front(10);

	// list.pop_front();
	// list.pop_back();

	list.remove(10);
	list.remove(5);

	list.print_data();

	cout << "\n" << "List Empty ? : " << list.empty() << endl;

	return 0;
}