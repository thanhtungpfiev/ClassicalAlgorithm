/*
 * File: main.cpp
 * Project: CountMap
 * File Created: Friday, 22nd July 2022 4:52:29 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
class CountMap
{
public:
    std::unordered_map<T, int> hm;
    virtual void add(T key)
    {
        if (hm.find(key) != hm.end())
        {
            hm[key] = hm[key] + 1;
        }
        else
        {
            hm[key] = 1;
        }
    }
    virtual void remove(T key)
    {
        if (hm.find(key) != hm.end())
        {
            if (hm[key] == 1)
            {
                hm.erase(key);
            }
            else
            {
                hm[key] = hm[key] - 1;
            }
        }
    }
    virtual int get(T key)
    {
        if (hm.find(key) != hm.end())
        {
            return hm[key];
        }
        return 0;
    }
    virtual bool containsKey(T key)
    {
        return hm.find(key) != hm.end();
    }
    virtual int size()
    {
        return hm.size();
    }
};

int main(int argc, char **argv)
{
    CountMap<int> *cm = new CountMap<int>();
    cm->add(2);
    cm->add(2);
    cm->remove(2);
    std::cout << "count is : " << cm->get(2) << std::endl;
    std::cout << "count is : " << cm->get(3) << std::endl;
    return 0;
    return 0;
}