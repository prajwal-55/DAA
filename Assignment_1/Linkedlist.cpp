#include<iostream> 
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    void deleteNode(int data)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->data == data)
        {
            head = head->next;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }
    bool search(int data)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void reverse()
    {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main()
{
    LinkedList list;
    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtEnd(3);
    list.printList();
    list.deleteNode(2);
    list.printList();
    cout << "Searching for 4: " << list.search(4) << std::endl;
    cout << "Searching for 3: " << list.search(3) << std::endl;
    cout << "Reverse List"
         << " ";
    list.reverse();
    list.printList();
    return 0;
}
