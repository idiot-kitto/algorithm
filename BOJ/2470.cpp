#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;v.resize(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];
    sort(v.begin(),v.end());
    
    int l=0, r=n-1, al=v[l], ar=v[r];
    int sum=v[l]+v[r];
    
    while(l+1!=r){
        if(sum==0){al=v[l];ar=v[r];break;}
        if(v[l]+v[r]<0) l++;
        else r--;
        if(abs(v[l]+v[r])<abs(sum)){al=v[l];ar=v[r];sum=v[l]+v[r];}
    }
    cout<<al<<" "<<ar;
    return 0;
}
