#include <iostream>
#include <vector>

class MaxHeap
{
private:
    std::vector<int> heap;

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
        if (heap[index] > heap[parentIndex])
        {
            std::swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index)
    {
        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);
        int largestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largestIndex])
        {
            largestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largestIndex])
        {
            largestIndex = rightChildIndex;
        }

        if (largestIndex != index)
        {
            std::swap(heap[index], heap[largestIndex]);
            heapifyDown(largestIndex);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void removeMax()
    {
        if (heap.empty())
            return;

        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax()
    {
        if (heap.empty())
        {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void printHeap()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(20);
    maxHeap.insert(7);

    maxHeap.printHeap();

    maxHeap.removeMax();

    maxHeap.printHeap();

    std::cout << "Max element: " << maxHeap.getMax() << std::endl;

    return 0;
}