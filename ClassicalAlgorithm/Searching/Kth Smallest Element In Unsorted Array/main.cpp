/*
 * File: main.cpp
 * Project: KthSmallestElementInUnsortedArray
 * File Created: Wednesday, 22nd June 2022 11:21:56 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int n, int k)
{

    // For finding min element we need (Max heap)priority queue
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        // First push first K elememts into heap
        pq.push(arr[i]);
    }
    // Now check from k to last element
    for (int i = k; i < n; i++)
    {

        // If current element is < top that means
        // there are  other k-1 lesser elements
        // are present at bottom thus, pop that element
        // and add kth largest element into the heap till curr
        // at last all the greater element than kth element will get pop off
        // and at the top of heap there will be kth smallest element
        if (arr[i] < pq.top())
        {
            pq.pop();
            // Push curr element
            pq.push(arr[i]);
        }
    }

    // Return top of element
    return pq.top();
}

// Driver's code:
int main()
{
    int n = 10;
    int arr[n] = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    cout << "Kth Smallest Element is: " << kthSmallest(arr, n, k) << endl;
    return 0;
}