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
#ifndef GENERATECONFIG_H
#define GENERATECONFIG_H

#include <vector>

using namespace std;

class GenerateConfig
{
public:
    GenerateConfig(int n);

    void initFirstConfig();
    void printConfig(const vector<int>& v);
    void generateConfig(vector<int>& v);
    vector<int> arr() const;

private:
    int m_n;
    vector<int> m_arr;
};

#endif // GENERATECONFIG_H
