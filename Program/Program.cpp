#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	struct Node
	{
		T data;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(T data)
		{
			this->data = data;
		}
	};


	Node* root;
public:
	Set()
	{
		root = nullptr;
	}

	void insert(T data)
	{
		Node* newNode = new Node(data);
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
				if (newNode->data == currentNode->data)
				{
					delete newNode;
					return;
				}
				else
				{
					if (newNode->data < currentNode->data)
					{
						if (currentNode->left == nullptr)
						{
							currentNode->left = newNode;
							break;
						}
						else
						{
							currentNode = currentNode->left;
						}

					}
					else
					{
						if (currentNode->right == nullptr)
						{
							currentNode->right = newNode;
							break;
						}
						else
						{
							currentNode = currentNode->right;
						}
					}
				}
			}
		}
	}

	void release(Node* root)
	{
		if (root == nullptr) return;

		release(root->left); // 왼쪽 끝까지 이동
		release(root->right); // 그 후 우측으로 이동

		delete root; // 노드 삭제 후 이전 release로 이동

	}

	// 고려할 조건
	// 1. 자식 노드가 하나도 없을 때
	// 2. 자식 노드가 하나만 있을 때
	// 3. 자식 노드가 둘 다 있을 때
	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentsNode = root;
		int check = -1;

		if (currentNode == nullptr)
		{
			cout << "Node doesn't have data" << endl;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (data < currentNode->data)
				{
					parentsNode = currentNode;
					currentNode = currentNode->left;
					check = 0;
				}
				else if (data > currentNode->data)
				{
					parentsNode = currentNode;
					currentNode = currentNode->right;
					check = 1;
				}
				else
				{
					if (currentNode == root)
					{
						root = nullptr;
						delete currentNode;
						break;
					}
					else
					{
						// 자식이 두개 있을 때
						if (currentNode->left != nullptr && currentNode->right != nullptr)
						{
							break;
						}
						// 자식이 하나만 있을 때
						else if (currentNode->left != nullptr)
						{
							break;
						}
						else if (currentNode->right != nullptr)
						{
							break;
						}
						// 자식이 없을 때
						else
						{
							switch (check)
							{
							case 0:
								parentsNode->left = nullptr;
								delete currentNode;
								break;
							case 1:
								parentsNode->right = nullptr;
								delete currentNode;
								break;
							}
							break;
						}
					}
				}
			}

			cout << "Node doesn't have data" << endl;
		}
	}

	void erase(T data, int a)
	{
		Node* currentNode = root;

		while (currentNode != nullptr && currentNode->data != data)
		{
			if (currentNode->data > data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}
	}

	~Set()
	{
		if (root != nullptr)
		{
			release(root);
		}
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
