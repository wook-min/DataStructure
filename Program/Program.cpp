#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue
{
private:
	int index;
	int capacity;
	T* container;
public:
	PriorityQueue()
	{
		index = 0;
		capacity = 0;
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

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = temporary;
	}

	const bool& empty() { return (index == 0); }

	const int& size() { return index; }

	const T& top() 
	{ 
		if (index <= 0)
		{
			cout << "PriorityQueue is Empty" << endl;
			return NULL;
		}
		else
		{
			return container[0];
		}
	}

	void push(T data)
	{
		if (index <= 0)
		{
			resize(1);
		}
		else if (index >= capacity)
		{
			resize(capacity * 2);
		}

		container[index] = data;

		int child = index;
		int parent = (child - 1) / 2;

		while (child != 0)
		{
			if (container[child] >= container[parent])
			{
				swap(container[parent], container[child]);
			}

			child = parent;
			parent = (child - 1) / 2;
		}

		index++;
	}

	~PriorityQueue()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}
};



// 우선순위 큐 구현(Priority Queue)
// 부모 자식 노드로 이루어져 있으며, 작은 노드는 왼쪽으로, 큰 노드는 우측으로 보내집니다.
// 가장 큰 값이 항상 top에 위치합니다.
int main()
{
	PriorityQueue<int> priorityQueue;

	priorityQueue.push(10);
	priorityQueue.push(20);
	priorityQueue.push(30);
	priorityQueue.push(40);
	priorityQueue.push(50);

	cout << priorityQueue.top() << endl;

	return 0;
}