//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

class dfs
{
public:
    vector<int> reverse(vector<int> v)
    {
        int i = 0, n = v.size() - 1;
        while (i < n)
        {
            swap(v[i], v[n]);
            i++;
            n--;
        }
        return v;
    }

    void topoSortdfs(vector<vector<pii>> &adj, int src, vector<bool> &visited, vector<int> &res)
    {
        visited[src] = 1;
        for (int v = 0; v < adj[src].size(); v++)
        {
            if (!visited[adj[src][v].fi])
            {
                topoSortdfs(adj, adj[src][v].fi, visited, res);
            }
        }
        res.pb(src);
    }

    vector<int> topodfs(int n, int m, vector<vector<int>> &edges)
    {
        vector<bool> visited(n, 0);
        vector<vector<pii>> adj(n);
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].pb({edges[i][1], edges[i][2]});
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topoSortdfs(adj, i, visited, res);
            }
        }
        return reverse(res);
    }
};

class bfs
{
public:
    vector<int> topoSortbfs(vector<vector<pii>> &adj, int n, vector<int> indegree)
    {
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                res.pb(i);
            }
        }
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < adj[temp].size(); i++)
            {
                indegree[adj[temp][i].fi]--;
                if (indegree[adj[temp][i].fi] == 0)
                {
                    q.push(adj[temp][i].fi);
                    res.pb(adj[temp][i].fi);
                }
            }
        }
        return res;
    }

    vector<int> topobfs(int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<pii>> adj(n);
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].pb(make_pair(edges[i][1], edges[i][2]));
        }
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j].fi]++;
            }
        }
        vector<int> topo = topoSortbfs(adj, n, indegree);
        return topo;
    }
};

//{ Driver Code Starts.
int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        
        bfs obj1;
        vector<int> res1 = obj1.topobfs(n, m, edges);
        for (auto x : res1)
        {
            cout << x << " ";
        }
        cout << "\n";

        dfs obj2;
        vector<int> res2 = obj2.topodfs(n, m, edges);
        for (auto x : res2)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends