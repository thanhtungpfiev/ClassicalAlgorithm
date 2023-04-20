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
#include "GenerateConfig.h"
#include "TryConfig.h"

using namespace std;


int main()
{
    int n = 5;
    int k = 3;

//    cout << "Thuat toan sinh" << endl;
//    GenerateConfig g(5, 3);
//    g.initFirstConfig();
//    vector<int> v = g.arr();
//    g.printConfig(v);
//    g.generateConfig(v);

    cout << "Thuat toan quay lui" << endl;
    TryConfig t(5, 3);
    t.tryConfig(1);

    return 0;
}
