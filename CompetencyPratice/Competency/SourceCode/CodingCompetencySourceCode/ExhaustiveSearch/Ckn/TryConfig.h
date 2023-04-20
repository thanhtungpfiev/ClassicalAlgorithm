/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/14/2021
 *
 * \class TryConfig
 *
 * \brief
 *
***********************************************************************/
#ifndef TRYCONFIG_H
#define TRYCONFIG_H

#include <vector>

using namespace std;

class TryConfig
{
public:
    TryConfig(int n, int k);

    void tryConfig(int i);
    void printConfig(const vector<int>& v);
private:
    int m_n;
    int m_k;
    vector<int> m_arr;
};

#endif // TRYCONFIG_H
