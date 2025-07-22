#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	int count;
	int capacity;
	int highset;

	T* container;
public:
	Stack()
	{
		count = 0;
		capacity = 0;
		highset = -1;
		container = nullptr;
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


	return 0;
}