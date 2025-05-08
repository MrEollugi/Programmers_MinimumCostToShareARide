#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int curCost = top.first;
        int cur = top.second;
        pq.pop();

        if (curCost > dist[cur]) continue;

        for (int i = 0; i < graph[cur].size(); ++i) {
            int next = graph[cur][i].first;
            int cost = graph[cur][i].second;

            int nextCost = curCost + cost;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    return dist;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<pair<int, int>>> graph(n + 1);

    for (auto& f : fares) {
        int u = f[0], v = f[1], c = f[2];
        graph[u].emplace_back(v, c);
        graph[v].emplace_back(u, c);
    }

    auto distFromS = dijkstra(s, n, graph);
    auto distFromA = dijkstra(a, n, graph);
    auto distFromB = dijkstra(b, n, graph);

    int minFare = INF;
    for (int x = 1; x <= n; ++x) {
        if (distFromS[x] == INF || distFromA[x] == INF || distFromB[x] == INF) continue;
        minFare = min(minFare, distFromS[x] + distFromA[x] + distFromB[x]);
    }

    return minFare;
}
