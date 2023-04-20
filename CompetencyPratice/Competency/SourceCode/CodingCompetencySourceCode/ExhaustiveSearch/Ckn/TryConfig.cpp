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

TryConfig::TryConfig(int n, int k)
{
    m_n = n;
    m_k = k;
    m_arr = std::vector<int>(k + 1);
}

void TryConfig::printConfig(const vector<int> &v)
{
    for (int i = 1; i <= m_k; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void TryConfig::tryConfig(int i) {
    for (int v = m_arr[i - 1] + 1; v <= m_n - m_k + i; ++v) {
        m_arr[i] = v;
        if (i == m_k) {
            printConfig(m_arr);
        } else {
            tryConfig(i + 1);
        }
    }
}
