#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>
class Queue
{
private:
	//
	int rear;
	//
	int front;

	T container[SIZE];

public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (rear < SIZE)
		{
			container[rear++] = data;
		}
		else
		{
			cout << "Linear Queue is Overflow" << endl;
		}
	}

	const bool& empty() { return (front == rear); }

	void pop()
	{
		if (empty() == true)
		{
			cout << "Linear Queue is Empty" << endl;
		}
		else
		{
			container[front++] = NULL;
		}
	}

	const int& size()
	{
		return (rear - front);
	}

	const T& peek()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[front];
		}
	}
};


// Queue 구현 (선형 큐와 원형 큐)
// 선형 큐의 문제점을 해결한 구조가 원형 큐
// rear가 선형적으로 증가하며, rear가 size끝까지 도달했을때
// 큐가 비어있어도 더이상 넣지 못하는 현상이 발생
// Last-in Last-Out
int main()
{
	// 선형 큐 (정적 배열로 잡아야함)

	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;
		queue.pop();
	}

	queue.push(60);

	return 0;
}