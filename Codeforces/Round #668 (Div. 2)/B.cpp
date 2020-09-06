#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
vector<ll> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ll ans=0;
        cin >> n;
        v.resize(n);
        for(int i=0 ; i<n ; i++)cin >> v[i];
        int l=n-1,r=n-1;
        while(l<=r){
            if(l==-1)break;
            if(l==r){
                if(v[l]>=0){l--;r--;}
                else{l--;}
            }else{
                if(v[l]>0){
                    if(v[l]+v[r]>=0){v[l]+=v[r];v[r]=0;r--;}
                    else{v[r]+=v[l];v[l]=0;l--;}
                }
                else{l--;}
            }
        }
        for(int i=0;i<n;i++) if(v[i]>0)ans+=v[i];
        cout << ans << "\n";
    }
    return 0;
}
