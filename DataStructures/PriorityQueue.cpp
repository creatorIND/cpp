#include <iostream>
#include <vector>

class Node
{
public:
    int value;
    int priority;

    Node(int val, int prio)
    {
        value = val;
        priority = prio;
    }
};

class PriorityQueue
{
private:
    std::vector<Node *> heap;

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int leftChild(int index)
    {
        return (2 * index) + 1;
    }

    int rightChild(int index)
    {
        return (2 * index) + 2;
    }

    void heapifyUp(int index)
    {
        if (index == 0)
            return;

        int parentIndex = parent(index);
        if (heap[index]->priority < heap[parentIndex]->priority)
        {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex]->priority < heap[smallestIndex]->priority)
        {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex]->priority < heap[smallestIndex]->priority)
        {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex != index)
        {
            std::swap(heap[index], heap[smallestIndex]);
            heapifyDown(smallestIndex);
        }
    }

public:
    void enqueue(int value, int priority)
    {
        Node *newNode = new Node(value, priority);
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    int dequeue()
    {
        if (heap.empty())
        {
            throw std::out_of_range("Priority queue is empty.");
        }

        int minValue = heap[0]->value;
        delete heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

int main()
{
    PriorityQueue pq;

    // Enqueue elements with priorities
    pq.enqueue(5, 2);
    pq.enqueue(10, 1);
    pq.enqueue(3, 4);
    pq.enqueue(7, 3);

    // Dequeue elements based on priority
    while (!pq.isEmpty())
    {
        std::cout << pq.dequeue() << " ";
    }

    std::cout << std::endl;

    return 0;
}