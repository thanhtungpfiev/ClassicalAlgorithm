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
        m_arr.push_back(i);
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
    // Xac dinh doan cuoi giam dan dai nhat
    int i = m_n; // i la vi tri cua phan tu dung ngay truoc phan tu dau tien trong day con giam dan dai nhat
    while ((i > 0) && v[i] > v[i + 1]) --i;
    if (i == 0) return; // cau hinh ket thuc, day toan so giam dan

    // Trong doan cuoi giam dan tim phan tu x(k) sao cho thoa man dieu kien x(k) > x(i)
    int k = m_n;
    while (v[k] < v[i]) --k;

    // Doi cho x(k) va x(i), lat nguoc thu tu doan cuoi giam dan thanh tang dan
    std::swap(v[k], v[i]);
    int a = i + 1;
    int b = m_n;
    while (a < b) {
        std::swap(v[a], v[b]);
        ++a;
        --b;
    }
    printConfig(v);
    generateConfig(v);
}
