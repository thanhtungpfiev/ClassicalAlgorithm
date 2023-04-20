#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxSubArray(const std::vector<int>& arr)
{
    int result = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i; j < arr.size(); ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += arr[k];
            }
            result = max(sum, result);
        }
    }
    return result;
}

int findMaxSubArray2(const std::vector<int>& arr)
{
    int result = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        int sum = 0;
        for (int j = i; j < arr.size(); ++j) {
            sum += arr[j];
            result = max(sum, result);
        }
    }
    return result;
}

int findMaxSubArray3(const std::vector<int>& arr)
{
    int result = INT_MIN;
    int sum  = 0;
    for (int i = 0; i < arr.size(); ++i) {
        sum = max(arr[i], sum + arr[i]);
        result = max(sum, result);
    }
    return result;
}

int main()
{
    cout << "Hello World!" << endl;
    std::vector<int> arr1 = {3, 1, -2, 5, -3};
    cout << findMaxSubArray3(arr1) << endl;
    return 0;
}
