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

    bool empty()
    {
        return (head == nullptr);
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
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }
        size++;
    }

    void pop_back()
    {
        if (size <= 0)
        {
            cout << "Linked List is Empty" << endl;
        }
        else if (size == 1)
        {
            Node* deleteNode = head;
            head = deleteNode->next;
            delete deleteNode;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;
            while (deleteNode->next != nullptr)
            {
                previousNode = deleteNode;
                deleteNode = deleteNode->next;
            }
            
            previousNode->next = nullptr;
            delete deleteNode;

        }
        size--;
    }

    void remove(T data)
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;

            while (deleteNode->next != nullptr)
            {
                if (deleteNode->data == data)
                {
                    if (deleteNode == head)
                    {
                        head = head->next;
                        previousNode = deleteNode;
                        delete deleteNode;
                        deleteNode = deleteNode->next;
                    }
                    else
                    {
                        delete deleteNode;
                        deleteNode = deleteNode->next;
                        previousNode = deleteNode;
                    }
                   

                }

                previousNode = deleteNode;
                deleteNode = deleteNode->next;
            }
        }
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
        while (head != nullptr)
        {
            pop_front();
        }
    }
};


int main()
{
    List<int> list;
    list.push_front(10);
    list.push_front(5);
    list.push_front(1);

    list.push_back(10);
    list.push_back(30);

    list.remove(10);

    list.print_data();

    //cout << "List is Empty? : " << list.empty() << endl;


    return 0;
}
