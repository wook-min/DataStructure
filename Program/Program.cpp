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
	}

	const int& hash_function(KEY key)
	{
		return ((unsigned int)key % size);
	}
};



// 

// Hash Table 구현
// size 8로 이루어진 동적 배열 구조
// Key, Value 값을 기준으로 구현함

// 해시 충돌 예방 방법
// 체이닝, 
// Open Addresing(개방주소법)
// (선형 탐사법(Linear Probing), 제곱 탐사법(Quadratic Probing), 이중 해싱(Double Probing))
int main()
{
	HashTable<const char*, int> hashtable;

	cout << hashtable.hash_function("aabb");
	cout << hashtable.hash_function("BBB");

	
	return 0;
}