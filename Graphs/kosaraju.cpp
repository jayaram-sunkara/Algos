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

// Kosaraju's Algorithm is used for finding strongly connected components in a graph
// In an undirected graph all components are strongly connected.
// This concept arises in a directed graph.

// Kosaraju's algorithm for Strongly Connected Components
/*Kosaraju's algorithm for Finding the number of Strongly Connected Components of a graph works on the fact
that on transposing a graph, i.e reversing all it's edges, the strongly connected components are unaffected.
This works in three steps:
1)Build a stack for the nodes using dfs. The node to finish the dfs latest shall be on top.
2)Transpose the graph
3)Perform dfs on the elements of the stack starting from top if it is unvisited and keep popping.
4)The number of SCC is merely the number of times DFS was called.
*/

void dfs(int V, int src, vector<vector<pii>> &adjList, stack<int> &stk, vector<bool> &vis)
{
    vis[src] = 1;
    for (int v = 0; v < adjList[src].size(); v++)
    {
        if (!vis[adjList[src][v].fi])
        {
            dfs(V, adjList[src][v].fi, adjList, stk, vis);
        }
    }
    stk.push(src);
}

void dfs_for_rev(vector<vector<int>> &reversed, vector<bool> &vis, int src)
{
    vis[src] = 1;
    cout << src << " ";
    for (int v = 0; v < reversed[src].size(); v++)
    {
        if (!vis[reversed[src][v]])
        {
            dfs_for_rev(reversed, vis, reversed[src][v]);
        }
    }
}

void kosaraju(int V, vector<vector<pii>> adjList)
{
    vector<bool> vis(V, 0);
    stack<int> stk;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(V, i, adjList, stk, vis); // call dfs for the initial graph
        }
    }

    // make another adjacency list to store the transpose of the graph.
    vector<vector<int>> reversed(V);
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < adjList[u].size(); v++)
        {
            reversed[adjList[u][v].fi].pb(u);
        }
    }

    // mark all the nodes as unvisited.
    for (int i = 0; i < V; i++)
        vis[i] = 0;

    // starting from the top of the stack go visit every node and perform dfs on it, if it is not visited
    // The total number of strongly connected components will be the number of times dfs is called.
    int count = 1;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if (!vis[u])
        {
            cout << "component " << count++ << ": ";
            dfs_for_rev(reversed, vis, u);
            cout << endl;
        }
    }
    cout << nl;
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

    // Kosaraju
    kosaraju(V, adjList);
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

