/*
 * File: main1.cpp
 * Project: AdjacencyList
 * File Created: Friday, 29th July 2022 3:10:47 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
private:
    struct Edge
    {
        int source;
        int destination;
        int cost;
        Edge *next;
        Edge(int src, int dst, int cst);
    };
    struct AdjList
    {
        Edge *head;
    };
    int count;
    std::vector<AdjList *> ListVector;
    class EdgeComparator
    {
    public:
        bool operator()(Edge *x, Edge *y);
    };

public:
    Graph(int cnt);
    virtual void AddEdge(int source, int destination, int cost);
    virtual void AddEdge(int source, int destination);
    virtual void AddBiEdge(int source, int destination, int cost); // bi
    virtual void AddBiEdge(int source, int destination);           // bi directional edge
    virtual void Print();
    // Other Methods of graph.
    void DFSStack();
    void DFS();
    void DFSRec(int index, std::vector<int> &visited);
    void BFS();
    void BFSQueue(int index, std::vector<int> &visited);
    int PathExist(int source, int destination);
    bool isConnected();
};
Graph::Edge::Edge(int src, int dst, int cst = 1)
{
    source = src;
    destination = dst;
    cost = cst;
    next = nullptr;
}
Graph::Graph(int cnt)
{
    count = cnt;
    ListVector = std::vector<AdjList *>(cnt);
    for (int i = 0; i < cnt; i++)
    {
        ListVector[i] = new AdjList();
        ListVector[i]->head = nullptr;
    }
}
void Graph::AddEdge(int source, int destination, int cost)
{
    Edge *edge = new Edge(source, destination, cost);
    edge->next = ListVector[source]->head;
    ListVector[source]->head = edge;
}
void Graph::AddEdge(int source, int destination)
{
    AddEdge(source, destination, 1);
}
void Graph::AddBiEdge(int source, int destination, int cost)
{
    AddEdge(source, destination, cost);
    AddEdge(destination, source, cost);
}
void Graph::AddBiEdge(int source, int destination)
{
    AddBiEdge(source, destination, 1);
}
void Graph::Print()
{
    Edge *ad;
    for (int i = 0; i < count; i++)
    {
        ad = ListVector[i]->head;
        if (ad != nullptr)
        {
            std::cout << "Vertex " << i << " is connected to : ";
            while (ad != nullptr)
            {
                std::cout << ad->destination << " ";
                ad = ad->next;
            }
            std::cout << std::endl;
        }
    }
}
bool Graph::EdgeComparator::operator()(Edge *x, Edge *y)
{
    if (x->cost <= y->cost)
    {
        return false;
    }
    return true;
}

void Graph::DFSStack()
{
    std::vector<int> visited(count);
    int curr;
    std::stack<int> stk;
    for (int i = 0; i < count; i++)
        visited[i] = 0;
    visited[0] = 1;
    stk.push(0);
    while (stk.empty() == false)
    {
        curr = stk.top();
        stk.pop();
        Edge *head = ListVector[curr]->head;
        while (head != nullptr)
        {
            if (visited[head->destination] == 0)
            {
                visited[head->destination] = 1;
                stk.push(head->destination);
            }
            head = head->next;
        }
    }
}

void Graph::DFS()
{
    std::vector<int> visited(count);
    for (int i = 0; i < count; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            DFSRec(i, visited);
        }
    }
}
void Graph::DFSRec(int index, std::vector<int> &visited)
{
    Edge *head = ListVector[index]->head;
    while (head != nullptr)
    {
        if (visited[head->destination] == 0)
        {
            visited[head->destination] = 1;
            DFSRec(head->destination, visited);
        }
        head = head->next;
    }
}

void Graph::BFS()
{
    std::vector<int> visited(count);
    for (int i = 0; i < count; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == 0)
        {
            BFSQueue(i, visited);
        }
    }
}
void Graph::BFSQueue(int index, std::vector<int> &visited)
{
    int curr;
    std::queue<int> que;
    visited[index] = 1;
    que.push(index);
    while (que.empty() == false)
    {
        curr = que.front();
        que.pop();
        Edge *head = ListVector[curr]->head;
        while (head != nullptr)
        {
            if (visited[head->destination] == 0)
            {
                visited[head->destination] = 1;
                que.push(head->destination);
            }
            head = head->next;
        }
    }
}

int Graph::PathExist(int source, int destination)
{
    std::vector<int> visited(count);
    for (int i = 0; i < count; i++)
        visited[i] = 0;
    visited[source] = 1;
    DFSRec(source, visited);
    return visited[destination];
}

bool Graph::isConnected()
{
    std::vector<int> visited(count);
    for (int i = 0; i < count; i++)
    {
        visited[i] = 0;
    }
    visited[0] = 1;
    DFSRec(0, visited);
    for (int i = 0; i < count; i++)
    {
        if (visited[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    Graph *graph = new Graph(5);
    graph->AddBiEdge(0, 1);
    graph->AddBiEdge(1, 2);
    graph->AddBiEdge(1, 3);
    graph->AddBiEdge(2, 3);
    graph->AddBiEdge(3, 4);
    graph->Print();
    return 0;
}