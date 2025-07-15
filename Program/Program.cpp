#include <iostream>


using namespace std;


template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    int size;
    Node* head;

public:
    List() 
    { 
        size = 0;
        head = nullptr;
    }

    int empty()
    {
        if (size == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (size == 0)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
        {
            Node* deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
            size--;
        }
    }

    void push_back(T data)
    {
        Node* currentNode = head;
        while (currentNode->next == nullptr)
        {
            currentNode = currentNode->next;
        }

        Node* newNode = new Node;
        newNode->data = data;
        currentNode->next = newNode;
        newNode->next = nullptr;
    }

    void print_data()
    {
        if (size == 0)
        {
            cout << "List size is 0" << endl;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < size; i++)
            {
                cout << "List [" << i << "] : " << current->data << endl;
                current = current->next;
            }
        }
    }

    ~List() 
    {
        if (head != nullptr)
        {
            Node* current = head;
            while (current != nullptr)
            {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
    }
};


int main()
{
    List<int> list;
    list.push_front(10);
    list.push_front(5);
    list.push_front(1);

    list.push_back(3);

    list.print_data();



    return 0;
}
