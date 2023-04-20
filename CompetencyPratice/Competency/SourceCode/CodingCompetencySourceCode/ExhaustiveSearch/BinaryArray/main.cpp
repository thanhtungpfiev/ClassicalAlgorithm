/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 8/15/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include "TryConfig.h"
#include "GenerateConfig.h"

using namespace std;

int main()
{
    int n = 3;

    cout << "Thuat toan sinh" << endl;
    GenerateConfig g(3);
    g.initFirstConfig();
    vector<int> v = g.arr();
    g.printConfig(v);
    g.generateConfig(v);

    cout << "Thuat toan quay lui" << endl;
    TryConfig t(n);
    t.tryConfig(1);

    return 0;
}
