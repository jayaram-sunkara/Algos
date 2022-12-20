#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Somewhat similar to last Occurance problem
*/

int squareRoot(int low, int high, int x)
{
    if (x == 1)
        return 1;
    int ans = -1;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << squareRoot(0, n/2, n);
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
