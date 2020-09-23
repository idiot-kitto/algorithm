#include <bits/stdc++.h>
using namespace std;
int n, mp, mf ,ms ,mv, ans=INT_MAX;
vector<int> p, f, s, v, c, idx, ans_i, tans_i;
int main()
{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> mp >> mf >> ms >> mv;
    p.resize(n);f.resize(n);s.resize(n);v.resize(n);c.resize(n);
    for(int i=0 ; i<n ; i++) cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];

    for(int i=1 ; i<=n ; i++){
        idx.clear();
        for(int j=0 ; j<i ; j++) idx.push_back(1);
        for(int j=0 ; j<n-i ; j++) idx.push_back(0);
        sort(idx.begin(),idx.end());
        do{int tp = 0, tf = 0, ts = 0, tv = 0, tc = 0;
           for(int j=0 ; j<n ; j++){
                if(idx[j]){
                    tp+=p[j]; tf+=f[j]; ts+=s[j]; tv+=v[j]; tc+=c[j];
                }
           }
           if(tp>=mp && tf>=mf && ts>=ms && tv>=mv){
                if(ans > tc) {
                    ans = tc; ans_i.clear();
                    for(int j=0 ; j<n ; j++)
                        if(idx[j]) ans_i.push_back(j);
                }
                else if(ans == tc){
                    tans_i.clear();
                    for(int j=0 ; j<n ; j++)
                        if(idx[j]) tans_i.push_back(j);
                    for(int j=0 ; min(ans_i.size(),tans_i.size()) ; j++){
                        if(tans_i[j] > ans_i[j]) break;
                        else if(tans_i[j] == ans_i[j]) continue;
                        else if(tans_i[j] < ans_i[j]){
                            ans_i = tans_i;
                        }
                    }
                }
           }
        }while(next_permutation(idx.begin(),idx.end()));
    }
    if(ans == INT_MAX) cout << -1;
    else{
        cout << ans << "\n";
        for(auto k : ans_i) cout << k+1 << " ";
    }
    return 0;
}
