#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    int answer = 0; map<int,int> mp;
    if(a.size() > 2){
        for(int i=0 ; i<a.size()-2 ; i++)
            if(a[i] == a[i+1] && a[i+1] == a[i+2]){
                a.erase(a.begin() + i, a.begin() + i + 1);
                i--;
            }
    }
    for(int i=0 ; i<a.size() ; i++) mp[a[i]]++;
    vector<pair<int,int>> v;
    for(auto iter = mp.begin() ; iter != mp.end() ; iter++)
        v.push_back({iter->second, iter->first});
    sort(v.begin(),v.end(),[](const pair<int,int> &v1, const pair<int,int> &v2){
        return v1.first > v2.first;});    
    int num, l, r;
    for(int j=0 ; j<v.size() ; j++){
        num = v[j].second;
        if(j && v[j-1].first != v[j].first) break;
        int tmp = 0;
        for(int i=0 ; i<a.size() ; i++) if(a[i] == num){l = i; break;}
        for(int i=a.size()-1 ; i>=0 ; i--) if(a[i] == num){r = i; break;}

        for(int i=0 ; i<l ; i++) if(a[i] != num) {tmp += 2; l++; break;}
        for(int i=r ; i<a.size() ; i++) if(a[i] != num) {tmp += 2; r--; break;}

        for(int i=l ; i<r ; i++)
            if(a[i] == num || a[i+1] == num)
                if(a[i] != a[i+1]) {tmp += 2; i++;}
        answer = max(answer, tmp);
    }
    return answer;
}
