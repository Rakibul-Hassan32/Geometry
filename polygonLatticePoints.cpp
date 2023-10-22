#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>

ll latticePointsOnSegmentExcludingEndPoints(ii p1,ii p2){
    ll a=abs(p1.ff-p2.ff);
    ll b=abs(p1.ss-p2.ss);
    return gcd(a,b) - 1;
}

ll areaOfPolygon(vii v){
    ll ans = 0;
    ll n=v.size();
    for(ll i=0;i<n;i++){
        ll x1 = v[i].first,y1=v[i].second;
        ll x2 = v[(i+1)%n].first,y2=v[(i+1)%n].second;
        ans+=((x1*y2)-(y1*x2));
    }

    return abs(ans);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vii vertices;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        vertices.pb(make_pair(x,y));
    }

    ll boundary=0;
    for(ll i=0;i<n;i++){
        ii p1=vertices[i]; ii p2=vertices[(i+1)%n];
        boundary+=latticePointsOnSegmentExcludingEndPoints(p1,p2);
    }

    boundary += n;

    ll area = areaOfPolygon(vertices)/2;

    cout<<(area+1-(boundary/2))<<" "<<boundary<<endl;
    
    return 0;
}