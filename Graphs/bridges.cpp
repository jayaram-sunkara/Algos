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

void dfs_for_bridges(int u, int &time, vector<vector<pii>> &adjList, vector<int> &parent, vector<int> &disc_time, vector<int> &low, vector<pii> &bridges)
{
    disc_time[u] = time;
    low[u] = time;

    time++;
    int child_count = 0;

    for (int v = 0; v < adjList[u].size(); v++)
    {
        int child = adjList[u][v].fi;
        if (disc_time[child] == -1)
        {

            // if child node has not been visited before
            // set parent of child node and increment the children count
            parent[child] = u;
            child_count++;

            dfs_for_bridges(child, time, adjList, parent, disc_time, low, bridges);

            // set the low for current node
            low[u] = min(low[u], low[child]);

            if (parent[child] == -1 && child_count > 1)
            {
                // case 1:
                bridges.pb({u, child});
            }

            else if (parent[child] != -1 && low[child] > disc_time[u])
            {
                // case 2:
                bridges.pb({u, child});
            }
        }
        else if (parent[u] != child)
        {
            // if child node has been visited before it is a back-edge
            // set low for current node.
            low[u] = min(low[u], disc_time[child]);
        }
    }
}

void findBridges(int V, vector<vector<pii>> &adjList)
{
    vector<int> parent(V, -1), disc_time(V, -1), low(V, -1);
    vector<pii> bridges;

    int time = 1;

    for (int i = 0; i < V; i++)
    {
        if (disc_time[i] == -1)
        {
            dfs_for_bridges(i, time, adjList, parent, disc_time, low, bridges);

            time = 1;
        }
    }

    cout << "Bridges are: " << nl;
    for (auto &it : bridges)
        cout << it.fi << " " << it.se << nl;

}

void solve()
{
    int V, m;
    cin >> V >> m;

    vector<vector<int>> edgeList(m); // edge list with weights as 1st number
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        edgeList[i] = {w, u, v};
    }

    vector<vector<pii>> adjList(V);
    for (int i = 0; i < m; i++)
    {
        adjList[edges[i][0]].pb({edges[i][1], edges[i][2]});
        // adjList[edges[i][1]].pb({edges[i][0], edges[i][2]});
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

    // Bridges in a graph
    findBridges(V, adjList);
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
