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

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        std::cout << value << " pushed to the stack." << std::endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow! Unable to pop." << std::endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        std::cout << poppedValue << " popped from the stack." << std::endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}