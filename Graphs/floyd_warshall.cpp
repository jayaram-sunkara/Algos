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

// Floyd Warshall's Algorithm is used for solving all pair shortest path problems.
    // Complexity of Floyd Warshall's Algorithm.
    // Time complexity - O(n^3)
    // Space complexity - O(n)

void fillDistMatrix(vector<vector<int>> &adjArray, int V, vector<vector<int>> &dist)
{
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (u == v)
                dist[u][u] = 0;
            else if (adjArray[u][v] != 0)
                dist[u][v] = adjArray[u][v];
        }
    }
    return;
}

// O(n^3)
vector<vector<int>> floydWarshall(vector<vector<int>> &adjArray)
{
    int V = adjArray.size();
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    fillDistMatrix(adjArray, V, dist);

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
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

    vector<vector<pii>> adjList(V);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        adjList[u].pb({v, wt});
        adjList[v].pb({u, wt});
    }

    vector<vector<int>> adjArray(V, vector<int>(V, 0));
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
        adjArray[u][v] = wt;
    }

    // for(int u=0; u<V; u++) {
    //     for(int v=0; v<adjList[u].size(); v++) {
    //         cout << adjList[u][v].fi << "-" << adjList[u][v].se << " ";
    //     }
    //     cout << nl;
    // }

    // for (int u = 0; u < V; u++) {
    //     for (int v = 0; v < V; v++) {
    //         cout << adjArray[u][v] << " ";
    //     }
    //     cout << nl;
    // }

    // Floyd warshall
    // Can be done using adjList too.
    vector<vector<int>> dist = floydWarshall(adjArray);
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            cout << dist[u][v] << " ";
        }
        cout << nl;
    }
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
