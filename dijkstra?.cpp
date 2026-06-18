#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<pair<int,int>>> adj(n + 1); // {to, weight}
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    const long long INF = LLONG_MAX;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    
    dist[1] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (u == n) break; // shortest distance to n is finalized
        
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[n] == INF) {
        printf("-1\n");
        return 0;
    }
    
    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    
    for (int v : path) printf("%d ", v);
    printf("\n");
    
    return 0;
}