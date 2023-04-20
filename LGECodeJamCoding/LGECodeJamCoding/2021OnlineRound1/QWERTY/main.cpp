/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 3/21/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <climits>

using namespace std;


map<char, int> initKeyboardMap()
{
    map<char, int> keyboardMap;
    keyboardMap.insert({'Q', 0});
    keyboardMap.insert({'W', 1});
    keyboardMap.insert({'E', 2});
    keyboardMap.insert({'R', 3});
    keyboardMap.insert({'T', 4});
    keyboardMap.insert({'Y', 5});
    keyboardMap.insert({'U', 6});
    keyboardMap.insert({'I', 7});
    keyboardMap.insert({'O', 8});
    keyboardMap.insert({'P', 9});
    keyboardMap.insert({'A', 10});
    keyboardMap.insert({'S', 11});
    keyboardMap.insert({'D', 12});
    keyboardMap.insert({'F', 13});
    keyboardMap.insert({'G', 14});
    keyboardMap.insert({'H', 15});
    keyboardMap.insert({'J', 16});
    keyboardMap.insert({'K', 17});
    keyboardMap.insert({'L', 18});
    keyboardMap.insert({'Z', 19});
    keyboardMap.insert({'X', 20});
    keyboardMap.insert({'C', 21});
    keyboardMap.insert({'V', 22});
    keyboardMap.insert({'B', 23});
    keyboardMap.insert({'N', 24});
    keyboardMap.insert({'M', 25});
    return keyboardMap;
}

void addEdge(vector<vector<int>>& adj, int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int BFS(const vector<vector<int>>& adj, int src, int dest)
{
    int v = adj.size();
    vector<bool> visited (v, false);
    vector<int> dist(v, INT_MAX);

    list<int> queue;
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int  i = 0; i < adj[u].size(); ++i) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest) {
                    return dist[dest];
                }
            }
        }
    }
    return 0;
}

vector<vector<int>> initGraph(map<char, int>& keyboardMap)
{
    vector<vector<int>> adj(keyboardMap.size());

    addEdge(adj, keyboardMap['Q'], keyboardMap['W']);
    addEdge(adj, keyboardMap['Q'], keyboardMap['A']);

    addEdge(adj, keyboardMap['W'], keyboardMap['E']);
    addEdge(adj, keyboardMap['W'], keyboardMap['S']);
    addEdge(adj, keyboardMap['W'], keyboardMap['A']);

    addEdge(adj, keyboardMap['E'], keyboardMap['R']);
    addEdge(adj, keyboardMap['E'], keyboardMap['D']);
    addEdge(adj, keyboardMap['E'], keyboardMap['S']);

    addEdge(adj, keyboardMap['R'], keyboardMap['T']);
    addEdge(adj, keyboardMap['R'], keyboardMap['F']);
    addEdge(adj, keyboardMap['R'], keyboardMap['D']);

    addEdge(adj, keyboardMap['T'], keyboardMap['Y']);
    addEdge(adj, keyboardMap['T'], keyboardMap['G']);
    addEdge(adj, keyboardMap['T'], keyboardMap['F']);

    addEdge(adj, keyboardMap['Y'], keyboardMap['U']);
    addEdge(adj, keyboardMap['Y'], keyboardMap['H']);
    addEdge(adj, keyboardMap['Y'], keyboardMap['G']);

    addEdge(adj, keyboardMap['U'], keyboardMap['I']);
    addEdge(adj, keyboardMap['U'], keyboardMap['J']);
    addEdge(adj, keyboardMap['U'], keyboardMap['H']);

    addEdge(adj, keyboardMap['I'], keyboardMap['O']);
    addEdge(adj, keyboardMap['I'], keyboardMap['K']);
    addEdge(adj, keyboardMap['I'], keyboardMap['J']);

    addEdge(adj, keyboardMap['O'], keyboardMap['P']);
    addEdge(adj, keyboardMap['O'], keyboardMap['L']);
    addEdge(adj, keyboardMap['O'], keyboardMap['K']);

    addEdge(adj, keyboardMap['P'], keyboardMap['L']);

    addEdge(adj, keyboardMap['A'], keyboardMap['S']);
    addEdge(adj, keyboardMap['A'], keyboardMap['Z']);

    addEdge(adj, keyboardMap['S'], keyboardMap['D']);
    addEdge(adj, keyboardMap['S'], keyboardMap['X']);
    addEdge(adj, keyboardMap['S'], keyboardMap['Z']);

    addEdge(adj, keyboardMap['D'], keyboardMap['F']);
    addEdge(adj, keyboardMap['D'], keyboardMap['C']);
    addEdge(adj, keyboardMap['D'], keyboardMap['X']);

    addEdge(adj, keyboardMap['F'], keyboardMap['G']);
    addEdge(adj, keyboardMap['F'], keyboardMap['V']);
    addEdge(adj, keyboardMap['F'], keyboardMap['C']);

    addEdge(adj, keyboardMap['G'], keyboardMap['H']);
    addEdge(adj, keyboardMap['G'], keyboardMap['B']);
    addEdge(adj, keyboardMap['G'], keyboardMap['V']);

    addEdge(adj, keyboardMap['H'], keyboardMap['J']);
    addEdge(adj, keyboardMap['H'], keyboardMap['N']);
    addEdge(adj, keyboardMap['H'], keyboardMap['B']);

    addEdge(adj, keyboardMap['J'], keyboardMap['K']);
    addEdge(adj, keyboardMap['J'], keyboardMap['M']);
    addEdge(adj, keyboardMap['J'], keyboardMap['N']);

    addEdge(adj, keyboardMap['K'], keyboardMap['L']);
    addEdge(adj, keyboardMap['K'], keyboardMap['M']);

    addEdge(adj, keyboardMap['Z'], keyboardMap['X']);

    addEdge(adj, keyboardMap['X'], keyboardMap['C']);

    addEdge(adj, keyboardMap['C'], keyboardMap['V']);

    addEdge(adj, keyboardMap['V'], keyboardMap['B']);

    addEdge(adj, keyboardMap['B'], keyboardMap['N']);

    addEdge(adj, keyboardMap['N'], keyboardMap['M']);

//    cout << BFS(adj, keyboardMap['F'], keyboardMap['F']) << endl;

    return adj;

}

void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    string s = "";
    map<char, int> keyboardMap = initKeyboardMap();
    vector<vector<int>> adj = initGraph(keyboardMap);
    while (T --> 0) {
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            int d = BFS(adj, keyboardMap[s[i]], keyboardMap[s[i + 1]]);
            sum += 2 * d;
        }
        sum += s.size();
        cout << sum << endl;
    }
}

void inputByReadFile()
{
    ifstream fileInput("/media/sf_D_DRIVE/CodingPractices/LGECodeJamCoding/LGECodeJamCoding/2021OnlineRound1/QWERTY/input.txt");
    int T = 0;
    fileInput >> T;
    string s = "";
    map<char, int> keyboardMap = initKeyboardMap();
    vector<vector<int>> adj = initGraph(keyboardMap);
    while (T --> 0) {
        fileInput >> s;
        int sum = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            int d = BFS(adj, keyboardMap[s[i]], keyboardMap[s[i + 1]]);
            sum += 2 * d;
        }
        sum += s.size();
        cout << sum << endl;
    }
}

int main()
{
    inputByReadConsole();
    return 0;
}
