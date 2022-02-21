#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    ll ans=0,z=0,x=0;
    while(n--){
        ll a,b;cin>>a>>b;
        ans+=z*b+x*a;z+=a;x+=b;
    }cout<<ans;
    return 0;
}