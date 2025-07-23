#include <iostream>

using namespace std;

#define SIZE 4

template<typename T>
class Queue
{
private:
	int rear;
	int front;
	T container[SIZE];

public:
	Queue()
	{
		rear = (SIZE - 1);
		front = (SIZE - 1);

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		checkfront = front;
		checkfront += (SIZE - 1);
		checkfront %= SIZE;

		if (checkfront == rear) return;

		++rear;
		rear %= SIZE;

		container[rear] = data;
	}
};

// Queue 구현 (선형 큐와 원형 큐)
// 선형 큐의 문제점을 해결한 구조가 원형 큐
// rear가 선형적으로 증가하며, rear가 size끝까지 도달했을때
// 큐가 비어있어도 더이상 넣지 못하는 현상이 발생

// 원형 큐는 메모리 하나를 비워둔다.(재활용 할 수 있게.)
// 크기는 고정(정적 배열)
// Last-in Last-Out
int main()
{
	

	return 0;
}