/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/14/2021
 *
 * \class GenerateConfig
 *
 * \brief
 *
***********************************************************************/
#include "GenerateConfig.h"
#include <iostream>


GenerateConfig::GenerateConfig(int n, int k)
{
    m_n = n;
    m_k = k;
}

void GenerateConfig::initFirstConfig()
{
    for (int i = 0; i <= m_k; ++i) {
        m_arr.push_back(i);
    }
}

void GenerateConfig::printConfig(const vector<int>& v) {
    for (int i = 1; i <= m_k; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> GenerateConfig::arr() const
{
    return m_arr;
}

void GenerateConfig::generateConfig(vector<int>& v) {
    // Tim tu cuoi len dau day cho den khi gap phan tu x(i) chua dat gioi han tren n - k + i
    int i = m_k;
    while ((i > 0) && v[i] == m_n - m_k + i) --i;
    if (i == 0) return; // cau hinh ket thuc, tat ca cac phan tu dat gioi han
    // Tang x[i] len 1 don vi
    ++v[i];

    // Dat cac phan tu phia sau bang gioi han duoi
    for (int j = i + 1; j <= m_k; ++j) {
        v[j] = v[j - 1] + 1;
    }
    printConfig(v);
    generateConfig(v);
}
