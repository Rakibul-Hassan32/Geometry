#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>

ll solve(vii positions,ll n){
      ll lx=-1;
      ll ly=-1;

      ll oldDir=-1;
      ll dTurn=0;

      for(ll i=0;i<=n;i++){
        ll x = positions[i].ff;
        ll y = positions[i].ss;

        if(i==0){
            lx=x;
            ly=y;
            continue;
        }
        if(i==1){
            oldDir=0;
            lx=x;
            ly=y;
            continue;
        }
        ll nDir=-1;
        if(lx==x){
            if(y>ly){
                nDir=0;
            }else{
               nDir=2; 
            }
        }else if(ly==y){
            if(x>lx){
                nDir=1;
            }else{
                nDir=3;
            }
        }

        if((nDir+1)%4==oldDir){
            dTurn++;
        }

        oldDir=nDir;
        lx = x;
        ly = y;
      }
      return dTurn;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vii positions;
    for(ll i=0;i<=n;i++){
        ll x,y; cin>>x>>y;
        positions.pb(make_pair(x,y));
    }

   ll ans = solve(positions,n);
   cout<<ans<<endl;
    return 0;
}