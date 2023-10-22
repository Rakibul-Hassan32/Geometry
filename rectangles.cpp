#include<bits/stdc++.h>
using namespace std;
#define Rect pair<pair<int, int>, pair<int, int>>
#define ff first
#define ss second
#define vr vector<Rect>

Rect merge(const Rect& a, const Rect& b) {
    return {{max(a.ff.ff, b.ff.ff), max(a.ff.ss, b.ff.ss)},
            {min(a.ss.ff, b.ss.ff), min(a.ss.ss, b.ss.ss)}};
}

bool check(const Rect& ans) {
    return ans.ff.ff <= ans.ss.ff && ans.ff.ss <= ans.ss.ss;
}

int main() {
    int n;
    cin >> n;

    vr recs(n);
    for (int i = 0; i < n; ++i) {
        cin >> recs[i].first.first >> recs[i].first.second >> recs[i].second.first >> recs[i].second.second;
    }

    vr prefix(n);
    prefix[0] = recs[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = merge(prefix[i - 1], recs[i]);
    }

    vr suffix(n);
    suffix[n - 1] = recs[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = merge(suffix[i + 1], recs[i]);
    }

    for (int i = 0; i < n; ++i) {
        Rect ans;
        if (i == 0) {
            ans = suffix[i + 1];
        } else if (i == n - 1) {
            ans = prefix[i - 1];
        } else {
            ans = merge(prefix[i - 1], suffix[i + 1]);
        }

        if (check(ans)) {
            cout << ans.ff.ff << " " << ans.ff.ss << endl;
            break;
        }
    }

    return 0;
}
