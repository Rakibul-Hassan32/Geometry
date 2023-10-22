#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x1[4],y1[4],x2[4],y2[4];
    ll hl=0,vl=0;
    for(ll i=0;i<4;i++){
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];

        if(x1[i]-x2[i]==0){
            vl++;
        }
        if(y1[i]-y2[i]==0){
            hl++;
        }

    }

    ll count=0;
    for(ll i=0;i<3;i++){
        for(ll j=i+1;j<4;j++){
           if(x1[i]==x2[j] && y1[i]==y2[j]){
            count++;
           } 
           if(x1[i]==x1[j] && y1[i]==y1[j]){
            count++;
           } 
           if(x2[i]==x1[j] && y2[i]==y1[j]){
            count++;
           } 
           if(x2[i]==x2[j] && y2[i]==y2[j]){
            count++;
           } 
        }
    }
    if(vl==2 && hl==2 && count==4){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}