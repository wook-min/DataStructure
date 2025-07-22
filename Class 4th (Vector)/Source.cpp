#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int count;
	int capacity;
	T* container;
public:
	Vector()
	{
		count = 0;
		capacity = 0;
		container = nullptr;
	}

	// 1. capacity에 새로운 size 값을 저장합니다.(count > capacity 인 경우)
	// 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록 합니다.
	// 3. 새로운 메모리 공간의 값을 초기화합니다.(NULL로)
	// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줍니다.
	// capacity는 1.5배 정도로 늘려줍니다.
	// 5. 기존 배열의 메모리를 해제합니다.
	// 6. 기존에 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가리킵니다.
	void resize(int newSize)
	{
		capacity = newSize;
		T* temporary = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < count; i++)
		{
			temporary[i] = container[i];
		}

		if (container != nullptr)
		{
			delete[] container;
		}

		container = temporary;
	}

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else
		{
			if (count >= capacity)
			{
				resize(2 * capacity);
			}
		}

		container[count++] = data;
	}

	const int& size()
	{
		return count;
	}

	const T& operator [] (const int& index)
	{
		return container[index];
	}

	void pop_back()
	{
		if (count <= 0)
		{
			cout << "Vector is Empty" << endl;
		}
		else
		{
			container[count--] = NULL;
		}
	}

	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}

	}
};

int main()
{

	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	for (int i = 0; i < vector.size(); i++)
	{
		cout << "Vector[" << i << "] : " << vector[i] << endl;
	}

	vector.pop_back();

	cout << "\n";

	for (int i = 0; i < vector.size(); i++)
	{
		cout << "Vector[" << i << "] : " << vector[i] << endl;
	}

	// 벡터는 foreach 문 인덱스를 위해 이터레이터를 사용해야함

	return 0;
}