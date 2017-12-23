#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 99999999;
const int MAX = 505;

typedef struct Graph
{
    int Nv;
    int Ne;
    int G[MAX][MAX];
}*PGraph, MGraph;

// 初始化定义
vector<bool> Collected(MAX, false);
int dist[MAX], weight_sum[MAX];
vector<int> WeightVertex(MAX, 0);
vector<int> path_num(MAX, 0);

// 函数原型
MGraph CreateGraph(int Nv, int Ne);
void Dijkstra(MGraph graph, int source);

int main()
{
    int Nv, Ne, start_v, end_v;
    scanf("%d %d %d %d", &Nv, &Ne, &start_v, &end_v);
    for(int i = 0; i < Nv; i++)
    {
        scanf("%d", &WeightVertex[i]);
    }
    MGraph graph = CreateGraph(Nv, Ne);  // 创建图
    Dijkstra(graph, start_v);
    if(start_v == end_v)
        cout << "1 " << WeightVertex[start_v];
    else
        printf("%d %d", path_num[end_v], weight_sum[end_v]);
    return 0;
}

MGraph CreateGraph(int Nv, int Ne)
{
    PGraph graph = new MGraph;
    graph->Nv = Nv;
    graph->Ne = Ne;
    int v, w, data;
    fill(graph->G[0], graph->G[0] + MAX * MAX, LIMIT);
    fill(dist, dist + MAX, LIMIT);
    for(int i = 0; i < graph->Ne; i++)
    {
        scanf("%d %d %d", &v, &w, &data);
        graph->G[v][w] = data;
        graph->G[w][v] = data;                    // 为毛我没看到题目里面说的是无权图，浪费好几个小时
    }
    return *graph;
}


void Dijkstra(MGraph graph, int source)
{
    dist[source] = 0;
    weight_sum[source] = WeightVertex[source];
    path_num[source] = 1;
    int min_v, min_road;
    for(int step = 0; step < graph.Nv; step++)
    {
        min_road = LIMIT;
        min_v = -1;
        for(int i = 0; i < graph.Nv; i++)
        {
            if(!Collected[i] && dist[i] < min_road)
            {
                min_v = i;
                min_road = dist[i];
            }
        }
        if(min_v == -1)
            break;
        Collected[min_v] = true;
        for(int w = 0; w < graph.Nv; w++)
        {
            if(!Collected[w] && graph.G[min_v][w] != LIMIT)
            {
                if(dist[w] > dist[min_v] + graph.G[min_v][w])
                {
                    dist[w] = dist[min_v] + graph.G[min_v][w];
                    path_num[w] = path_num[min_v];
                    weight_sum[w] = WeightVertex[w] + weight_sum[min_v];
                }
                else if(dist[w] == dist[min_v] + graph.G[min_v][w])
                {
                    path_num[w] += path_num[min_v];
                    if(weight_sum[w] < WeightVertex[w] + weight_sum[min_v])
                        weight_sum[w] = WeightVertex[w] + weight_sum[min_v];
                }
            }
        }
    }
}
