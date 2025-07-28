#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket* bucket;
	int size;
public:
	HashTable()
	{
		size = 8;
		bucket = new Bucket[size];
		for (int i = 0; i < size; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}
		
	}

	unsigned int hash_function(KEY key)
	{
		// const char*는 주소값이라 다른 문자열이라도 주소값이 비슷하여
		// 해시 값이 동일할 수 있습니다
		// 1. const char*만의 예외적인 처리 방식을 지정하세요.
		// 2. 또는 std::string을 사용하세요.
		std::hash<KEY> hash;
		return hash(key) % size;
	}

	// Insert 함수 구현
	// 1. 해시 함수를 통해 값을 받는 임시 변수 hashIndex 생성
	// 2. 새로운 노드를 작성해서, 얻은 key, value, *next 입력
	void insert(KEY key, VALUE value)
	{
		int hashIndex = hash_function(key);

		Node* newNode = new Node;
		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		// 노드가 1개라도 존재하지 않는다면
		if (bucket[hashIndex].head == nullptr)
		{
			// bucket[hashIndex]의 head 포인터가 newNode를 가리키게 합니다.
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;
			bucket[hashIndex].head = newNode;
		}

		// bucket[hashIndex]의 count를 증가시킵니다.
		bucket[hashIndex].count++;
	}

	const int& bucket_count()
	{
		return size;
	}

	// 1. 해시 함수를 통해서 값을 받는 임시 변수 (int hashIndex)
	// 2. Node를 탐색할 수 있는 토인터 변수 선언 (Node* currentNode)
	// 3. 이전 Node를 저장할 수 있는 포인터 변수가 필요 (Node* previousNode)
	// 4. currentNode 가 nullptr과 같다면 함수를 종료합니다.
	void erase(KEY key)
	{
		int hashIndex = hash_function(key);

		Node* currentNode = bucket[hashIndex].head;
		Node* previousNode = nullptr;

		if (currentNode == nullptr)
		{
			cout << "Key doesn't Exist" << endl;
			return;
		}
		else
		{
			int count = bucket[hashIndex].count;

			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					Node* deleteNode = currentNode;
					currentNode = currentNode->next;
					
					if (previousNode == nullptr)
					{
						bucket[hashIndex].head = bucket[hashIndex].head->next;
					}
					else
					{
						previousNode->next = currentNode;
					}
	
					delete deleteNode;
					bucket[hashIndex].count--;
				}
				else
				{
					previousNode = currentNode;
					currentNode = currentNode->next;
				}
			}

			if (count == bucket[hashIndex].count)
			{
				cout << "Key doesn't Exist" << endl;
			}
		}

	}
};

// Hash Table 구현
// size 8로 이루어진 동적 배열 구조
// Key, Value 값을 기준으로 구현함

// 해시 충돌 예방 방법
// 체이닝, 
// Open Addresing(개방주소법)
// (선형 탐사법(Linear Probing), 제곱 탐사법(Quadratic Probing), 이중 해싱(Double Probing))

// 리해시가 일어난다면 시간복잡도가 증가
// 
int main()
{
	HashTable<std::string, int> hashtable;

	// cout << hashtable.hash_function("Operator") << endl;
	// cout << hashtable.hash_function("Yahoo") << endl;
	// cout << hashtable.hash_function("Zazaza") << endl;

	hashtable.insert("first", 10);
	hashtable.insert("second", 20);
	hashtable.insert("third", 30);

	// cout << hashtable.bucket_count() << endl;

	hashtable.erase("first");
	hashtable.erase("first");
	hashtable.erase("two");

	
	return 0;
}