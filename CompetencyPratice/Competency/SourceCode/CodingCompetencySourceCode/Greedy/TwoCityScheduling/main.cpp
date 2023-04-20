/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/4/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element
{
    int position;
    int cost;
    Element(int position1, int cost1) {
        position = position1;
        cost = cost1;
    }
};

struct CompareElement
{
    bool operator()(const Element& e1, const Element& e2) {
        if (e1.cost == e2.cost) {
            return e1.position > e2.position;
        }
        return e1.cost > e2.cost;
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int result = 0;
        priority_queue<Element, vector<Element>, CompareElement> pq;
        for (int i = 0; i < costs.size(); ++i) {
            vector<int> cost = costs[i];
            pq.push(Element(i, cost[0] - cost[1]));
        }

        int cnt = 0;
        while (!pq.empty()) {
            Element e = pq.top();
            pq.pop();
            int i = e.position;
            vector<int> cost = costs[i];
            if (cnt < costs.size() / 2) {
                result += cost[0];
            } else {
                result += cost[1];
            }
            cnt++;
        }
        return result;
    }
};

int main()
{
    Solution s;
//    vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
    vector<vector<int>> costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    int result = s.twoCitySchedCost(costs);
    cout << result << endl;
    return 0;
}
