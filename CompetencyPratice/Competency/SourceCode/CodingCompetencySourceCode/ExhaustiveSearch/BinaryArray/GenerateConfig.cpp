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


GenerateConfig::GenerateConfig(int n)
{
    m_n = n;
}

void GenerateConfig::initFirstConfig()
{
    for (int i = 0; i <= m_n; ++i) {
        m_arr.push_back(0);
    }
}

void GenerateConfig::printConfig(const vector<int>& v) {
    for (int i = 1; i <= m_n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> GenerateConfig::arr() const
{
    return m_arr;
}

void GenerateConfig::generateConfig(vector<int>& v) {
    // Tim tu cuoi len dau day cho den khi gap phan tu 0 dau tien
    int i = m_n;
    while ((i > 0) && v[i] == 1) --i;
    if (i == 0) return; // cau hinh ket thuc, tat ca cac phan tu deu la 1
    // Doi 0 thanh 1
    v[i] = 1;

    // Dat cac phan tu phia sau thanh 0
    for (int j = i + 1; j <= m_n; ++j) {
        v[j] = 0;
    }
    printConfig(v);
    generateConfig(v);
}
