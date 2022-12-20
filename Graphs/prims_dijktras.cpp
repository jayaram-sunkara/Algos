#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<ll, ll>
#define pr_que priority_queue<pii, vector<pii>, greater<pii>>
#define mod 1000000007
const long long N = 200001, INF = 1000000000000000000;
const char nl = '\n';

int prims(int V, int s, vector<vector<pii>> &adj)
{
    vector<bool> vis(V, 0);
    int cost = 0;
    pr_que pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        int wt = pq.top().fi, u = pq.top().se;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        cost += wt;
        for (int v = 0; v < adj[u].size(); v++)
        {
            if (!vis[adj[u][v].fi])
            {
                pq.push({adj[u][v].se, adj[u][v].fi});
            }
        }
    }
    return cost;
}

vector<int> dijkstra(int V, int s, vector<vector<pii>> &adj)
{
    vector<int> vis(V, 0);
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    pr_que pq;
    pq.push({dist[s], s});
    while (!pq.empty())
    {
        int wt = pq.top().fi, u = pq.top().se;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v = 0; v < adj[u].size(); v++)
        {
            int child = adj[u][v].fi, wt = adj[u][v].se;
            int parent = u;
            if (!vis[child] && dist[parent] + wt < dist[child])
            {
                dist[child] = wt + dist[parent];
                pq.push({dist[child], adj[u][v].fi});
            }
        }
    }
    return dist;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].pb({edges[i][1], edges[i][2]});
        adj[edges[i][1]].pb({edges[i][0], edges[i][2]});
    }

    // for(int u=0; u<n; u++) {
    //     for(int v=0; v<adj[u].size(); v++) {
    //         cout << adj[u][v].fi << "-" << adj[u][v].se << " ";
    //     }
    //     cout << nl;
    // }

    // To find min cost spanning tree
    //  cout << prims(n, 0, adj) << nl;

    // Dijkstra's algorithm
    vector<int> dist = dijkstra(n, 0, adj);

    for (auto &it : dist)
        cout << it << nl;
}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
