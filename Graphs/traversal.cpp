#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(vector<vector<int>> &adj, int s, int d, vector<int> &visited)
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (visited[adj[temp][i]] == false)
            {
                visited[adj[temp][i]] = true;
                q.push(adj[temp][i]);
            }
        }
    }
    return;
}

void dfs(vector<vector<int>> &adj, int s, int d, vector<int> &visited)
{
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            dfs(adj, v, d, visited);
    }
}

void solve() {
    
    return;
}

int main () {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
        //cout << (solve()?"YES" : "NO") << endl;

    return 0;
}
