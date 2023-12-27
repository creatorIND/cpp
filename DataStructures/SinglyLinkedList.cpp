#include <iostream>

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    SinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // adding a new node to the end
    void push(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // removing a node from the end
    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Cannot pop from an empty list." << std::endl;
            return -1; // return a default value to indicate failure
        }

        int poppedValue{tail->value};
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        length--;
        return poppedValue;
    }

    // removing a node from the beginning
    int shift()
    {
        if (isEmpty())
        {
            std::cout << "Cannot shift from an empty list." << std::endl;
            return -1;
        }

        int shiftedValue{head->value};
        Node *temp = head;
        head = head->next;
        delete temp;
        length--;
        return shiftedValue;
    }

    // adding a new node to the beginning
    void unshift(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // retrieving a node by its position
    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Index out of bounds." << std::endl;
            return nullptr;
        }

        Node *current = head;
        for (size_t i{0}; i < index; i++)
        {
            current = current->next;
        }
        return current;
    }

    // changing the value of a node based on its position
    bool set(int index, int value)
    {
        Node *node = get(index);
        if (node == nullptr)
        {
            return false;
        }
        node->value = value;
        return true;
    }

    // adding a node at a specific position
    bool insert(int index, int value)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Index out of bounds." << std::endl;
            return false;
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
            Node *prev = get(index - 1);
            Node *nextNode = prev->next;
            Node *newNode = new Node(value);
            prev->next = newNode;
            newNode->next = nextNode;
            length++;
        }
        return true;
    }

    // removing a node at a specific position
    int remove(int index)
    {
        if (index < 0 || index >= length)
        {
            std::cout << "Index out of bounds." << std::endl;
            return -1;
        }

        if (index == 0)
        {
            return shift();
        }
        else if (index == (length - 1))
        {
            return pop();
        }
        else
        {
            Node *prev = get(index - 1);
            Node *removedNode = prev->next;
            Node *nextNode = removedNode->next;
            int removedValue = removedNode->value;
            prev->next = nextNode;
            delete removedNode;
            length--;
            return removedValue;
        }
    }

    // reversing the linked list in place
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        tail = head;
        head = prev;
    }

    // check if the list is empty
    bool isEmpty()
    {
        return (length == 0);
    }

    void printList()
    {
        if (isEmpty())
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    SinglyLinkedList list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);
    list.push(39);
    list.push(22);
    list.push(90);

    std::cout << "Original list: ";
    list.printList();

    // std::cout << "Length: " << list.length << std::endl;

    // int poppedValue = list.pop();
    // std::cout << "Popped value: " << poppedValue << std::endl;
    // std::cout << "After popping: ";
    // list.printList();

    // int shiftedValue = list.shift();
    // std::cout << "Shifted value: " << shiftedValue << std::endl;
    // std::cout << "After shifting: ";
    // list.printList();

    // list.unshift(50);
    // std::cout << "After unshifting: ";
    // list.printList();

    // Node *getNode = list.get(1);
    // if (getNode != nullptr)
    // {
    //     std::cout << "get(1): " << getNode->value << std::endl;
    // }

    // bool setResult = list.set(2, 60);
    // if (setResult)
    // {
    //     std::cout << "After setting value: ";
    //     list.printList();
    // }

    // bool insertResult = list.insert(2, 70);
    // if (insertResult)
    // {
    //     std::cout << "After inserting value: ";
    //     list.printList();
    // }

    // int removeValue = list.remove(3);
    // std::cout << "Removed value: " << removeValue << std::endl;
    // std::cout << "After removing: ";
    // list.printList();

    list.reverse();
    std::cout << "After reversing: ";
    list.printList();

    return 0;
}