#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int capacity;
	int highset;

	T* container;
public:
	Stack()
	{
		capacity = 0;
		highset = -1;
		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;
		T* temporary = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < (highset + 1); i++)
		{
			temporary[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (highset + 1 >= capacity)
		{
			resize(capacity * 2);
		}

		container[++highset] = data;
	}

	const bool& empty() { return (highset <= -1); }

	const int& size() { return (highset + 1); }

	const T& top() { return container[highset]; }

	void pop()
	{
		if (highset <= -1) { cout << "Stack is Empty" << endl; }
		else
		{
			container[highset--] = NULL;
		}
	}

	~Stack()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};

// stack 구현
// Last-in First-out
int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.push(60);
	stack.push(70);
	stack.push(80);
	stack.push(90);

	cout << "Stack Size : " << stack.size() << "\n" << endl;

	while (!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}

	stack.pop();


	return 0;
}