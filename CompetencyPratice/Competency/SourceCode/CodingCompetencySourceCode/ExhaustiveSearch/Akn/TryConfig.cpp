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
    m_count = 0;
    m_arr = std::vector<int>(k + 1);
    m_mark = std::vector<bool>(k + 1, false);
}

void TryConfig::printConfig(const vector<int> &v)
{
    int n = v.size();
    cout << "Chinh hop thu " << m_count << ": ";
    for (int i = 1; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void TryConfig::tryConfig(int i) {
    for (int v = 1; v <= m_n; ++v) {
        if (!m_mark[v]) {
            m_arr[i] = v;
            if (i == m_k) {
                m_count++;
                printConfig(m_arr);
            } else {
                m_mark[v] = true;
                tryConfig(i + 1);
                m_mark[v] = false;
            }
        }
    }
}
