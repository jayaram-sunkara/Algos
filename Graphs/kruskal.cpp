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

// DSU data structure
// path compression + rank by union

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

int kruskals_mst(int V, vector<vector<int>> &edgeList)
{
    // 1. Sort all edges
    sort(edgeList.begin(), edgeList.end());

    // Initialize the DSU
    DSU s(V);
    int ans = 0;
    cout << "Following are the edges in the constructed MST" << endl;
    for (auto edge : edgeList)
    {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        // Take this edge in MST if it does
        // not forms a cycle
        if (s.find(x) != s.find(y))
        {
            s.unite(x, y);
            ans += w;
            cout << x << " -- " << y << " == " << w << endl;
        }
    }

    cout << "Minimum Cost Spanning Tree: ";
    return ans;
}

void solve()
{
    int V, m;
    cin >> V >> m;

    vector<vector<int>> edgeList(m); // edge list with weights as 1st number
    vector<vector<int>> edges(m);   //  edges with order as {u, v, wt}
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
        edgeList[i] = {wt, u, v};
    }

    vector<vector<pii>> adjList(V);
    for (int i = 0; i < m; i++)
    {
        adjList[edges[i][0]].pb({edges[i][1], edges[i][2]});
        adjList[edges[i][1]].pb({edges[i][0], edges[i][2]});
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

    // Krushkal
    cout << kruskals_mst(V, edgeList) << nl;

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
