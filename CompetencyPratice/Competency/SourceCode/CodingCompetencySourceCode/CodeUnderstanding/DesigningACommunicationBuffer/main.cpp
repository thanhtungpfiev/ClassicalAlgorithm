/**********************************************************************
 *
 * \author  tung.dao@lge.com
 *
 * \date 9/4/2021
 *
 * \class %{Cpp:License:ClassName}
 *
 * \brief
 *
***********************************************************************/
#include <iostream>
#include <queue>

using namespace std;

typedef struct st
{
    int packet_no;
    int prior_level;
}PACKET;

struct ComparePriority
{
    bool operator()(const PACKET &a, const PACKET& b) {
        if (a.prior_level == b.prior_level) {
            return a.packet_no > b.packet_no;
        }
        return a.prior_level > b.prior_level;
    }
};

int main(void)
{
    int N;

    cin >> N;	// read number of packet

    priority_queue<PACKET, vector<PACKET>, ComparePriority> pq;

    for (int i = 0; i < N; ++i) {
        PACKET p;
        cin >> p.packet_no >> p.prior_level;
        pq.push(p);
    }

    while (!pq.empty()) {
        PACKET p = pq.top();
        pq.pop();
        cout << p.packet_no << " ";
    }
    cout << endl;

    return 0;
}
