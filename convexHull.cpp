#include <bits/stdc++.h> 
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

ll convexHull(vii points, ll n) 
{ 
	
	ll count=0,count1=0;
	ll l = 0; 
	for (int i = 1; i < n; i++) 
		if (points[i].ff < points[l].ff) 
			l = i; 
 
	ll p = l, q; 
	do
	{ 
		count++; 

		q = (p+1)%n; 
		for (int i = 0; i < n; i++) 
		{ 
		if (ori(points[p].ff,points[p].ss, points[i].ff,points[i].ss, points[q].ff,points[q].ss) == 2) 
			q = i; 
		}  
		p = q; 

	} while (p != l);  

	return count; 
} 
 
int main() 
{ 
	ll n;
    cin>>n;
    vii points;
    for(ll i=0;i<n;i++){
        ll x,y; cin>>x>>y;
        points.pb(make_pair(x,y));
    }
	ll ans = convexHull(points, n); 
	cout<<ans<<endl;
	return 0; 
} 
