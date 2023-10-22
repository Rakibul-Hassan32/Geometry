#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>

ll ori(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    ll val = (x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
        if(val<0) return 2;
        else if(val>0) return 1;
        else return 0;
}

bool onSeg(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return (x3<=max(x1,x2) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3>=min(y1,y2));
}

bool intersect(ii a,ii b,ii c,ii d){
    ll x1=a.ff,y1=a.ss,x2=b.ff,y2=b.ss,x3=c.ff,y3=c.ss,x4=d.ff,y4=d.ss;
    ll o1 = ori(x1,y1,x2,y2,x3,y3);
        ll o2 = ori(x1,y1,x2,y2,x4,y4);
        ll o3 = ori(x3,y3,x4,y4,x1,y1);
        ll o4 = ori(x3,y3,x4,y4,x2,y2);

        if(o1!=o2 && o3!=o4) return true;
        else return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vii vertices;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        vertices.pb(make_pair(x,y));
    }
    vii points;
    for(ll i=0;i<m;i++){
        ll x,y; cin>>x>>y;
        points.pb(make_pair(x,y));
    }

    for(ii cp: points){
        set<ii> donePoints;
        ii endp = {(ll)INT_MAX,(ll)INT16_MAX+1};
        ll intersectCount = 0;
        bool boundary = false;
        for(ll i=0;i<n;i++){
            ii a = vertices[i];
            ii b = vertices[(i+1)%n];
            if(ori(a.ff,a.ss,b.ff,b.ss,cp.ff,cp.ss)==0 && onSeg(a.ff,a.ss,b.ff,b.ss,cp.ff,cp.ss)){
                boundary=true;
                break;
            }
            if(intersect(a,b,cp,endp)){
                intersectCount++;
            }

        }

        if(boundary) cout<<"BOUNDARY"<<endl;
        else if(intersectCount % 2) cout<<"INSIDE"<<endl;
        else cout<<"OUTSIDE"<<endl;
    }
    return 0;
}