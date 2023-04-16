#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[100001];
bool visited[100001];
int dist[100001];
int parent[100001];

void prim(int start) {
    for (int i = 1; i <= 100000; i++) {
        visited[i] = false;
        dist[i] = INF;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        
        for (auto v : adj[u]) {
            if (!visited[v.first] && v.second < dist[v.first]) {
                dist[v.first] = v.second;
                parent[v.first] = u;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    prim(1);
    
    int total_weight = 0;
    for (int i = 1; i <= n; i++) {
        total_weight += dist[i];
    }
    
    cout << total_weight << endl;
    
    return 0;
}
