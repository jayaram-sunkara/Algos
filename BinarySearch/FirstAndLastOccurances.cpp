#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
The first Occurance is found by updating high to (mid - 1)
even after we found the element as mid and mid - 1
still have the same value.
*/
int firstOcc(vector<int> &v, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] > x)
            high = mid - 1;
        else if (v[mid] < x)
            low = mid + 1;
        else
        {
            if (mid == 0 || v[mid] != v[mid - 1])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

/*
The last Occurance is found by updating low to (mid + 1)
even after we found the element as mid and mid + 1
still have the same value.
*/
int lastOcc(vector<int> &v, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] > x)
            high = mid - 1;
        else if (v[mid] < x)
            low = mid + 1;
        else
        {
            if (mid == v.size() - 1 || v[mid] != v[mid + 1])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &v, int x)
{
    int first = firstOcc(v, 0, v.size() - 1, x), last = lastOcc(v, 0, v.size() - 1, x);

    if (first != -1)
        return {first, last};
    return {-1, -1};
}

void solve()
{
    /*
    Number of elements = n
    Element to be found = x
    Vector name = v
    */
    int n, x;
    cin >> n >> x;
    vector<int> v(n), res;
    for (auto &it : v)
        cin >> it;

    res = searchRange(v, x);

    for (int &it : res)
        cout << it << " ";

    return;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << (solve()?"YES" : "NO") << endl;

    return 0;
}
