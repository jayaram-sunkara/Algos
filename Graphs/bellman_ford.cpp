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

vector<int> bellmann(int V, int src, vector<vector<int>> &edges)
{
    // Step 1 - Creating a V sized array/vector,
    // and initializing it with a very big value.
    vector<int> dist(V, INT_MAX); // Creating a vector dist of size V with values as INT_MAX.
    dist[src] = 0;                // Since we are already on source vertex, we can reach it within no time.

    // Step 2 - For V-1 times, traversing over,
    // all the edges and checking if a shorter
    // path between any edge u to v is possible.
    for (int i = 0; i < V - 1; i++)
    { // Iterating V-1 times
        for (int j = 0; j < edges.size(); j++)
        { // Iterating over all the edges.
            int parent = edges[j][0], child = edges[j][1], wt = edges[j][2];
            // If we can reach child from parent in less time it
            // is currently required to reach child then update
            // the value.
            if (dist[parent] != INT_MAX && dist[parent] + wt < dist[child])
            {
                dist[child] = dist[parent] + wt;
            }
        }
    }

    // Step 3 - Checking for negative edge weight cycle,
    // by checking if the underliying condition satifies.
    // No more changes should happen to dist vector after V-1 iterations.
    // If happens then there is a Negitive cycle.
    for (int j = 0; j < edges.size(); j++)
    {
        int parent = edges[j][0], child = edges[j][1], wt = edges[j][2];
        if (dist[parent] != INT_MAX && dist[parent] + wt < dist[child])
        {
            cout << "Negitive cycle is found" << nl;
            return {};
        }
    }
    return dist; // returning our answer vector/array.
}

void solve()
{
    int V, m;
    cin >> V >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    vector<vector<pii>> adj(V);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].pb({edges[i][1], edges[i][2]});

        //This line is required only if we want to create a 
        // undirected graph from directed edges.
        adj[edges[i][1]].pb({edges[i][0], edges[i][2]});
    }

    // for(int u=0; u<V; u++) {
    //     for(int v=0; v<adj[u].size(); v++) {
    //         cout << adj[u][v].fi << "-" << adj[u][v].se << " ";
    //     }
    //     cout << nl;
    // }

    // Bellmann Ford
    vector<int> dist = bellmann(V, 5, edges);
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
