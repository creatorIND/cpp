#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        std::cout << "***Destructor called***" << std::endl;
        while (!isEmpty())
        {
            dequeue();
        }
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " enqueued" << std::endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node *temp = front;
        int dequeueValue = front->data;
        front = front->next;

        // if dequeued element was the last element, update rear
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        std::cout << dequeueValue << " dequeued." << std::endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }
};

int main()
{
    Queue q;

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    std::cout << "Front element: " << q.peek() << std::endl;

    q.dequeue();

    std::cout << "Front element after one dequeue: " << q.peek() << std::endl;

    return 0;
}