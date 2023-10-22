#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vii vector<ii>
int main() {
    ll n, x1, x2;
    cin >> n >> x1 >> x2;
    
    vii yy(n);
    for (ll i = 0; i < n; ++i) {
        ll k, b;
        cin >> k >> b;
        yy[i].ff = k * x1 + b;
        yy[i].ss = k * x2 + b;
    }

    sort(yy.begin(), yy.end());

    bool ok = false;
    ll flag = 0;
    for (ll i = 1; i < n; ++i) {
        if (yy[flag].ff < yy[i].ff && yy[flag].ss > yy[i].ss) {
            ok = true;
            break;
        }
        if (yy[i].ss < yy[flag].ss) {
            flag = i;
        }
    }
    
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
