/*
 * File: main.cpp
 * Project: MaxHeap
 * File Created: Monday, 18th July 2022 1:52:37 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    static const int CAPACITY = 16;
    int size;             // Number of elements in heap
    std::vector<int> arr; // The heap array
    void proclateDown(int position);
    void proclateUp(int position);

public:
    Heap();
    Heap(std::vector<int> &array_in);
    virtual void add(int value);
    virtual int remove();
    virtual bool isEmpty();
    virtual int peek();
    static void heapSort(std::vector<int> &array_in);
};

Heap::Heap()
{
    arr = std::vector<int>(CAPACITY);
    size = 0;
}

Heap::Heap(std::vector<int> &array_in)
{
    size = array_in.size();
    arr = std::vector<int>(array_in.size() + 1);
    auto it = arr.begin();
    copy(array_in.begin(), array_in.end(), ++it); // we do not use 0 index
    // Build Heap operation over array
    for (int i = (size / 2); i > 0; i--)
    {
        proclateDown(i);
    }
}
void Heap::proclateDown(int position)
{
    int lChild = 2 * position;
    int rChild = lChild + 1;
    int small = -1;
    int temp;
    if (lChild <= size)
    {
        small = lChild;
    }
    if (rChild <= size && (arr[rChild] - arr[lChild]) < 0)
    {
        small = rChild;
    }
    if (small != -1 && (arr[small] - arr[position]) < 0)
    {
        temp = arr[position];
        arr[position] = arr[small];
        arr[small] = temp;
        proclateDown(small);
    }
}
bool Heap::isEmpty()
{
    return (size == 0);
}
int Heap::peek()
{
    if (isEmpty())
        throw std::runtime_error("Heap empty exception.");
    return arr[1];
}

void Heap::add(int value)
{
    arr[++size] = value;
    proclateUp(size);
}
void Heap::proclateUp(int position)
{
    int parent = position / 2;
    int temp;
    if (parent == 0)
        return;
    if ((arr[parent] - arr[position]) < 0)
    {
        temp = arr[position];
        arr[position] = arr[parent];
        arr[parent] = temp;
        proclateUp(parent);
    }
}

int Heap::remove()
{
    if (isEmpty())
        throw std::runtime_error("HeapEmptyException.");
    int value = arr[1];
    arr[1] = arr[size];
    size--;
    proclateDown(1);
    return value;
}

void Heap::heapSort(std::vector<int> &array_in)
{
    Heap *hp = new Heap(array_in);
    for (int i = 0; i < array_in.size(); i++)
    {
        array_in[i] = hp->remove();
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}