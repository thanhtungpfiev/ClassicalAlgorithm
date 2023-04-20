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
    m_mark = std::vector<bool>(n + 1, false);
}

void TryConfig::printConfig(const vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void TryConfig::tryConfig(int i) {
    for (int v = 1; v <= m_n; ++v) {
        if (!m_mark[v]) {
            m_arr[i] = v;
            if (i == m_n) {
                printConfig(m_arr);
            } else {
                m_mark[v] = true;
                tryConfig(i + 1);
                m_mark[v] = false;
            }
        }
    }
}
