#include<bits/stdc++.h>
using namespace std;
int main(){
    
        long x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        long val = (x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
        if(val<0) cout<<"anti clock wise"<<endl;
        else if(val>0) cout<<"clock wise"<<endl;
        else cout<<"co-linear"<<endl;
    
    return 0;
}
