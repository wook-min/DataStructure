#include <iostream>

using namespace std;

// 그래프 자료구조 (Graph Database) 구현
// 길찾기(경로 당 가중치 고려), 퀘스트라인
// - 그래프의 요소들
// 1. vertex : 다양한 데이터 자료를 가지는 하나의 객체(int, float, string...)
// 2. edge : 두 vertex 사이를 연결하는 간선
// - 그래프의 종류
// 1. 방향 그래프 : vertex 사이의 edge에 가는 방향이 존재하는 그래프
// >> 진입 차수 : 해당 vertex로 들어갈 수 있는 차수
// >> 진출 차수 : 해당 vertex에서 나갈 수 있는 차수
// 2. 무방향 그래프 : vertex 사이에 있는 edge를 통한 진입과 진출이 자유로운 그래프
// 진입과 진출 차수가 연결된 edge 수와 같음
// 3. 가중치 그래프 : edge(간선)에 가중치가 존재하는 그래프
// cycle이란 개념 : 하나의 vertex에서 vertex를 통해 돌고 돌아 다시 원래의 정점으로
// 올 수 있다면, cycle이 존재한다는 개념
// 자기 자신을 가리키는 vertex도 존재하며, 이것도 cycle이라 본다.
// (일일퀘스트가 이에 해당, 조건이 맞으면 다시 시작)
// - 그래프의 표현
// 1. 인접 행렬
// 3 x 3 행렬을 표현하기 위해, 3개의 vertex로 이루어진 그래프가 필요
// 예를 들어, a-b, b-c인 무방향 그래프의 경우 대각 행렬
//		a	b	c
// a	0	1	0
// b	1	0	1
// c	0	1	0
// 으로 표현이 가능하다.
// 이중 포인터로 동적 2차원 배열을 만들어 구현가능
// 2. 인접 리스트


// Graph class 필요한것
// 정점의 개수, 정점의 집합, 정점의 최대 용량
// void push(T data)
// capacity 존재(resize 필요)
template <typename T>
class Graph
{
private:
	// 정점의 개수
	int size;
	// 정점 집합
	T* vertex;
	// 정점의 최대 용량
	int capacity;
	// 인접 행렬 (int or bool) 더블 포인터
	int** matrix;
	// 인접 행렬의 크기 (count)
	int count;

public:
	Graph()
	{
		size = 0;
		capacity = 0;
		count = 0;
		vertex = nullptr;
		matrix = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;
		T* container = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			container[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			container[i] = vertex[i];
		}

		if (vertex != nullptr)
		{
			delete[] vertex;
		}

		vertex = container;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else
		{
			if (size >= capacity)
			{
				resize(2 * capacity);
			}
		}

		vertex[size++] = data;
	}

	// 1. 간선을 연결할 vertex이 없을 경우, 인접행렬이 없다고 출력.
	// 2. 현존하는 vertex의 크기를 벗어나게 호출할 경우, 배열의 범위를 벗어났다고 출력.

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "Adjacency Matrix is Empty" << endl;
			return;
		}
		else if (i > size || j > size)
		{
			cout << "Index Out of Vertex Range" << endl;
		}
		else
		{
			if (matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int x = 0; x < size; x++)
				{
					matrix[x] = new int[size];
				}

				for (int x = 0; x < size; x++)
				{
					for (int y = 0; y < size; y++)
					{
						matrix[x][y] = 0;
					}
				}
				
			}

			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	~Graph()
	{
		if (vertex != nullptr) delete[] vertex;

		if (matrix != nullptr)
		{
			for (int i = 0; i < count; i++)
			{
				delete[] matrix[i];
			}

			delete[] matrix;
		}
	}
};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');


	graph.edge(0, 1);
	graph.edge(0, 2);
	

	return 0;
}
