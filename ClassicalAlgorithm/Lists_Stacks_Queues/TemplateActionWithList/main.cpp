/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 23 - 5 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
using namespace std::chrono;

template <typename Container>
void removeEveryOtherItem(Container& lst)
{
    auto itr = lst.begin();
    while (itr != lst.end()) {
        itr = lst.erase(itr);
        if (itr != lst.end()) {
            itr++;
        }
    }
}

template <typename Container, typename Object>
void change(Container& c, const Object& newValue)
{
    typename Container::iterator itr = c.begin();
    while (itr != c.end()) {
        *itr++ = newValue;
    }
}

template <typename Container>
void print(const Container& c)
{
    typename Container::const_iterator itr = c.cbegin();
    while (itr != c.end()) {
        cout << *itr++ << endl;
    }
}

int main()
{
    list<int> values(800000);

    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };

    // Fill up the vector
    generate(values.begin(), values.end(), f);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    removeEveryOtherItem(values);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
             << duration.count() << " microseconds" << endl;

//    vector<int> values1(800000);

//    // Fill up the vector
//    generate(values1.begin(), values1.end(), f);

//    // Get starting timepoint
//    start = high_resolution_clock::now();

//    // Call the function, here sort()
//    removeEveryOtherItem(values1);

//    // Get ending timepoint
//    stop = high_resolution_clock::now();

//    // Get duration. Substart timepoints to
//    // get duration. To cast it to proper unit
//    // use duration cast method
//    duration = duration_cast<microseconds>(stop - start);

//    cout << "Time taken by function: "
//             << duration.count() << " microseconds" << endl;

    vector<int> v = {1, 2, 3, 4};
    print(v);
    change(v, 10);
    print(v);

    return 0;
}
