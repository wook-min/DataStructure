#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	int size;

	Node* root;
public:
	Set()
	{
		size = 0;

		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node[data];
		newNode->left = nullptr;
		newNode->right = nullptr;

		if (root == nullptr)
		{
			root = newNode;
		}
		else
		{
			Node* currentNode = root;
			while (currentNode != nullptr)
			{
				if (newNode->data < currentNode->data)
				{
					currentNode = currentNode->left;
				}
				else if (newNode->data == currentNode->data)
				{
					cout << "Node already have " << newNode->data << endl;
					return;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}

			currentNode = newNode;
		}

		size++;
	}

};


// 이진 트리 구현
int main()
{
	// 트리 용어
	// vertex와 Node : 트리를 구성하는 기본 요소
	// Node는 데이터를 담는 data, left, right 자식 포인터로 구성
	// edge : vertex 사이를 연결해주는 간선
	// Root Node : 트리의 최상단에 위치한 노드
	// 이진 탐색 트리 : 좌측 자식노드에는 작은 값을, 우측 자식노드에는 큰 값을 배치
	// Leaf Node : 자식을 가지지 않은 노드
	// 트리의 종류
	// 완전 이진 트리 : 왼쪽에서부터 채워진 트리
	// 편향 이진 트리 : 트리가 오른쪽으로 치우쳐서 시간 복잡도가 0(n)과 유사하게 된 트리

	Set<int> set;

	set.insert(10);
	set.insert(5);
	set.insert(15);
	set.insert(7);
	set.insert(18);

	return 0;
}
