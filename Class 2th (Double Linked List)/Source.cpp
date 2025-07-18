#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
	struct Node
	{
		T data;
		struct Node* previous;
		struct Node* next;
	};

	int size;
	// 가장 앞의 노드를 가리키는 노드입니다.
	Node* head;
	// 가장 뒤의 노드를 가리키는 노드입니다.
	Node* tail;

public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	bool empty()
	{
		return (head == nullptr);
	}

	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (size == 0)
		{
			newNode->next = nullptr;
			newNode->previous = nullptr;

			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			newNode->previous = nullptr;

			head->previous = newNode;
			head = newNode;
		}

		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "'Linked List is Empty" << endl;
		}
		else if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
			size--;
		}
		else
		{
			Node* deleteNode = head;
			deleteNode->next->previous = nullptr;
			head = head->next;

			delete deleteNode;
			size--;
		}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			newNode->previous = nullptr;
			newNode->next = nullptr;

			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->previous = tail;
			newNode->next = nullptr;

			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}

	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		else
		{
			Node* deleteNode = tail;

			deleteNode->previous->next = nullptr;
			tail = tail->previous;

			delete deleteNode;
			size--;
		}
	}

	void remove(T data)
	{
		Node* currentNode = head;
		Node* previousNode = nullptr;

		while (currentNode != nullptr)
		{
			if (currentNode->data == data)
			{
				Node* deleteNode = currentNode;

				if (currentNode == head)
				{
					pop_front();
					currentNode = head;
					previousNode = nullptr;
				}
				else if (currentNode == tail)
				{
					pop_back();
					currentNode = nullptr;
				}
				else
				{
					currentNode->next->previous = previousNode;
					previousNode->next = currentNode->next;

					currentNode = currentNode->next;

					delete deleteNode;
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

	void print_data()
	{

		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* currentNode = head;

			for (int i = 0; i < size; i++)
			{
				cout << "List[" << i << "] : " << currentNode->data << endl;
				currentNode = currentNode->next;
			}
		}
	}

	void print_data_reverse()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* currentNode = tail;

			for (int i = 0; i < size; i++)
			{
				cout << "List[" << size - (i + 1) << "] : "
					<< currentNode->data << endl;

				currentNode = currentNode->previous;
			}
		}
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

	list.push_front(10);
	list.push_front(5);
	list.push_front(1);

	list.push_back(20);
	list.push_back(30);
	list.push_front(10);
	list.push_back(10);

	// 10 1 5 10 20 30 10
	// 1 5 20 30
	list.remove(10);

	list.print_data();
	cout << endl;
	list.print_data_reverse();

	cout << "List is Empty? : " << list.empty() << endl;

	return 0;
}