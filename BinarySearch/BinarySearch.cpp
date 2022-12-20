#include <bits/stdc++.h>
using namespace std;
#define ll long long

int IterativeBinarySearch(vector<int> &v, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
            return mid;
        else if (v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int RecursiveBinarySearch(vector<int> &v, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (v[mid] == x)
        return mid;
    else if (v[mid] > x)
        return RecursiveBinarySearch(v, 0, mid - 1, x);
    else
        return RecursiveBinarySearch(v, mid + 1, high, x);
}

void solve() {
    /*
    Number to be found = x
    Number of elements in vector = n
    Name of vector = v
    */
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(auto &it: v) cin >> it;
    sort(v.begin(), v.end());

    IterativeBinarySearch(v, 0, n-1, x);
    RecursiveBinarySearch(v, 0, n-1, x);

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
