#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    ll re=pow((a2+a3+a4),2)-(pow(a2,2)+pow(a4,2)+pow(a6,2));
    cout<<re<<endl;
    return 0;
}