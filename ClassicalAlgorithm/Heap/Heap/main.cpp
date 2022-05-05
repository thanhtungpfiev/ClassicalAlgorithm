/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/1/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap
{
private:
    vector<int> harr; // array of elements in heap
    int capacity; // maximum possible size of min heap

public:
    // Constructor
    MinHeap(int capacity);
    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
    // ti get parent of node at index i
    int parent(int i) { return (i-1)/2; }
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
    // to extract the root which is the minimum element
    int extractMin();
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
    // Deletes a key stored at index i
    void deleteKey(int i);
    // Inserts a new key 'k'
    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    capacity = cap;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < harr.size() && harr[l] < harr[i]) {
        smallest = l;
    }
    if (r < harr.size() && harr[r] < harr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin()
{
    if (harr.size() <= 0) {
        return INT_MAX;
    }
    if (harr.size() ==  1) {
        int temp = harr.front();
        harr.pop_back();
        return temp;
    }
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[harr.size() - 1];
    harr.pop_back();
    MinHeapify(0);
    return root;

}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k)
{
    if (harr.size() == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // First insert the new key at the end
    harr.push_back(k);
    int i = harr.size() - 1;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;
    return 0;
}
