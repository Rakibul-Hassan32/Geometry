#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<ll,ll>> v;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll x1 = v[i].first,y1=v[i].second;
        ll x2 = v[(i+1)%n].first,y2=v[(i+1)%n].second;
        ans+=((x1*y2)-(y1*x2));
    }

    cout<<abs(ans)<<endl;

    return 0;
}