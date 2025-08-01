#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;
			next = link;
		}
	};
	
	int size;		// 정점의 개수
	int capacity;	// 최대 용량
	int count;		// 인접 리스트의 크기

	T* vertex;		// 정점의 집합
	Node** list;	// 인접 리스트(더블 포인터)
	
public:
	Graph()
	{
		size = 0;
		capacity = 0;
		count = 0;

		vertex = nullptr;
		list = nullptr;
		
	}

	void resize(int newSize)
	{
		capacity = newSize;
		T* newVertex = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			newVertex[i] = NULL;
		}

		if (vertex != nullptr)
		{
			if (capacity >= size)
			{
				for (int i = 0; i < size; i++)
				{
					newVertex[i] = vertex[i];
				}
			}
			delete[] vertex;
		}

		vertex = newVertex;
	}

	void resize()
	{
		Node** newList = new Node * [size];
		for (int i = 0; i < size; i++)
		{
			newList[i] = nullptr;
		}

		if (size >= count)
		{
			for (int i = 0; i < count; i++)
			{
				newList[i] = list[i];
			}

			delete[] list;
			list = newList;
			count = size;
		}
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (capacity <= size)
		{
			resize(2 * capacity);
		}

		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "Adjacency List is Empty" << endl;
		}
		else if (size <= i || size <= j)
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			if (list == nullptr)
			{
				list = new Node * [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = nullptr;
				}

				count = size;
			}
			else if (count <= size)
			{
				resize();
			}

			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}
	}

	~Graph()
	{
		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		for (int i = 0; i < size; i++)
		{
			if (list[i] != nullptr)
			{
				if (list[i]->next == nullptr)
				{
					delete list[i];
				}
				else
				{
					Node* deleteNode = list[i];
					Node* nextNode = list[i]->next;

					while (nextNode != nullptr)
					{
						delete deleteNode;
						deleteNode = nextNode;
						nextNode = nextNode->next;
					}
				}
			}
			else
			{
				continue;
			}
		}

		delete[] list;
	}
};

int main()
{
	// 퀘스트 : 상태 전이 그래프 DAG
	// 인접리스트는 선행 조건 탐색이 비효율적, 중간에 퀘스트라인 파악이 어려움
	// 정점이 적고 간선이 많다 >> 인접행렬 구조
	// 정점이 많고 간선이 적다 >> 인접리스트 구조
	// KENNEY 에셋사이트!

	Graph<int> graph;
	
	graph.push(10);
	graph.push(20);
	graph.push(30);
	graph.edge(0, 2);

	graph.push(40);
	graph.push(50);

	graph.edge(0, 4);
	graph.edge(0, 6);


	return 0;
}
