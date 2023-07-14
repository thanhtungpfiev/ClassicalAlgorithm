#include <iostream>

using namespace std;

int getMedian(std::vector<int> &data)
{
    sort(data.begin(), data.end());
    return data[data.size() / 2];
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}