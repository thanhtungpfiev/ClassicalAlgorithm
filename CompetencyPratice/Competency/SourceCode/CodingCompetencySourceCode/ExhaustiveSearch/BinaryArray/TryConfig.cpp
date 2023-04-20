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
#include "TryConfig.h"
#include <iostream>

TryConfig::TryConfig(int n)
{
    m_n = n;
    m_arr = std::vector<int>(n + 1);
}

void TryConfig::printConfig(const vector<int> &v)
{
    for (int i = 1; i <= m_n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void TryConfig::tryConfig(int i) {
    for (int v = 0; v <= 1; ++v) {
        m_arr[i] = v;
        if (i == m_n) {
            printConfig(m_arr);
        } else {
            tryConfig(i + 1);
        }
    }
}
