#include <iostream>

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Error: List is empty." << std::endl;
            return -1; // or throw an exception
        }

        Node *removedNode = tail;
        int removedValue = removedNode->data;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
            removedNode->prev = nullptr;
        }
        delete removedNode;
        length--;
        return removedValue;
    }

    int shift()
    {
        if (isEmpty())
        {
            std::cout << "Error: List is empty." << std::endl;
            return -1; // or throw an exception
        }

        Node *removedNode = head;
        int removedValue = removedNode->data;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            removedNode->next = nullptr;
        }
        delete removedNode;
        length--;
        return removedValue;
    }

    void unshift(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Error: Invalid index." << std::endl;
            return nullptr; // or throw and exception
        }

        Node *currentNode;
        if (index <= length / 2)
        {
            currentNode = head;
            for (int i{0}; i < index; i++)
            {
                currentNode = currentNode->next;
            }
        }
        else
        {
            currentNode = tail;
            for (int i{length - 1}; i > index; i--)
            {
                currentNode = currentNode->prev;
            }
        }
        return currentNode;
    }

    bool set(int index, int value)
    {
        Node *node = get(index);
        if (node != nullptr)
        {
            node->data = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Error: Invalid index." << std::endl;
            return false; // or throw an exception
        }

        if (index == 0)
        {
            unshift(value);
        }
        else if (index == length)
        {
            push(value);
        }
        else
        {
            Node *beforeNode = get(index - 1);
            Node *afterNode = beforeNode->next;
            Node *newNode = new Node(value);
            newNode->prev = beforeNode;
            beforeNode->next = newNode;
            newNode->next = afterNode;
            afterNode->prev = newNode;
            length++;
        }
        return true;
    }

    bool remove(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Error: Invalid index." << std::endl;
            return false; // or throw an exception
        }

        if (index == 0)
        {
            shift();
        }
        else if (index == length - 1)
        {
            pop();
        }
        else
        {
            Node *removedNode = get(index);
            Node *beforeNode = removedNode->prev;
            Node *afterNode = removedNode->next;
            beforeNode->next = afterNode;
            afterNode->prev = beforeNode;
            removedNode->prev = nullptr;
            removedNode->next = nullptr;
            delete removedNode;
            length--;
        }
        return true;
    }

    void reverse()
    {
        Node *currentNode = head;
        Node *temp = nullptr;
        while (currentNode != nullptr)
        {
            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;
            currentNode = currentNode->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }

    bool isEmpty()
    {
        return (length == 0);
    }

    void printList()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.printList(); // Output: 1 2 3 4

    list.shift();
    list.pop();
    list.printList(); // Output: 2 3

    list.unshift(1);
    list.unshift(0);
    list.printList(); // Output: 0 1 2 3

    list.set(2, 10);
    list.printList(); // Output: 0 1 10 3

    list.insert(2, 5);
    list.printList(); // Output: 0 1 5 10 3

    list.remove(1);
    list.printList(); // Output: 0 5 10 3

    list.reverse();
    list.printList(); // Output: 3 10 5 0

    return 0;
}